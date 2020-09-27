group "Dependencies"
include "../../engine/dependencies/glfw/premake"

group ""

project "Engine"
	location "%{wks.location}/engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	
	targetdir ("%{prj.location}/bin/%{outputDir}")
	objdir ("%{prj.location}/bin-int/%{outputDir}")
	
	pchheader "engine_precompiled/engine_precompiled.hpp"
	pchsource "../../engine/source/engine_precompiled/engine_precompiled.cpp"
	
	files {
		"%{prj.location}/source/**.cpp",
		"%{prj.location}/source/**.hpp"
	}
	
	includedirs {
		"%{prj.location}/source",
		"%{prj.location}/dependencies/glfw/include"
	}
	
	links {
		"GLFW",
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"ENGINE_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Development"
		defines "ENGINE_CONFIGURATION_DEVELOPMENT"
		symbols "On"
		runtime "Debug"
	
	filter "configurations:Testing"
		defines "ENGINE_CONFIGURATION_TESTING"
		optimize "On"
		runtime "Release"
	
	filter "configurations:Production"
		defines "ENGINE_CONFIGURATION_PRODUCTION"
		optimize "On"
		runtime "Release"
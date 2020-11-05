group "Dependencies"
include "../../engine/dependencies/glfw/premake"
include "../../engine/dependencies/glad/premake"
include "../../engine/dependencies/stb/stb/premake"

group ""

project "Engine"
	location "%{wks.location}/engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir "%{binDir}"
	objdir "%{binIntDir}"
	
	pchheader "engine_precompiled/engine_precompiled.hpp"
	pchsource "../../engine/source/engine_precompiled/engine_precompiled.cpp"
	
	files {
		"%{prj.location}/source/**.cpp",
		"%{prj.location}/source/**.hpp",
		"%{prj.location}/dependencies/glm/glm/**.hpp",
		"%{prj.location}/dependencies/stb/stb/stb_image.h"
	}
	
	includedirs {
		"%{prj.location}/source",
		"%{prj.location}/dependencies/glfw/include",
		"%{prj.location}/dependencies/glad/include",
		"%{prj.location}/dependencies/glm",
		"%{prj.location}/dependencies/stb"
	}
	
	links {
		"GLFW",
		"Glad",
		"stb",
		"opengl32.lib",
	}
	
	defines {
		"GLFW_INCLUDE_NONE"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"ENGINE_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Development"
		defines "ENGINE_CONFIGURATION_DEVELOPMENT"
		symbols "on"
		runtime "Debug"
	
	filter "configurations:Testing"
		defines "ENGINE_CONFIGURATION_TESTING"
		optimize "on"
		runtime "Release"
	
	filter "configurations:Production"
		defines "ENGINE_CONFIGURATION_PRODUCTION"
		optimize "on"
		runtime "Release"
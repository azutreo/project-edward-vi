project "Sandbox"
	location "%{wks.location}/sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	
	targetdir ("%{prj.location}/bin/%{outputDir}")
	objdir ("%{prj.location}/bin-int/%{outputDir}")
	
	pchheader "precompiled/precompiled.hpp"
	pchsource "../../sandbox/source/precompiled/precompiled.cpp"
	
	files {
		"%{prj.location}/source/**.cpp",
		"%{prj.location}/source/**.hpp"
	}
	
	includedirs {
		"%{prj.location}/source",
		"%{wks.location}/engine/source",
		"%{prj.location}/dependencies/glfw/include",
		"%{prj.location}/dependencies/glad/include"
	}
	
	links {
		"Engine",
		"GLFW",
		"Glad",
		"opengl32.lib",
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"PLATFORM_WINDOWS"
		}
	
	filter "configurations:Development"
		defines "CONFIGURATION_DEVELOPMENT"
		symbols "On"
		runtime "Debug"
	
	filter "configurations:Testing"
		defines "CONFIGURATION_TESTING"
		optimize "On"
		runtime "Release"
	
	filter "configurations:Production"
		defines "CONFIGURATION_PRODUCTION"
		optimize "On"
		runtime "Release"
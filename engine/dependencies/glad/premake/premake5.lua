project "Glad"
	location "%{wks.location}/engine/dependencies/glad"
	kind "StaticLib"
	language "C"
	
	targetdir ("%{prj.location}/bin/%{outputDir}")
	objdir ("%{prj.location}/bin-int/%{outputDir}")
	
	files {
		"%{prj.location}/include/glad/glad.h",
		"%{prj.location}/include/khr/khrplatform.h",
		"%{prj.location}/src/glad.c"
	}
	
	includedirs {
		"%{prj.location}/include"
	}
	
	filter "configurations:Development"
		symbols "On"
		runtime "Debug"
	
	filter "configurations:Testing"
		optimize "On"
		runtime "Release"
	
	filter "configurations:Production"
		optimize "On"
		runtime "Release"

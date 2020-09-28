project "Glad"
	location "%{wks.location}/engine/dependencies/glad"
	kind "StaticLib"
	language "C"
	
	targetdir "%{binDir}"
	objdir "%{binIntDir}"
	
	files {
		"%{prj.location}/include/glad/glad.h",
		"%{prj.location}/include/khr/khrplatform.h",
		"%{prj.location}/src/glad.c"
	}
	
	includedirs {
		"%{prj.location}/include"
	}
	
	filter "configurations:Development"
		symbols "on"
		runtime "Debug"
	
	filter "configurations:Testing"
		optimize "on"
		runtime "Release"
	
	filter "configurations:Production"
		optimize "on"
		runtime "Release"

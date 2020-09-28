binDir = "%{wks.location}/bin/%{prj.name}-%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
binIntDir = "%{wks.location}/bin-int/%{prj.name}-%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "Project Edward VI"
	location "../.."
	architecture "x86_64"
	startproject "Sandbox"

	configurations {
		"Development",
		"Testing",
		"Production"
	}

	flags {
		"MultiProcessorCompile"
	}

group "Build"
project "Premake"
	location "%{wks.location}/build/premake"
	kind "Utility"
	
	targetdir "%{binDir}"
	objdir "%{binIntDir}"

	files {
		"%{wks.location}/**premake5.lua"
	}

	postbuildmessage "Regenerating project files with Premake5!"
	postbuildcommands {
		"%{prj.location}/premake5 %{_ACTION} --file=\"%{prj.location}premake5.lua\""
	}

group ""
include "../../engine/premake"
include "../../sandbox/premake"
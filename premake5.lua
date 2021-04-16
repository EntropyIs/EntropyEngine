workspace "EntropyEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputDir = "%{cfg.architecture}/%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "middleware/GLFW/include"
IncludeDir["GLAD"] = "middleware/GLAD/include"

include "middleware/GLFW"
include "middleware/GLAD"

project "EntropyLib"
	location "src/EntropyLib"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("obj/" .. outputDir .. "/%{prj.name}")

	pchheader "ecpch.h"
	pchsource "src/EntropyLib/ecpch.cpp"

	files
	{
		"src/%{prj.name}/**.h",
		"src/%{prj.name}/**.cpp",
	}

	includedirs
	{
		"src/EntropyLib",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}"
	}
		
	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ENTROPY_PLATFORM_WINDOWS",
			"ENTROPY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../../bin/" .. outputDir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ENTROPY_DEBUG"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "ENTROPY_RELEASE"
			buildoptions "/MD"
			symbols "On"

		filter "configurations:Dist"
			defines "ENTROPY_DIST"
			buildoptions "/MD"
			symbols "On"

project "Sandbox"
	location "src/Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("obj/" .. outputDir .. "/%{prj.name}")

	files
	{
		"src/%{prj.name}/**.h",
		"src/%{prj.name}/**.cpp",
	}

	includedirs
	{
		"src/EntropyLib",
	}

	links
	{
		"EntropyLib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ENTROPY_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ENTROPY_DEBUG"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "ENTROPY_RELEASE"
			buildoptions "/MD"
			symbols "On"

		filter "configurations:Dist"
			defines "ENTROPY_DIST"
			buildoptions "/MD"
			symbols "On"
workspace "EntropyEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputDir = "%{cfg.architecture}\%{cfg.buildcfg}-%{cfg.system}"

project "EntropyCore"
	location "EntropyCore"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("obj/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ENTROPY_PLATFORM_WINDOWS",
			"ENTROPY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ENTROPY_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ENTROPY_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "ENTROPY_DIST"
			symbols "On"

project "EntropyGraphics"
	location "EntropyGraphics"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ENTROPY_PLATFORM_WINDOWS",
			"ENTROPY_BUILD_DLL"
		}

		includedirs
		{
			"EntropyCore",
			"Middleware/GLEW/include",
			"Middleware/GLFW/include"
		}
		
		libdirs
		{
			"Middleware/GLEW/lib",
			"Middleware/GLFW/lib"
		}

		links
		{
			"EntropyCore",
			"glfw3.lib",
			"glew32.lib",
			"opengl32.lib"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ENTROPY_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ENTROPY_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "ENTROPY_DIST"
			symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ENTROPY_PLATFORM_WINDOWS"
		}

		includedirs
		{
			"EntropyCore",
			"EntropyGraphics",
			"Middleware/GLEW/include",
			"Middleware/GLFW/include"
		}
		
		libdirs
		{
			"Middleware/GLEW/lib",
			"Middleware/GLFW/lib"
		}

		links
		{
			"EntropyCore",
			"EntropyGraphics",
			"glfw3.lib",
			"glew32.lib",
			"opengl32.lib"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ENTROPY_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ENTROPY_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "ENTROPY_DIST"
			symbols "On"
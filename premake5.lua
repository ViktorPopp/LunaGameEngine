workspace "LunaGameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LunaEngine"
	location "LunaEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermidate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LUNA_PLATFORM_WINDOWS",
			"LUNA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LUNA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LUNA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LUNA_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermidate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.c",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp"
	}

	includedirs
	{
		"LunaEngine/vendor/spdlog/include",
		"LunaEngine/src"
	}

	links
	{
		"LunaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LUNA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LUNA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LUNA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LUNA_DIST"
		optimize "On"
workspace "Hazel"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Hazel"
    kind "SharedLib"
    language "C++"
    targetdir("bin/"..outputdir.."/%{prj.name}")--必须得括号包裹 因为有多个字符串拼接操作
    objdir("bin-int/"..outputdir.."/%{prj.name}")
    pchheader "hzpch.h"
    pchsource "Hazel/src/Hazel/hzpch.cpp"
	
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
		"%{prj.name}/src",
        "%{prj.name}/Vendors/spdlog/include"
    }
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL"
        }
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"

project "Sandbox"
    kind "consoleApp"
    language "C++"
    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
        "Hazel/Vendors/spdlog/include",
        "Hazel/src"
    }
    links
    {
        "Hazel"
    }
    filter "system:windows"
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"
        defines
        {
            "HZ_PLATFORM_WINDOWS",
        }
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"

workspace "Stopwatch"
    -- We indicate that all the projects are C++ only
    language "C++"
    cppdialect "C++11"

    -- We will compile for x86_64. You can change this to x86 for 32 bit builds.
    architecture "x86_64"

    -- Configurations are often used to store some compiler / linker settings together.
    -- The Debug configuration will be used by us while debugging.
    -- The optimized Release configuration will be used when shipping the app.
    configurations { "Debug", "Release" }

    -- We now only set settings for the Debug configuration
    filter { "configurations:Debug" }
        defines { "DEBUG", "_CRT_SECURE_NO_WARNINGS", "_CRT_NONSTDC_NO_DEPRECATE" }
        runtime "Debug"
        symbols "On"
    
    -- We now only set settings for Release
    filter { "configurations:Release" }
        defines { "NDEBUG", "_CRT_SECURE_NO_WARNINGS", "_CRT_NONSTDC_NO_DEPRECATE" }
        runtime "Release"
        optimize "On"
    
    -- Reset the filter for other settings
	filter { }
    
    -- Here we use some "tokens" (the things between %{ ... }). They will be replaced by Premake automatically when configuring the projects.
    -- * %{prj.name} will be replaced by "ExampleLib" / "App" / "UnitTests"
    -- * %{cfg.longname} will be replaced by "Debug" or "Release" depending on the configuration
    -- The path is relative to *this* folder
    targetdir ("%{prj.name}/Binaries/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")
    objdir ("%{prj.name}/Intermediate/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")


project "Stopwatch"
    location "Stopwatch"
    kind "ConsoleApp"

    files {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.hpp",
        "%{prj.name}/Source/**.c",
        "%{prj.name}/Source/**.cpp",
    }

-- A solution contains projects, and defines the available configurations
solution "CyrusUI"
   configurations { "Debug", "Release" }
 
   configuration "Debug"
      defines { "DEBUG" }
      flags { "Symbols"}
      targetdir "bin/debug"
 
    configuration "Release"
      defines { "NDEBUG" }
      flags { "Optimize" }
      targetdir "bin/release"

   -- CyrusUI
   project "cyrusui"
      kind "SharedLib"
      language "C++"
      files { "Source/**.cpp", "Libs/stb_image.c" }
      excludes {"Source/sn/fmod/*.cpp", "Source/sn/bass/*.cpp", "Source/av/**.cpp"}
      includedirs { "Libs/SDL/include" }
      buildoptions { "-fpermissive" }
        links { "SDL2", "IL", "ILU"}
        libdirs { ".", "LIBDIR" }


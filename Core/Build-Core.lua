project "Core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp", "Source/**.hpp" }

   includedirs
   {
      "Source",
      "../Vendor/Binaries/SFML-2.6.1/include"
   }

   libdirs
   {
        "../Vendor/Binaries/SFML-2.6.1/lib"
   }

   links
   {
      "winmm.lib",
      "ws2_32.lib",
      "openal32.lib",
      "flac.lib",
      "vorbisenc.lib",
      "vorbisfile.lib",
      "vorbis.lib",
      "ogg.lib",
      "gdi32.lib",
      "opengl32.lib",
      "freetype.lib"
   }

   defines
   {
    "SFML_STATIC"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       links 
       { 
        "sfml-system-s-d.lib",
        "sfml-network-s-d.lib",
        "sfml-audio-s-d.lib",
        "sfml-window-s-d.lib",
        "sfml-graphics-s-d.lib"
       }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       links 
       { 
        "sfml-system-s.lib",
        "sfml-network-s.lib",
        "sfml-audio-s.lib",
        "sfml-window-s.lib",
        "sfml-graphics-s.lib"
       }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       links 
       { 
        "sfml-system-s.lib",
        "sfml-network-s.lib",
        "sfml-audio-s.lib",
        "sfml-window-s.lib",
        "sfml-graphics-s.lib"
       }
       runtime "Release"
       optimize "On"
       symbols "Off"
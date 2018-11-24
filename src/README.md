TODO
 - Remake of Arcana for the SNES, at least the Scenaric part of the Intro


HOW TO COMPILE
- Install SDL
  - sudo dnf install SDL2
  - sudo dnf install SDL2-devel
- install SDL_image
  - sudo dnf install SDL2_image
  - sudo dnf install SDL2_image-devel
- install SDL_mixer
  - sudo dnf install SDL2_mixer
  - sudo dnf install SDL2_mixer-devel

- install NetBeans 8.2 & C/C++ plugins & libs
  - install NetBeans 8.2
  - install C/C++ plugin
  - sudo dnf install gcc-c++
  - sudo dnf install glut-devel
  - sudo dnf install automake
  - sudo yum groupinstall "X Software Development"
  
  - Under File.ProjectProperties(Arcana).C++Compiler.CompilationLine.Additionnal options; Add the following:
    `sdl2-config --cflags` -fexceptions
    
  - Under File.ProjectProperties(Arcana).C++Compiler.General.PreProcessorDefinition; add the following :
    _DEBUG _LINUX (for debug build target)
    NDEBUG _LINUX (for release build target)

  - Under File.ProjectProperties(Arcana).C++Compiler.General.IncludeDirectories; add the following :
    src;../../Libs/dakiilib/src/dfc;../../Libs/dakiilib/src/helper;../../Libs/dakiilib/src/lib

  - Under File.ProjectProperties(Arcana).Linker.General.AdditionalLibraryDirectories
    ../../Libs/dakiilib/dist/Debug/GNU-Linux;/usr/lib64

  - - Under File.ProjectProperties(Arcana).Linker.Libraries.Libraries
    dakiilib
    /usr/lib64/libSDL2_image.so
    /usr/lib64/libSDL2_mixer.so

  - - Under File.ProjectProperties(Arcana).Linker.CompilationLine.AdditionalOptions
    `sdl2-config --libs`    


TODO
- fix crash bugs in gradual labels

# RayGUI
Nowadays there are big troubles to just create GUI on C++, cause you often need to choose between crossplatform, lightweight development environment and easier build (quite everybody could easy write UI on Qt with "Creator" or on ImGUI with "Visual Studio"), but for me it is hell. Why I need to chose?
That's why I present to you my GUI Framework RayGUI.

RayGUI is:
- **crossplatform** - 'cause it uses Raylib to render and cmake as build-platform
- able to be used in **lightweight environment** 'cause it all compiles into library file and have all includes in one file
- **easy to build** - 'cause now project provides cmake file (maybe it'll has expantion to other build systems)

# Installation
To use RayGUI in your project, do following steps:
- download repository archive
- unpack it to your project folder

## Build
There are two ways how you can do it:
### Include to CMake project
just add 
```cmake
add_subdirectory(path/to/RayGUI-src)
target_link_libraries(target RayGUI)
target_include_directories(target PUBLIC build_path/RayGUI/include)
```
to your CMake file

## Use binaries
(I promise, someday I will compile binaries for win_x64 and debian_x64, but now you need to build them yourself)

To use binaries you need to:
- link libRayGUI built for your system 
- to use interfaces add RayGUI/include to include directories
- and finally add #include <RayGUI.h> line to your code
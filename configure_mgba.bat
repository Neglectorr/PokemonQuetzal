@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
cd /d "C:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_src\build"
"C:\PassionProjects\GBAEmu\PokemonQuetzal\vcpkg\downloads\tools\cmake-3.31.10-windows\cmake-3.31.10-windows-x86_64\bin\cmake.exe" .. -DCMAKE_TOOLCHAIN_FILE=C:\PassionProjects\GBAEmu\PokemonQuetzal\vcpkg\scripts\buildsystems\vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -G "Ninja" -DCMAKE_MAKE_PROGRAM="C:\PassionProjects\GBAEmu\PokemonQuetzal\vcpkg\downloads\tools\ninja-1.13.2-windows\ninja.exe"

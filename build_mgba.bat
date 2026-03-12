@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
echo Testing cl.exe...
echo #include ^<stdio.h^> > test_env.c
echo int main() { printf("Hello\n"); return 0; } >> test_env.c
cl test_env.c /nologo
if %ERRORLEVEL% NEQ 0 (
    echo cl.exe FAILED to find stdio.h in active environment!
    set INCLUDE
) else (
    echo cl.exe PASSED test.
)
cd /d "C:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_src\build"
"C:\PassionProjects\GBAEmu\PokemonQuetzal\vcpkg\downloads\tools\ninja-1.13.2-windows\ninja.exe"

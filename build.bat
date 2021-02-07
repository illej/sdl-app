@echo off

if not exist external goto dl

set include_dir=external\include
set lib_dir=external\lib\x64

:: Shell32.lib is required for the magic main redefinition SDL does
:: on windows, along with specifying a subsystem.
set libs=Shell32.lib SDL2.lib SDL2main.lib

set compiler_flags=-nologo -I %include_dir%
set linker_flags=-link -subsystem:console -libpath:%lib_dir% %libs%

set src=app.c

echo compiling app.c
cl %compiler_flags% %src% %linker_flags%

goto end

:dl
    :: TODO: supress all the logs
    :: TODO: add enet
    set VERSION=2.0.12

    echo downloading sdl-%VERSION%
    mkdir external

    curl https://www.libsdl.org/release/SDL2-devel-%VERSION%-VC.zip -o sdl2.zip
    tar -xvf sdl2.zip

    :: TODO also copy SDL2.dll next to the .exe
    robocopy SDL2-%VERSION% external /E /NJH /V /XD docs
    rmdir /Q /S SDL2-%VERSION%
    del sdl2.zip

    echo download finished
    :: TODO is this the correct way to exit a function?
    goto eof

:end
    echo done
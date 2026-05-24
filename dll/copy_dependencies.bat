@echo off
Rem Copies ImGui into project and Runner headers
Rem Ensure that "runtime" below is downloaded or adjusted

set imgui=thirdparty\imgui
copy "%imgui%\im*.cpp"
rename "imconfig.h" "_imconfig.h"
copy "%imgui%\im*.h"
del "imconfig.h"
rename "_imconfig.h" "imconfig.h"
copy "%imgui%\misc\cpp\imgui_stdlib.*"
copy "%imgui%\backends\imgui_impl_dx11.*"

set program=GameMakerStudio2-Beta
set runtime=runtime-2024.1400.5.1031
set base=%PROGRAMDATA%\%program%\Cache\runtimes\%runtime%\yyc\include

copy "%base%\extension\YYRunnerInterface.h" "Extension_Interface.h"
copy "%base%\YYStd.h"
copy "%base%\Ref.h"

echo #include "Ref.h" >> YYRValue.h
type %base%\YYRValue.h >> YYRValue.h
echo Copied and modified YYRValue.h
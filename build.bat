@echo off
setlocal
rem ============================================
rem  One-click C/C++ build (MSVC toolchain)
rem  Usage : build.bat source.cpp
rem  Output: build\<name>.exe
rem ============================================

set "VCROOT=D:\Visual Studio\VisuaI Studio 2022\Community\VC\Tools\MSVC"
set "SDKROOT=D:\Windows Kits\10"

rem --- pick newest installed MSVC version ---
for /d %%i in ("%VCROOT%\*") do set "VC=%%i"
rem --- pick newest installed Windows SDK version ---
for /d %%i in ("%SDKROOT%\Include\*") do set "SDKV=%%~nxi"

if "%~1"=="" (
  echo [ERROR] No source file given. Example: build.bat hello.cpp
  exit /b 1
)
if not defined VC (
  echo [ERROR] MSVC not found under %VCROOT%
  exit /b 1
)

set "PATH=%VC%\bin\Hostx64\x64;%PATH%"
set "INCLUDE=%VC%\include;%SDKROOT%\Include\%SDKV%\ucrt;%SDKROOT%\Include\%SDKV%\shared;%SDKROOT%\Include\%SDKV%\um"
set "LIB=%VC%\lib\x64;%SDKROOT%\Lib\%SDKV%\ucrt\x64;%SDKROOT%\Lib\%SDKV%\um\x64"

if not exist "%~dp0build" mkdir "%~dp0build"

echo [BUILD] %~nx1
cl /nologo /utf-8 /EHsc /std:c++17 /Zc:__cplusplus /Zi /W3 /MT ^
   /Fe:"%~dp0build\%~n1.exe" ^
   /Fo:"%~dp0build\%~n1.obj" ^
   "%~f1"

if errorlevel 1 (
  echo [FAILED] Compilation error, see messages above
  exit /b 1
)

echo [OK] Generated build\%~n1.exe
endlocal

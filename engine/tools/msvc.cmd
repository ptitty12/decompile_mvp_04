@echo off
rem Run a command inside the MSVC x64 developer environment, for the "msvc" preset:
rem   engine\tools\msvc.cmd cmake --preset msvc
rem Locates Visual Studio with vswhere, so no install path is hard-coded.
setlocal
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" (
  echo msvc.cmd: vswhere.exe not found 1>&2
  exit /b 1
)
for /f "usebackq tokens=*" %%i in (`call "%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSDIR=%%i"
if not defined VSDIR (
  echo msvc.cmd: no Visual Studio with the C++ x64 tools found 1>&2
  exit /b 1
)
call "%VSDIR%\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1
%*

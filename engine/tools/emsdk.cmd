@echo off
rem Run a command with the Emscripten SDK on PATH, for the "emscripten" preset:
rem   engine\tools\emsdk.cmd cmake --preset emscripten
rem   engine\tools\emsdk.cmd cmake --build --preset emscripten -j 8
rem   engine\tools\emsdk.cmd ctest --preset emscripten
rem The SDK lives in EMSDK, by default %USERPROFILE%\tools-ext\emsdk; the pinned
rem version is in docs/engine/TOOLCHAIN.md ("Browser: Emscripten").
setlocal
if not defined EMSDK set "EMSDK=%USERPROFILE%\tools-ext\emsdk"
if not exist "%EMSDK%\upstream\emscripten\emcc.py" (
  echo emsdk.cmd: no Emscripten SDK at "%EMSDK%" 1>&2
  exit /b 1
)
set "EM_CONFIG=%EMSDK%\.emscripten"
set "EMSDK_PYTHON="
for /d %%d in ("%EMSDK%\python\*") do set "EMSDK_PYTHON=%%d\python.exe"
for /d %%d in ("%EMSDK%\node\*") do set "EMSDK_NODE=%%d\node.exe"
for /d %%d in ("%EMSDK%\node\*") do set "PATH=%%d;%PATH%"
set "PATH=%EMSDK%;%EMSDK%\upstream\emscripten;%PATH%"
%*

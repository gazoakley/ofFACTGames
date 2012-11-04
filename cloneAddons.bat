@echo off
set _=%CD%

cd %~dp0\..\..\..\addons
if %errorlevel% neq 0 goto noaddons

git help > NUL 2>&1
if %errorlevel% neq 0 goto nogit

git clone https://github.com/gazoakley/ofxFACTLiverpoolScreen.git
if %errorlevel% equ 128 echo Already have ofxFACTLiverpoolScreen
git clone https://github.com/labatrockwell/ofxLibwebsockets.git
if %errorlevel% equ 128 echo Already have ofxLibwebsockets
goto exit

:noaddons
echo Cannot find addons directory
goto exit

:nogit
echo Cannot find git
goto exit

:exit
cd %_%
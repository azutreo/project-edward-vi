@echo off
pushd %~dp0\premake\
call premake5.exe vs2019
popd
PAUSE
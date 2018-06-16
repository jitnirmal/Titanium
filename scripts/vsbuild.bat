ECHO OFF
ECHO starting program
set BUILD="C:\Users\jitni\Documents\GitHub\"
set REPO="C:\Users\jitni\Documents\GitHub\CodeBase Git"
cd %BUILD%
cmake %REPO%
cmake --build vsbuild --
PAUSE
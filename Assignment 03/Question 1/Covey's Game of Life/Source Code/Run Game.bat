@echo off
cd /d "%~dp0"
if not exist "build\covey_game.exe" (
    echo Executable not found: build\covey_game.exe
    pause
    exit /b 1
)
"build\covey_game.exe" "input.txt"
echo.
pause

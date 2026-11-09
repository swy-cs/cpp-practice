@echo off
setlocal
rem ============================================
rem  Clean build artifacts (keeps source safe)
rem  Usage: clean.bat
rem ============================================
if not exist "%~dp0build" (
  echo [INFO] Nothing to clean.
  exit /b 0
)
for %%f in ("%~dp0build\*") do del /q "%%f" >nul 2>&1
echo [OK] build directory cleaned. Source files untouched.
endlocal

@echo off
:: This script safely disconnects an RDP session while keeping the GUI alive and unlocked for bots/macros.
:: Run this script AS ADMINISTRATOR when you want to leave the server.

echo Disconnecting RDP session and restoring Console...
for /f "skip=1 tokens=3" %%s in ('query user %USERNAME%') do (
  %windir%\System32\tscon.exe %%s /dest:console
)

@echo off
docker build --no-cache -f Docker/Dockerfile --target pcs_2026 . -t pcs_2026:1.0.0
pause


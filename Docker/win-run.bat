@echo off
docker run --rm -it --hostname THIS_IS_PCS_DOCKER -v .\Data:/home/pcsdocker/Data pcs_2026:1.0.0 /bin/bash
pause

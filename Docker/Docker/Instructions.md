# Docker Instructions

**NB**: on some system the command `sudo` shall be used to run docker commands.

## Create the pcs_2025 image

To create a virtual machine named `pcs_2025` using the instructions contained in the file `Dockerfile`

```bash
docker build --no-cache -f Dockerfile --target pcs_2025 . -t pcs_2025:1.0.0
```

## Run pcs_2025 container with bash

We want to run the virtual machine sharing a folder between our machine and the virtual one.
The folder will be called `Data` and it is located at `<path_Data_folder>` in out machine.
Run the following command:

```bash
docker run --rm -it -v <path_Data_folder>:/home/appuser/Data pcs_2025:1.0.0 /bin/bash
```

***EXAMPLE***
In my computer the folder `Data` is located at `/home/pippo/Data`. So I run:

```bash
docker run --rm -it -v /home/pippo/Data:/home/appuser/Data pcs_2025:1.0.0 /bin/bash
```

## Stop running containers

```bash
docker container prune
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
```

## Remove the pcs_2025 image (RESET)

```bash
docker container prune
docker rmi pcs_2025:1.0.0
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker buildx prune -f
```

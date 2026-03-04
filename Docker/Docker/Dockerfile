FROM debian:trixie-slim AS pcs_2026

# Create machine
RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt install -y apt-utils ssh \
    apt-transport-https ca-certificates gnupg wget

RUN apt update

RUN apt install -y build-essential gdb cmake cmake-curses-gui git vim \
    libeigen3-dev clang lldb


RUN useradd --create-home pcsdocker
USER pcsdocker

RUN < /dev/zero ssh-keygen -N ''

WORKDIR /home/pcsdocker/
RUN mkdir Data


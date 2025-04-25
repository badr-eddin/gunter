FROM archlinux

WORKDIR ./

COPY ../common .

RUN pacman -Syy base-devel build-essential

EXPOSE 4444

CMD mkdir build; cd build; cmake ..

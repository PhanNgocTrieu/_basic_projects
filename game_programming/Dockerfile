FROM Ubuntu:latest

RUN apt-get install -y build-essential cmake git
RUN apt-get update -y && apt-get install -y libx11-dev libx11-xcb-dev libfontenc-dev libice-dev libsm-dev libxau-dev libxaw7-dev libxcb-util-dev
RUN apt-get install -y libxkbfile-dev libxmuu-dev libxres-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-dri3-dev libxcb-cursor-dev

COPY . /opt/

RUN [ \
    cd /opt/ \
    mkdir build \
    cd build \
    cmake .. \
    make \
] \
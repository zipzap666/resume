#!/bin/bash

sudo apt-get update
sudo apt-get upgrade
sudo apt install g++
sudo apt install qt5-default
qmake -project
qmake ./cw.pro
make
./cw

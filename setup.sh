#!/bin/bash

# Description: This script manages the setup
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev
make -C ./Debug clean
make -C ./Debug all
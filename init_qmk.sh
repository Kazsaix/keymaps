#!/bin/bash

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
USER_SPACE="$QMK_HOME/users"
HANDWIRED="keyboards/handwired"
BM40="keyboards/kprepublic/bm40hsrgb/keymaps"
MJ64="keyboards/melgeek/mj64/keymaps"
WINGS42R2="keyboards/dailycraft/wings42/rev2/keymaps"

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/qmk/qmk_firmware
fi
echo "Update git sub-modules..."
git submodule sync --recursive
git submodule update --init --recursive --progress

if [[ ! -d "$USER_SPACE/rafaelromao" ]]
then
    echo "Creating userspace symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/users/rafaelromao" "$USER_SPACE"
fi
if [[ ! -d "$QMK_HOME/$HANDWIRED/rafaelromao" ]]
then
    echo "Creating Handwired symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$HANDWIRED/rafaelromao" "$QMK_HOME/$HANDWIRED"
fi
if [[ ! -d "$QMK_HOME/$BM40/rafaelromao" ]]
then
    echo "Creating BM40 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$BM40/rafaelromao" "$QMK_HOME/$BM40"
fi
if [[ ! -d "$QMK_HOME/$MJ64/clopes.le" ]]
then
    echo "Creating MJ64 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$MJ64/clopes.le" "$QMK_HOME/$MJ64"
fi
if [[ ! -d "$QMK_HOME/$WINGS42R2/rafaelromao" ]]
then
    echo "Creating WINGS42R2 symbolic link..."
    ln -s "$KEYBOARD_HOME/src/qmk/$WINGS42R2/rafaelromao" "$QMK_HOME/$WINGS42R2"
fi
echo "Checking out qmk v0.22.10..."
cd $QMK_HOME
git fetch
git checkout 0.22.10
cd ..

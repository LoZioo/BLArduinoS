#!/bin/zsh

mkdir build
cd build

while true; do
	clear && cmake .. && make && echo && ./main

	echo "\nHit a key to continue or ESC to exit..."
	read -skrn 1 key

	if [[ $key == $'\x1b' ]]; then
		echo "ESC pressed, exiting..."
		break
	fi
done

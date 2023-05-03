#!/bin/zsh

while true; do
	clear && g++ main.cpp && ./a.out

	echo "\nHit a key to continue or ESC to exit..."
	read -skrn 1 key

	if [[ $key == $'\x1b' ]]; then
		echo "ESC pressed, exiting..."
		break
	fi
done

#!/bin/bash

#functions
function error() {
	printf "\e[31m\e[1m%s\e[0m\n" "$*" >&2
	exit 1
}

ARCH=$(uname -m)
if [[ "$ARCH" == "armv7l" ]] || [[ "$ARCH" == "armhf" ]] || [[ "$ARCH" == "arm64" ]] || [[ "$ARCH" == "aarch64" ]]; then
	true
else
	error "This isn't a arm device! while 'Pi-Apps terminal - C edition' will compile ok on any common arch, it will only work on devices with pi-apps installed."
fi

#check if pi-apps directory is present
if [[ ! -d "$HOME/pi-apps" ]]; then
	while true; do
		read -p "Pi-Apps appears to not be installed, do you want to install it now [y/n]?" answer
		if [[ "$answer" =~ [yY] ]]; then
			echo "Installing pi-apps..."
			cd $HOME || cd ~ || error "Failed to change directory to your home directory!"
			git clone --depth=1 https://github.com/Botspot/pi-apps || error "Failed to clone pi-apps repo!"
			~/pi-apps/install || error "Failed to run pi-apps install script!"
			if ! command -v pi-apps >/dev/null ; then
				#pi-apps isn't installed
				error "Pi-Apps isn't installed, but should be by now!"
			fi
			break
		elif [[ "$answer" =~ [nN] ]]; then
			error "ERROR: can't continue without installing pi-apps!"
		else
			echo -e "\e[1m\e[31mInvalid answer \"$answer\"! please try again."
		fi
	done
else
	if ! command -v pi-apps >/dev/null ; then
		#pi-apps isn't installed
		error "Pi-Apps isn't installed, can't continue!"
	else
		echo -e "\e[1mPi-Apps appears to be installed, if it isn't this program will malfunction!\e[0m"
		sleep 2
	fi
fi
echo -e "\e[32m\e[1mEVERYTHING IS OK:\e[0m now simply run '\e[1mmkdir build; cd build; cmake ..; make\e[0m' to compile and '\e[1msudo make install\e[0m' to install.\n to uninstall run '\e[1msudo make uninstall\e[0m'."
sleep 0.3
exit 0

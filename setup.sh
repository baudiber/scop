#! /bin/bash

prefix="\033[2;37m[libsdl2.so/setup] - \033[0m"

function mac_setup() {
	list=`brew list`;
	if [ $? -ne 0 ]
	then
		printf "$prefix brew is missing.\n";
		rm -rf $HOME/.brew \
			&& git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew \
			&& echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc \
			&& source $HOME/.zshrc \
			&& brew update;
		printf "$prefix brew installed.\n";
		list=`brew list`;
		if [ $? -ne 0 ]
		then
			printf "$prefix\033[2;31mbrew installation failed.\n\033[0m";
			exit 1;
		fi
	fi

	sdl2=`echo $list | grep sdl2`
	if [ $? -ne 0 ]
	then
		printf "$prefix sdl2 is missing.\n"
		brew install SDL2
		if [ $? -ne 0 ]
		then
			printf "$prefix\033[2;31msdl2 installation failed.\n\033[0m";
			exit 1;
		fi
		printf "$prefix sdl2 installed.\n"
	fi

	glew=`echo $list | grep glew`
	if [ $? -ne 0 ]
	then
		printf "$prefix glew is missing.\n"
		brew install glew
		if [ $? -ne 0 ]
		then
			printf "$prefix\033[2;31mglew installation failed.\n\033[0m";
			exit 1;
		fi
		printf "$prefix glew installed.\n"
	fi
}

function linux_setup() {
	sudo apt install libsdl2-dev libglew-dev;
}

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    linux_setup;
elif [[ "$OSTYPE" == "darwin"* ]]; then
    mac_setup;
fi

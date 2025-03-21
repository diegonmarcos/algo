### Ubuntu base image
FROM ubuntu:latest



### Install necessary system packages
RUN apt update && 	apt install -y 	build-essential bash-completion command-not-found less man-db time 	sudo 	zsh 	vim nano 	make cmake 	git tar wget curl 	gcc gdb 	clang clang-tidy lldb 	valgrind kcachegrind 	xdotool bear 	doxygen graphviz 	libpq-dev libbsd-dev libncurses-dev libxext-dev 	python3 pipx python3-pip python3-dev python3-venv python3-wheel 	&& rm -rf /var/lib/apt/lists/*

RUN pipx install 	pipenv 	gdown 	&& rm -rf /var/lib/apt/lists/* 	&& pipx ensurepath


RUN apt update && apt upgrade -y




### Additional packages (separately from the above layer to avoid re-processing)
#RUN apt install -y #	command-not-found less man-db time 



### Entrypoint to run the login script
ADD login.sh program_root/system/login.sh
RUN rm -rf login.sh
RUN chmod +x program_root/system/login.sh
RUN bash /program_root/system/login.sh
RUN bash install.sh || true
RUN zsh
#ENTRYPOINT ["program_root/system/login.sh"]



### Set the environment variables
ENV PATH="${PATH}:/root/.local/bin"



### Folder source code
#RUN git clone <GIT_REPO_URL> /push_swap
#COPY push_swap /push_swap
#RUN from mounted mirrored volume done in the docker-compose file



### Set the working directory
WORKDIR /program_root/program

### Start zsh shell
CMD ["zsh"]



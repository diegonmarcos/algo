#!/bin/bash

wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh && chmod 777 install.sh && ./install.sh && #git clone --depth=1 https://github.com/romkatv/powerlevel10k.git \"/home/dinepomu/.oh-my-zsh/custom/themes/powerlevel10k\" && #sed -i 's/ZSH_THEME=\"robbyrussell\"/ZSH_THEME=\"powerlevel10k\/powerlevel10k\"/' ~/.zshrc
chsh -s /usr/bin/zsh

# Pi-Apps CLI
Pi-Apps CLI client written in C 

### About this project
This is my first complete C program I've written! It's based off of [@Itai-Nelken](https://github.com/Itai-Nelken)'s Pi-Apps-Terminal-Bash-Edition, as it has the same functions.

### Installing

Make sure you have [Pi-Apps](https://github.com/Botspot/pi-apps) installed first, this program is useless without it.

```bash
git clone https://github.com/ryanfortner/pi-apps-cli.git
cd pi-apps-cli
mkdir build; cd build; cmake ..
```
These steps will generate a binary file called `pi-apps`. You can either run this binary directly, or install it with the following command:

```
sudo make install
```

### Uninstalling
open your terminal in the `pi-apps-cli/build` folder and run `sudo make uninstall`.
you can also simply delete `/usr/local/bin/pi-apps`.

## to do
- [x] install
- [x] uninstall
- [ ] list-all
- [ ] list-installed
- [ ] list-uninstalled
- [ ] list-corrupted
- [ ] search
- [ ] website
- [ ] debianization
# Pi-Apps_terminal-C_edition
Pi-Apps terminal written in C

## Compiling
**it's recommended to run the `install_checks.sh` script by running `bash install_checks.sh` after the `cd` line bellow to make sure the program will run correctly.**
```bash
git clone https://github.com/Itai-Nelken/Pi-Apps_terminal-C_edition.git
cd Pi-Apps_terminal-C_edition
mkdir build; cd build; cmake ..
```
to run from the build whithout installing, run from the `build` folder: `./papm`.
## Installing
first compile using the steps in the the compiling step, then run `sudo make install`.
## Uninstalling
open your terminal in the `Pi-Apps_terminal-C_edition/build` folder and run `sudo make uninstall`.
you can also simply delete `/usr/local/bin/papm`.
## running
if you installed with `sudo make install`, then run with `papm`. otherwise you can run it directly from the build folder by typing `./papm` after compiling.
## to do
- [x] install
- [x] uninstall
- [ ] list-all
- [ ] list-installed
- [ ] list-uninstalled
- [ ] list-corrupted
- [ ] search
- [ ] website

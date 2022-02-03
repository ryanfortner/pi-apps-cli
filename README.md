# Pi-Apps CLI
Pi-Apps command-line client written in C 

![screenshot](https://github.com/ryanfortner/pi-apps-cli/blob/master/screenshot.png?raw=true)

### Installing

Make sure you have [Pi-Apps](https://github.com/Botspot/pi-apps) installed first, this program is useless without it.

```bash
git clone https://github.com/ryanfortner/pi-apps-cli.git
cd pi-apps-cli
mkdir build; cd build; cmake ..
make
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
- [x] list-all
- [ ] list-installed
- [ ] list-uninstalled
- [ ] list-corrupted
- [ ] search
- [ ] website
- [ ] release workflow
- [ ] debianization

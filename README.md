# Breakout in Terminal

A simple Breakout game written in pure C for Unix/Linux terminals using ncurses.

## Requirements

Before building the project, make sure you have:
- GCC
- Make
- ncurses development library

### Ubuntu / Debian
```sh
sudo apt update
sudo apt install build-essential libncurses-dev
```

### Fedora
```sh
sudo dnf install gcc make ncurses-devel
```

### Arch Linux
```sh
sudo pacman -S base-devel ncurses
```

### openSUSE
```sh
sudo zypper install gcc make ncurses-devel
```

### Build

Clone the repository and build the project:

```sh
git clone https://github.com/LeoHernandes/breakout.git
cd breakout
make
```

This will generate the breakout executable.

```sh
./breakout
```
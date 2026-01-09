# Sysinfo

**Sysinfo** is a small C program that displays system information on Linux. The tool is designed to be lightweight and provides quick access to essential system data, similar to tools like `fastfetch` or `neofetch`.

## Features

The program can display:

- **CPU information**
- **GPU information**
- **Memory (RAM and swap)**  
- **System uptime**  
- **Hostname**  
- **Kernel and OS version**

## Screenshot

![Sysinfo](https://i.imgur.com/YbkIBli.png)

## Compilation

The project uses a structure with `src/` for source files and `include/` for headers.

Compile with gcc:

    gcc -Iinclude src/*.c -o sysinfo

Or using the Makefile:

    make

After compiling, run the program with:

    ./sysinfo [option] or ./sysinfo

## Installation

This project is currently available on fedora v43 copr, install instructions below.

Step 1.

    sudo dnf upgrade

Step 2.

    dnf copr enable betong/sysinfo

Step 3.

    sudo dnf install sysinfo

Step 4.

    sysinfo

## Usage

    Usage: ./sysinfo [--cpu | --gpu | --mem | --all | --uptime | --version | --help]

### Options

- `--cpu`      : **Display CPU information**
- `--gpu`      : **Display GPU information** 
- `--mem`      : **Display memory (RAM)**
- `--swap`     : **Display swap**
- `--all`      : **Display all available system information**  
- `--uptime`   : **Display system uptime**  
- `--version`  : **Display program version**  
- `--help`     : **Show this help message**  

## Contribute

Contributions are welcome.

This project is open to maintenance, improvements, refactoring, and new features.  
The TODO list can be used as inspiration, but it is **not a requirement** to follow it.

Feel free to contribute with any idea or change you think improves the project, regardless of whether it is listed in TODO or not.
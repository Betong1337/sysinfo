# Sysinfo

**Sysinfo** is a small C program that displays system information on Linux. The tool is designed to be lightweight and provides quick access to essential system data, similar to tools like `fastfetch` or `neofetch`.

## Features

The program can display:

- **CPU information and per-core usage**  
- **Memory (RAM and swap)**  
- **System uptime**  
- **Hostname**  
- **Program version**  

## Compilation

The project uses a structure with `src/` for source files and `include/` for headers.

Compile with gcc:

    gcc -Iinclude src/*.c -o sysinfo

Or using the Makefile:

    make

After compiling, run the program with:

    ./sysinfo [option]

## Usage

    Usage: ./sysinfo [--cpu | --mem | --all | --uptime | --version | --hostname | --help]

### Options

- `--cpu`      : **Display CPU information and per-core usage**  
- `--mem`      : **Display memory (RAM and swap)**  
- `--all`      : **Display all available system information**  
- `--uptime`   : **Display system uptime**  
- `--version`  : **Display program version**  
- `--hostname` : **Display system hostname**  
- `--help`     : **Show this help message**  

## License

This project is **open-source** and free to use.

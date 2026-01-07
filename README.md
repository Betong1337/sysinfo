# Sysinfo

**Sysinfo** is a small C program that displays system information on Linux. The tool is designed to be lightweight and provides quick access to essential system data, similar to tools like `fastfetch` or `neofetch`.

## Features

The program can display:

- **CPU information and per-core usage (Actually not yet)**  
- **Memory (RAM and swap)**  
- **System uptime**  
- **Hostname**  
- **Kernel and OS version**  

## Compilation

The project uses a structure with `src/` for source files and `include/` for headers.

Compile with gcc:

    gcc -Iinclude src/*.c -o sysinfo

Or using the Makefile:

    make

After compiling, run the program with:

    ./sysinfo [option] or ./sysinfo

## Usage

    Usage: ./sysinfo [--cpu | --mem | --all | --uptime | --version | --help]

### Options

- `--cpu`      : **Display CPU information and per-core usage**  
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

## License

This project is **open-source** and free to use.

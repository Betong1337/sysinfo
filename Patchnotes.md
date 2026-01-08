Patchnotes 2026-01-08

sysinfo.c
    kernel:
        Added error handling on print_kernel_version().
    Uptime:
        Changed uptime output to: Uptime: 2 days, 13 hours, 13 minutes
        Changed error handling to more readable code.
        Fixed bug with uptime print.
    print_title:
        cleaned up code.
    print_os_type:
        Changed error handling to more readable code.
        Changed name to print_os_info
    get_hostname():
        Changed error handling to more readable code.
        
sysinfo.h
    Changed name to print_os_info

memory.c
    get_memory_info():
        Changed error handling
    
    print_swap():
        Added percentage on used swap.
        Cleaned up some code.

cpu.c
    print_cpu_model():
        Changed error handling

Added defines.h for compare strings, colors and print formatting

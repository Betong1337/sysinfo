#ifndef GPU_H
#define GPU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <color.h>

#define GPU_COMMAND "/bin/lspci | grep -iE 'VGA|3D|video'"
#define GPU_MSG "%s%s%d%s%s%s"

void print_gpus();

#endif
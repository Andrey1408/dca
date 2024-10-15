#include "ipc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int *size;
    int *writer;
    int *reader;
} Pipeline_ptr;

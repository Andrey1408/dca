#include "ipc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "process_factory.h"

typedef struct {
    int **writer;
    int **reader;
} Pipeline_ptr;

void create_pipe(Process_ptr *proc, FILE *pipes_log_file);

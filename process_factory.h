#include "ipc.h"
#include "pipe_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    local_id cur_id;
    local_id size;
    Pipeline_ptr **pipline;
} Process_ptr;

void defaultProcess(Process_ptr* proc, FILE* events_log);

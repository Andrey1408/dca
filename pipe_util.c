#include <stdlib.h>
#include <unistd.h>
#include "pipe_util.h"
#include "log.h"
#include "process_factory.h"

void create_pipe(Process_ptr *proc, FILE *pipes_log_file) {
    Pipeline_ptr* pp = proc->pipline;
    pp->writer = (int **)malloc( sizeof(int *) * proc->size);
    pp->reader = (int **)malloc( sizeof(int *) * proc->size);
    pp->reader[0] = malloc( sizeof(int) * (proc->size * proc->size));
    pp->writer[0] = malloc( sizeof(int) * (proc->size * proc->size));
    for ( int i = 0; i < proc->size; i++ ) {
        pp->reader[i] = ( *(pp->reader) + proc->size * i );
        pp->writer[i] = ( *(pp->writer) + proc->size * i );
    }

    for (local_id i = 0; i < proc->size; ++i) {
        for(local_id j =0; j < proc->size; ++j) {
            int pipe[2];
            pp->reader[i][j] = pipe[0];
            pp->writer[i][j] = pipe[1];
            log_pipe(pipes_log_file, i, j, pp->reader[i][j], pp->writer[i][j]);
        }
    }
}
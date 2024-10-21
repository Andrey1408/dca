#include <unistd.h>
#include <stdio.h>
#include "ipc.h"
#include "pipe_util.h"
#include "process_factory.h"

int send(void * self, local_id dst, const Message * msg) {
    Process_ptr *proc = (Process_ptr *)self;
    Pipeline_ptr pp = proc->pipline[proc->cur_id][dst];
    if (write(pp.writer, msg, sizeof(Message)) < 0) {
        return 1;
    }
    if (msg->s_header.s_magic != MESSAGE_MAGIC) {
        return 1;
    }
    return 0;
}

int send_multicast(void * self, const Message * msg) {
    Process_ptr *proc = (Process_ptr *)self;
    for (local_id i = 0; i < proc->size; i++) {
        send(self, i, msg);
    }
    return 0;
}

int receive(void * self, local_id from, Message * msg) {
    Process_ptr *proc = (Process_ptr *)self;
    Pipeline_ptr pp = proc->pipline[from][proc->cur_id];
    if (read(pp.reader, msg, sizeof(Message)) < 0) {
        return 1;
    }
    if (msg->s_header.s_magic != MESSAGE_MAGIC) {
        return 1;
    }
    return 0;  
}

int receive_any(void * self, Message * msg) {
    return 0;
}

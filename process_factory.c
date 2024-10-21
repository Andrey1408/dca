#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ipc.h"
#include "log.h"
#include "process_factory.h"


Message create_message ( MessageType type, char* contents ) {
    Message msg;

    msg.s_header.s_magic = MESSAGE_MAGIC;
    msg.s_header.s_payload_len = strlen(contents);
    msg.s_header.s_type = type;
    memcpy(&(msg.s_payload), contents, strlen(contents));

    return msg;
}

void defaultProcess(Process_ptr* proc, ) {
    send_multicast(p, create_message(STARTED));
    
}

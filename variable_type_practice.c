#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint8_t header;
    uint8_t cmd_id;
    uint8_t data_len;
    uint8_t checksum;
} CommandPacket;

void send_command(uint8_t cmd){
    CommandPacket pkg;

    pkg.header = 0xAA;
    pkg.cmd_id = cmd;
    pkg.data_len = 0;
    pkg.checksum = pkg.header ^ pkg.cmd_id;

    printf("Sent Command: 0x%x\n", pkg.cmd_id);
}

int main(){

    uint8_t cmd = 0x01;
    send_command(cmd);

    return 0;
}

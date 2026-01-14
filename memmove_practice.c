#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcpy

typedef struct{
    uint8_t id;
    uint16_t value;
    uint8_t timestamp;
} SensorData;

typedef struct __attribute__((packed)){
    uint8_t id;
    uint16_t value;
    uint8_t timestamp;
} SensorData_packed;

int main(){
    SensorData sensor;
    sensor.id = 0x01;
    sensor.value = 0x1234;
    sensor.timestamp = 0x55;
    printf("Size of SensorData: %x\n", sizeof(SensorData));

    uint8_t tx_buffer1[10];
    memset(tx_buffer1, 0, sizeof(tx_buffer1));

    memcpy(tx_buffer1, &sensor, sizeof(sensor));

    printf("Buffer Content: \n");
    for(int i = 0; i < sizeof(SensorData); i++){
        printf("0x%02X\n", tx_buffer1[i]);
    }
// ---------------------------------------------------------------------
    SensorData_packed sensor_packed;
    sensor_packed.id = 0x01;
    sensor_packed.value = 0x1234;
    sensor_packed.timestamp = 0x55;
    printf("Size of SensorData: %x\n", sizeof(SensorData_packed));

    uint8_t tx_buffer2[10];
    memset(tx_buffer2, 0, sizeof(tx_buffer2));

    memcpy(tx_buffer2, &sensor_packed, sizeof(sensor_packed));

    printf("Buffer Content: \n");
    for(int i = 0; i < sizeof(SensorData_packed); i++){
        printf("0x%02X\n", tx_buffer2[i]);
    }
    return 0;
}

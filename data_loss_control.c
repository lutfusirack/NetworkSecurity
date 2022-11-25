#include "mqtt_client.h"
#include "esp_log.h"
#include "cJSON.h"


char * create_data_loss_header(char const * p_device_id, uint8_t len_device_id, uint32_t message_index){

    uint8_t len = 16; // byte in the header

    char * p_header = heap_caps_malloc(len, MALLOC_CAP_SPIRAM);
    memcpy(p_header,p_device_id,len_device_id);
    char msg_index_temp[4];
    snprintf(msg_index_temp,sizeof(msg_index_temp),"%d",message_index);
    strcat(p_header,msg_index_temp);

    return p_header;
}
/*
 * ANALYZE.c
 *
 *  Created on: Nov 25, 2020
 *      Author: fw_tien
 */
#include <PROCESS/PROCESS.h>

uint8_t ANALYZE_packet(PACKET_typedef *PACKET, uint8_t *data_input, uint16_t len);
uint8_t ANALYZE_checksum_decode(uint8_t *buff, uint8_t len);
uint8_t ANALYZE_checksum_encode(uint8_t *buff, uint8_t len);

uint8_t ANALYZE_packet(PACKET_typedef *PACKET, uint8_t *data_input, uint16_t len)
{
    PACKET->start_code = data_input[0];    //data_input[0]: start_code
    PACKET->length     = data_input[1];    //data_input[1]: length

    if(PACKET->start_code != START_CODE)   //Start code is not equal 0x69
    {
        PACKET->start_code = START_FAIL;   //Always PACKET.start_code is START_FAIL
        return ANALYZE_RETURN_FALSE;       //Data read from UART is failed, return ANALYZE_RETURN_FALSE
    }
    if( len < 5 && PACKET->length < 5)     //Data length
    {
        PACKET->start_code = START_FAIL;
        return ANALYZE_RETURN_FALSE;
    }
    if(ANALYZE_checksum_decode(data_input, data_input[1]) == ANALYZE_RETURN_FALSE)
    {
        PACKET->start_code = START_FAIL;
        return ANALYZE_RETURN_FALSE;
    }
    PACKET->command     = data_input[2];    //data_input[2]: Command
    PACKET->sensor_type = data_input[3];    //data_input[3]: sensor_type
    PACKET->len_data    = PACKET->length - 5;

    memcpy(PACKET->data, &data_input[4], PACKET->len_data);

    return ANALYZE_RETURN_TRUE;
}

uint8_t ANALYZE_checksum_decode(uint8_t *buff, uint8_t len)
{
    uint8_t i, check_sum = 0;
    for(i = 0; i < len-1; i++)
    {
        check_sum += buff[i];
    }

    if(check_sum == buff[len-1])
    {
        return ANALYZE_RETURN_TRUE;
    }
    else
        return ANALYZE_RETURN_FALSE;
}

uint8_t ANALYZE_checksum_encode(uint8_t *buff, uint8_t len)
{
    uint8_t i, check_sum = 0;
    for(i = 0; i < len - 1; i++)
    {
        check_sum += buff[i];
    }
    return check_sum;
}



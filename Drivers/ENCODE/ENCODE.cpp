/*
 * ENCODE.c
 *
 *  Created on: May 21, 2019
 *      Author: QuanLe
 */

#include <PROCESS/PROCESS.h>

uint8_t ENCODE_get_checksum(uint8_t *buff, uint8_t len);
uint8_t ENCODE_check_checksum(uint8_t *buff, uint8_t len);
uint8_t ENCODE_string_2_hex(char *in_str_buff, uint16_t in_str_length, uint8_t *out_hex_buff, uint16_t *out_hex_length);
uint8_t ENCODE_hex_2_string(uint8_t *in_hex_buff, uint16_t in_hex_length, char *out_str_buff, uint16_t *out_str_length);

uint32_t ENCODE_double_to_scale(double_t value, uint8_t value_size);
double_t ENCODE_scale_to_double(uint32_t value, uint8_t value_size);

uint8_t ENCODE_get_checksum(uint8_t *buff, uint8_t len)
{
    uint8_t i;
    uint16_t sum = 0;

    for( i = 0 ; i < len; i ++)
    {
        sum += buff[i];
    }
    return (uint8_t)sum;
}

uint8_t ENCODE_check_checksum(uint8_t *buff, uint8_t len)
{
    if(ENCODE_get_checksum(buff, len) == buff[len])
    {
        return ENCODE_RETURN_TRUE;
    }
    return ENCODE_RETURN_FALSE;
}

uint8_t ENCODE_string_2_hex(char *in_str_buff, uint16_t in_str_length, uint8_t *out_hex_buff, uint16_t *out_hex_length)
{
    if((in_str_length % 2) != 0 || in_str_length > 256) return ENCODE_RETURN_FALSE;

    uint16_t i;

    for(i = 0 ; i < in_str_length; i ++)
    {
        if(in_str_buff[i] >= '0' && in_str_buff[i] <= '9')
        {
            in_str_buff[i] = in_str_buff[i] - 0x30;
        }
        else if(in_str_buff[i] >= 'A' && in_str_buff[i] <= 'F')
        {
            in_str_buff[i] = (in_str_buff[i] - 'A') + 0x0A;
        }
        else if(in_str_buff[i] >= 'a' &&in_str_buff[i] <= 'f')
        {
            in_str_buff[i] = (in_str_buff[i] - 'a') + 0x0A;
        }
    }

    *out_hex_length = in_str_length/2;

    for( i = 0 ; i < (in_str_length/2); i++)
    {
        out_hex_buff[i] = (uint8_t) ((in_str_buff[i*2] << 4) & 0xF0) | (uint8_t)(in_str_buff[i*2 +1] & 0x0F);
    }

    return ENCODE_RETURN_TRUE;
}

uint8_t ENCODE_hex_2_string(uint8_t *in_hex_buff,
                            uint16_t in_hex_length,
                            char *out_str_buff,
                            uint16_t *out_str_length)
{
    if(in_hex_length > 128) return ENCODE_RETURN_FALSE;

    uint16_t i;

    for( i = 0 ; i < in_hex_length; i++)
    {
        out_str_buff[i*2] = ((in_hex_buff[i] & 0xF0)>>4) <= 0x09 ? (uint8_t)((in_hex_buff[i] & 0xF0)>>4) + 0x30 : (uint8_t)(((in_hex_buff[i] & 0xF0)>>4)-0x09) + 0x40;
        out_str_buff[i*2 + 1] = (uint8_t)((in_hex_buff[i] & 0x0F)) <= 0x09 ? (uint8_t)((in_hex_buff[i] & 0x0F)) + 0x30 : (uint8_t)((in_hex_buff[i] & 0x0F)-0x09) + 0x40;
    }

    *out_str_length = in_hex_length * 2;
    return ENCODE_RETURN_TRUE;
}


uint32_t ENCODE_double_to_scale(double_t value, uint8_t value_size)
{
    uint32_t ivalue = 0;
    uint32_t scale  = 0;

    switch (value_size)
    {
        case ENCODE_VALUE_SIZE_2:
            if(value < ENCODE_RATIO_10)
            {
                scale = ENCODE_SCALE_3;
                ivalue = value * ENCODE_RATIO_1000;
            }
            else if(value < ENCODE_RATIO_100)
            {
                scale = ENCODE_SCALE_2;
                ivalue = value * ENCODE_RATIO_100;
            }
            else if(value < ENCODE_RATIO_1000)
            {
                scale = ENCODE_SCALE_1;
                ivalue = value * ENCODE_RATIO_10;
            }
            else
            {
                scale = ENCODE_SCALE_0;
                ivalue = value;
            }
            ivalue = ivalue | (scale << ENCODE_SCALE_2_BYTES);
            break;
        case ENCODE_VALUE_SIZE_3:
            if(abs(value) < ENCODE_RATIO_1000)
            {
                scale = ENCODE_SCALE_3;
                ivalue = value * ENCODE_RATIO_1000;
            }
            else if(abs(value) < ENCODE_RATIO_10000)
            {
                scale = ENCODE_SCALE_2;
                ivalue = value * ENCODE_RATIO_100;
            }
            else if(abs(value) < ENCODE_RATIO_100000)
            {
                scale = ENCODE_SCALE_1;
                ivalue = value * ENCODE_RATIO_10;
            }
            else
            {
                scale = ENCODE_SCALE_0;
                ivalue = value;
            }
            ivalue = ivalue | (scale << ENCODE_SCALE_3_BYTES);
            break;
        case ENCODE_VALUE_SIZE_4:
            if(value < ENCODE_RATIO_1000000) //1.000.000
            {
                scale = ENCODE_SCALE_3;
                ivalue = value * ENCODE_RATIO_1000;
            }
            else if(value < ENCODE_RATIO_10000000) //10.000.000
            {
                scale = ENCODE_SCALE_2;
                ivalue = value * ENCODE_RATIO_100;
            }
            else if(value < ENCODE_RATIO_100000000) // 100.000.000
            {
                scale = ENCODE_SCALE_1;
                ivalue = value * ENCODE_RATIO_10;
            }
            else
            {
                scale = ENCODE_SCALE_0;
                ivalue = value;
            }
            ivalue = ivalue | (scale << ENCODE_SCALE_4_BYTES);
            break;
        default:
            break;
    }
    return ivalue;
}

double_t ENCODE_scale_to_double(uint32_t value, uint8_t value_size)
{
    double_t dvalue = 0;
    uint32_t scale = 0;

    switch(value_size)
    {
        case ENCODE_VALUE_SIZE_2:
            scale = (value >> ENCODE_SCALE_2_BYTES) & ENCODE_SCALE_BITS;
            value = value & ENCODE_VALUE_2_BYTES;
            dvalue = value;
            break;
        case ENCODE_VALUE_SIZE_3:
            scale = (value >> ENCODE_SCALE_3_BYTES) & ENCODE_SCALE_BITS;
            value = value & ENCODE_VALUE_3_BYTES;
            dvalue = value;
            if(value & ENCODE_VALUE_SIGN_3_BYTES)
            {
                value = value | ENCODE_VALUE_SIGN_3_BYTES;
                dvalue = (int32_t)value;
            }
            break;
        case ENCODE_VALUE_SIZE_4:
            scale = (value >> ENCODE_SCALE_4_BYTES) & ENCODE_SCALE_BITS;
            value = value & ENCODE_VALUE_4_BYTES;
            dvalue = value;
            break;
        default:
            break;
    }

    switch(scale)
    {
        case ENCODE_SCALE_0:
            scale = ENCODE_RATIO_1;
            break;
        case ENCODE_SCALE_1:
            scale = ENCODE_RATIO_10;
            break;
        case ENCODE_SCALE_2:
            scale = ENCODE_RATIO_100;
            break;
        case ENCODE_SCALE_3:
            scale = ENCODE_RATIO_1000;
            break;
        default:
            break;
    }

    return dvalue/scale;
}

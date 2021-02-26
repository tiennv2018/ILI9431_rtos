/*
 * ENCODE.h
 *
 *  Created on: Oct 20, 2020
 *      Author: fw_tien
 */

#ifndef DRIVERS_ENCODE_ENCODE_H_
#define DRIVERS_ENCODE_ENCODE_H_

#define ENCODE_RETURN_FALSE                 0x00
#define ENCODE_RETURN_TRUE                  0x01

#define ENCODE_VALUE_SIZE_2                 2
#define ENCODE_VALUE_SIZE_3                 3
#define ENCODE_VALUE_SIZE_4                 4

#define ENCODE_VALUE_2_BYTES                0x00003FFF
#define ENCODE_VALUE_3_BYTES                0x003FFFFF
#define ENCODE_VALUE_4_BYTES                0x3FFFFFFF

#define ENCODE_VALUE_SIGN_3_BYTES           0xFFE00000

#define ENCODE_SCALE_BITS                   0x03
#define ENCODE_SCALE_2_BYTES                14
#define ENCODE_SCALE_3_BYTES                22
#define ENCODE_SCALE_4_BYTES                30

#define ENCODE_SCALE_0                      0
#define ENCODE_SCALE_1                      1
#define ENCODE_SCALE_2                      2
#define ENCODE_SCALE_3                      3

#define ENCODE_RATIO_1                      1
#define ENCODE_RATIO_10                     10
#define ENCODE_RATIO_100                    100
#define ENCODE_RATIO_1000                   1000
#define ENCODE_RATIO_10000                  10000
#define ENCODE_RATIO_100000                 100000
#define ENCODE_RATIO_1000000                1000000
#define ENCODE_RATIO_10000000               10000000
#define ENCODE_RATIO_100000000              100000000


extern uint8_t ENCODE_get_checksum(uint8_t *buff, uint8_t len);
extern uint8_t ENCODE_check_checksum(uint8_t *buff, uint8_t len);
extern uint8_t ENCODE_string_2_hex(char *in_str_buff, uint16_t in_str_length, uint8_t *out_hex_buff, uint16_t *out_hex_length);
extern uint8_t ENCODE_hex_2_string(uint8_t *in_hex_buff, uint16_t in_hex_length, char *out_str_buff, uint16_t *out_str_length);

extern uint32_t ENCODE_double_to_scale(double_t value, uint8_t value_size);
extern double_t ENCODE_scale_to_double(uint32_t value, uint8_t value_size);


#endif /* DRIVERS_ENCODE_ENCODE_H_ */

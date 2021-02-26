/*
 * ANALYZE.h
 *
 *  Created on: Nov 25, 2020
 *      Author: fw_tien
 */

#ifndef DRIVERS_ANALYZE_ANALYZE_H_
#define DRIVERS_ANALYZE_ANALYZE_H_

#define FLAG_INACTIVE                   0x00
#define FLAG_ACTIVE                     0x01
#define ANALYZE_RETURN_FALSE            0x00
#define ANALYZE_RETURN_TRUE             0x01
#define RETURN_FAIL                     0xFF

#define ANALYZE_INDEX_PROPERTY                      0
#define ANALYZE_INDEX_PROPERTY_SETTING_POWER        ANALYZE_INDEX_PROPERTY + 1

#define START_CODE                      0x69
#define START_FAIL                      0xFF

typedef struct {
    uint8_t start_code;
    uint8_t length;
    uint8_t command;
    uint8_t sensor_type;
    uint8_t data[80];
    uint8_t len_data;
}PACKET_typedef;

//extern PACKET_typedef PACKET;

extern uint8_t ANALYZE_packet(PACKET_typedef *PACKET, uint8_t *data_input, uint16_t len);
extern uint8_t ANALYZE_checksum_encode(uint8_t *buff, uint8_t len);

#endif /* DRIVERS_ANALYZE_ANALYZE_H_ */

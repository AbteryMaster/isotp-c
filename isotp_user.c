/*
 * isotp_user.c
 *
 *  Created on: 13 Jan 2020
 *      Author: Anton
 */

#include "isotp_user.h"
#include "HW_access.h"

/* user implemented, print debug message */
void isotp_user_debug(const char* message){

}

/* user implemented, send can message */
uint8_t isotp_user_send_can(const uint32_t arbitration_id, const uint8_t* data, const uint8_t size){
	return hw_can_send_frame (arbitration_id, data, 0, size, 0);

}

/* user implemented, get millisecond */
uint32_t isotp_user_get_ms(void){
	return hw_get_time();
}


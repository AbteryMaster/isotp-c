/*
 * isotp_user.c
 *
 *  Created on: 13 Jan 2020
 *      Author: Anton
 */

#include "isotp_user.h"
#include "database.h"

/* user implemented, print debug message */
void isotp_user_debug(const char* message){

}

/* user implemented, send can message */
uint8_t isotp_user_send_can(const uint32_t arbitration_id, const uint8_t * data, const uint8_t size)
{
	hw_can_pack_isotp_frame(data, size);

	uint16_t frame_name = get_frame_name(arbitration_id, CANBUS1);

	xQueueSend(event_id_queue_tx_can1, &frame_name, 0);

	return 0;
}

/* user implemented, get millisecond */
uint32_t isotp_user_get_ms(void){
	return hw_get_time();
}

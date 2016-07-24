/*
 * upsat-comms-software: Communication Subsystem Software for UPSat satellite
 *
 *  Copyright (C) 2016, Libre Space Foundation <http://librespacefoundation.org/>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef INC_STATS_H_
#define INC_STATS_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint32_t rx_failed_cnt;
  uint32_t rx_crc_failed_cnt;
  uint32_t tx_failed_cnt;
  uint32_t tx_frames_cnt;
  uint32_t rx_frames_cnt;
  uint32_t uptime_h;
  uint32_t uptime_m;
  uint32_t uptime_s;
  uint32_t last_tick;
  float comms_temperature;
  float eps_temperature;
  float bat_temperature;
  int32_t last_tx_error_code;
  int32_t last_rx_error_code;
  uint32_t battery_mV;
  int32_t battery_mA;
  uint32_t bus_3300_mA;
  uint32_t bus_5000_mA;
  uint32_t invalid_dest_frames_cnt;
  uint32_t last_utc;
} comms_rf_stat_t;

void
comms_rf_stats_init(comms_rf_stat_t *h);

void
comms_rf_stats_update(comms_rf_stat_t *h);

void
comms_rf_stats_frame_received(comms_rf_stat_t *h, uint8_t succesfull,
			      int32_t error);

void
comms_rf_stats_frame_transmitted(comms_rf_stat_t *h, uint8_t succesfull,
				 int32_t error);

void
comms_rf_stats_invalid_dest_frame(comms_rf_stat_t *h);

void
comms_rf_stats_invalid_crc_frame(comms_rf_stat_t *h);

float
comms_rf_stats_get_temperature(comms_rf_stat_t *h);

void
comms_rf_stats_wod_received(comms_rf_stat_t *h, const uint8_t *obc_wod);
#endif /* INC_STATS_H_ */

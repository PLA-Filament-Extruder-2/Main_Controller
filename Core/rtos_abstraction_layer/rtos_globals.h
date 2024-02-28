/***********************************************************************************************************************
 * Main_Controller
 * rtos_globals.h
 *
 * wilson
 * 2/27/24
 * 9:37 PM
 *
 * Description:
 *
 **********************************************************************************************************************/

#ifndef MAIN_CONTROLLER_RTOS_GLOBALS_H
#define MAIN_CONTROLLER_RTOS_GLOBALS_H

/* c/c++ includes */

/* stm32 includes */

/* third-party includes */
#include "cmsis_os2.h"
/* hal includes */

/* driver includes */

/* rtos abstraction includes */

/* sys op includes */

/* meta structure includes */

#define QUEUE_LENGTH_MAX    16

osMessageQueueId_t get_initialization_task_queue_handle();
osMessageQueueId_t get_extrusion_task_spi_tx_queue_handle();
osMessageQueueId_t get_extrusion_task_spi_rx_queue_handle();
osMessageQueueId_t get_extrusion_task_i2c_tx_queue_handle();
osMessageQueueId_t get_extrusion_task_i2c_rx_queue_handle();
osMessageQueueId_t get_spooling_task_i2c_tx_queue_handle();
osMessageQueueId_t get_spooling_task_i2c_rx_queue_handle();

osMutexId_t get_spi_tx_buffer_mutex();


#endif //MAIN_CONTROLLER_RTOS_GLOBALS_H

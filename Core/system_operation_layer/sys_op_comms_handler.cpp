/***********************************************************************************************************************
 * Main_Controller
 * system_operation_comms_handler.cpp
 *
 * wilson
 * 11/6/22
 * 3:46 PM
 *
 * Description:
 *
 **********************************************************************************************************************/

/* c/c++ includes */
#include <cstdint>
/* stm32 includes */
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
/* 3rd-party includes */
#include "cmsis_os2.h"
/* hal includes */
#include "../hardware_abstraction_layer/hal_general.h"
#include "../hardware_abstraction_layer/hal_spi.h"
#include "../hardware_abstraction_layer/hal_i2c.h"
#include "../hardware_abstraction_layer/hal_callbacks.h"
#include "mcu_clock_timers.h"
#include "system_clock.h"
#include "gpio.h"
#include "spi.h"
/* driver includes */
#include "../driver_layer/driver_dc_motor_controller.h"
#include "../driver_layer/driver_rtd.h"
/* system includes */
/* rtos includes */

/* system_operation_comms_handler header */
#include "sys_op_comms_handler.h"

#define COMMS_HANDLER_STATE_INITIALIZE      0
#define COMMS_HANDLER_STATE_RUN             1

spi::handle_t spi_2_handle;
i2c::handle_t i2c_2_handle;

void SPI2_IRQHandler()
{
    spi_irq_handler(get_spi_object());
}

namespace driver
{
    dc_motor_controller motor_controller_1;
    rtd rtd_1;
}

namespace hal
{
    spi spi_2;
}

spi* get_spi_object()
{
    return &hal::spi_2;
}

spi::handle_t* get_spi_handle()
{
    return &spi_2_handle;
}

rtd* get_rtd_object()
{
    return &driver::rtd_1;
}

namespace sys_op
{
    void comms_handler_intitialize()
    {

    }

    void comms_handler_state_machine()
    {
        static uint8_t comms_handler_state = COMMS_HANDLER_STATE_INITIALIZE;
        static uint8_t counter = 0;
        uint8_t spi_byte = 0xC2;
        uint8_t rx_data = 0;
        float temp = 0;

        switch (comms_handler_state)
        {
            case COMMS_HANDLER_STATE_INITIALIZE:
                hal::spi_2.initialize_spi_object(&spi_2_handle,
             spi::SPI_TX_RX_COMPLETE_CALLBACK_ID, HAL_SPI_TxRxCplt_Callback,
                spi::SPI_TX_RX_COMPLETE_CALLBACK_ID, HAL_SPI_Error_Callback);


                driver::rtd_1.initialize_rtd(&hal::spi_2);

                comms_handler_state = COMMS_HANDLER_STATE_RUN;
                break;
            case COMMS_HANDLER_STATE_RUN:
                HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);


                if (counter == 0)
                {
                    driver::rtd_1.read_rtd_and_calculate_temperature(rtd::DEVICE_0);
                    temp = driver::rtd_1.get_device_reading_degrees_celsius();
                    counter = 1;
                }
                else if (counter == 1)
                {
                    driver::rtd_1.read_rtd_and_calculate_temperature(rtd::DEVICE_1);
                    temp = driver::rtd_1.get_device_reading_degrees_celsius();
                    counter = 2;
                }
                else if (counter == 2)
                {
                    driver::rtd_1.read_rtd_and_calculate_temperature(rtd::DEVICE_2);
                    temp = driver::rtd_1.get_device_reading_degrees_celsius();
                    counter = 0;
                }
                if (temp > 100)
                {
                    temp = 100;
                }
                break;
            default:
                break;
        }

    }
}

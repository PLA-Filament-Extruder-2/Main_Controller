/***********************************************************************************************************************
 * Main_Controller
 * device_callback.cpp
 *
 * wilson
 * 10/31/24
 * 11:19 PM
 *
 * Description:
 *
 **********************************************************************************************************************/

/* c/c++ includes */

/* stm32 includes */

/* third-party includes */

/* layer_0_hal includes */

/* layer_1_rtosal includes */

/* layer_2_device includes */
#include "device.h"
/* layer_3_control includes */

/* layer_4_sys_op includes */

/* layer_n_meta_structure includes */

/* device_callback header */
#include "device_callback.h"



void device_callback_tim_1_input_capture_pulse_detected_callback(TIM_HandleTypeDef *htim)
{
    device::band_heater::zero_crossing_pulse_restart();
    output_pulse_restart(&device::zone_1_band_heater);
    output_pulse_restart(&device::zone_2_band_heater);
    output_pulse_restart(&device::zone_3_band_heater);
}

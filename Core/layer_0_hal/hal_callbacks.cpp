/***********************************************************************************************************************
 * Main_Controller
 * hal_callbacks.cpp
 *
 * wilson
 * 11/4/22
 * 12:38 AM
 *
 * Description:
 *
 **********************************************************************************************************************/

/* c/c++ includes */

/* stm32 includes */
#include "stm32f4xx_hal.h"
/* third-party includes */

/* hal includes */
#include "hal_general.h"
/* driver includes */

/* rtos abstraction includes */

/* sys op includes */

/* meta structure includes */

/* hal_callbacks header */
#include "hal_callbacks.h"



static uint8_t spi_rx_data_ready_flag = 0;

uint8_t hal_callbacks_get_spi_rx_data_ready_flag()
{
    return spi_rx_data_ready_flag;
}

void hal_callbacks_set_spi_rx_data_ready_flag(uint8_t status)
{
    spi_rx_data_ready_flag = status;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
    {
        HAL_IncTick();
    }
}

void hal_callback_spi_rx_tx_complete(spi::module_t *hspi)
{

    if (HAL_GPIO_ReadPin(hspi->chip_select_port, hspi->chip_select_pin) == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(hspi->chip_select_port, hspi->chip_select_pin, GPIO_PIN_SET);
    spi_rx_data_ready_flag = 1;

}

void HAL_SPI_Error_Callback(spi::module_t *hspi)
{
    if (HAL_GPIO_ReadPin(hspi->chip_select_port, hspi->chip_select_pin) == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(hspi->chip_select_port, hspi->chip_select_pin, GPIO_PIN_SET);
    spi_rx_data_ready_flag = 1;
}


//static uint8_t spi_rx_data_ready_flag = 0;
//
//uint8_t hal_callbacks_get_spi_rx_data_ready_flag()
//{
//    return spi_rx_data_ready_flag;
//}
//
//void hal_callbacks_set_spi_rx_data_ready_flag(uint8_t status)
//{
//    spi_rx_data_ready_flag = status;
//}
//
//void hal_callbacks_assert_spi_chip_select(spi::module_t* _module)
//{
//    if (HAL_GPIO_ReadPin(_module->chip_select.port, _module->chip_select.pin) == CHIP_SELECT_RESET)
//        HAL_GPIO_WritePin(_module->chip_select.port, _module->chip_select.pin, (GPIO_PinState) CHIP_SELECT_SET);
//}
//void hal_callbacks_deassert_spi_chip_select(spi::module_t* _module)
//{
//    if (HAL_GPIO_ReadPin(_module->chip_select.port, _module->chip_select.pin) == CHIP_SELECT_SET)
//        HAL_GPIO_WritePin(_module->chip_select.port, _module->chip_select.pin, (GPIO_PinState) CHIP_SELECT_RESET);
//}
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//    if (htim->Instance == TIM3)
//    {
//        HAL_IncTick();
//    }
//}
//
//void hal_callback_spi_tx_rx_complete(spi::module_t* _module)
//{
//    hal_callbacks_deassert_spi_chip_select(_module);
//    spi_rx_data_ready_flag = 1;
//}
//
//void hal_callback_spi_tx_complete(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_rx_complete(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_tx_rx_half_complete(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_tx_half_complete(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_rx_half_complete(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_error(spi::module_t* _module)
//{
//    hal_callbacks_deassert_spi_chip_select(_module);
//    spi_rx_data_ready_flag = 1;
//}
//
//void hal_callback_spi_abort(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_msp_init(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//void hal_callback_spi_msp_deinit(spi::module_t* _module)
//{
//    UNUSED_CAST_VOID(_module);
//}
//
//
//
//
//
//void HAL_SPI_TxRxCplt_Callback(spi::module_t *hspi)
//{
//    hal_callbacks_deassert_spi_chip_select(hspi);
//    spi_rx_data_ready_flag = 1;
//}
//
//void HAL_SPI_Error_Callback(spi::module_t *hspi)
//{
//    hal_callbacks_deassert_spi_chip_select(hspi);
//    spi_rx_data_ready_flag = 1;
//}
//
//void HAL_SPI_TxCpltCallback(spi::module_t *spi_handle)
//{
//    UNUSED_CAST_VOID(spi_handle);
//}
//
//void HAL_SPI_RxCpltCallback(spi::module_t *spi_handle)
//{
//    UNUSED_CAST_VOID(spi_handle);
//}
//
//void HAL_SPI_TxHalfCpltCallback(spi::module_t *spi_handle)
//{
//    UNUSED_CAST_VOID(spi_handle);
//}
//
//void HAL_SPI_RxHalfCpltCallback(spi::module_t *spi_handle)
//{
//    UNUSED_CAST_VOID(spi_handle);
//}
//
//void HAL_SPI_TxRxHalfCpltCallback(spi::module_t *spi_handle)
//{
//    UNUSED_CAST_VOID(spi_handle);
//}
//
//void HAL_SPI_AbortCpltCallback(spi::module_t *spi_handle)
//{
//    UNUSED_CAST_VOID(spi_handle);
//}

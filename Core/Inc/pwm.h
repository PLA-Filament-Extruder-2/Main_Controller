/***********************************************************************************************************************
 * Main_Controller
 * pwm.h
 *
 * wilson
 * 7/12/22
 * 8:57 PM
 *
 * Description:
 *
 **********************************************************************************************************************/

//
// Created by wilson on 7/12/22.
//

#ifndef MAIN_CONTROLLER_PWM_H
#define MAIN_CONTROLLER_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
//void MX_TIM10_Init(void);

#ifdef __cplusplus
}
#endif

#endif //MAIN_CONTROLLER_PWM_H

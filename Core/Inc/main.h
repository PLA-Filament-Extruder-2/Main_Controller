/* USER CODE BEGIN Header */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/

//
///* USER CODE BEGIN EFP */
///* USER CODE END EFP */
//
///* Private defines -----------------------------------------------------------*/
//#define B1_Pin GPIO_PIN_13
//#define B1_GPIO_Port GPIOC
//#define STEPPER_PULSE_Pin GPIO_PIN_0
//#define STEPPER_PULSE_GPIO_Port GPIOA
//#define STEPPER_DIR_Pin GPIO_PIN_1
//#define STEPPER_DIR_GPIO_Port GPIOA
//#define STEPPER_ENABLE_Pin GPIO_PIN_4
//#define STEPPER_ENABLE_GPIO_Port GPIOA
//#define LD2_Pin GPIO_PIN_5
//#define LD2_GPIO_Port GPIOA
//#define SPI1_CS2_Pin GPIO_PIN_4
//#define SPI1_CS2_GPIO_Port GPIOC
//#define STEPPER_ALARM_Pin GPIO_PIN_0
//#define STEPPER_ALARM_GPIO_Port GPIOB
//#define SPI2_CS3_Pin GPIO_PIN_1
//#define SPI2_CS3_GPIO_Port GPIOB
//#define SPI2_CS1_Pin GPIO_PIN_14
//#define SPI2_CS1_GPIO_Port GPIOB
//#define SPI2_CS2_Pin GPIO_PIN_15
//#define SPI2_CS2_GPIO_Port GPIOB
//#define SPI1_CS1_Pin GPIO_PIN_10
//#define SPI1_CS1_GPIO_Port GPIOA
//#define TMS_Pin GPIO_PIN_13
//#define TMS_GPIO_Port GPIOA
//#define TCK_Pin GPIO_PIN_14
//#define TCK_GPIO_Port GPIOA
///* USER CODE BEGIN Private defines */
///* USER CODE END Private defines */


#endif /* __MAIN_H */

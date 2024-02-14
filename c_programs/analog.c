#include "main.h"
#include "stdio.h"

ADC_HandleTypeDef hadc1;

float convertToTemperature(uint16_t adcValue) {
    // Conversion formula specific to your analog temperature sensor
    // Replace this with the actual conversion formula for the KY-013 sensor
    float voltage = (float)adcValue / 4095.0 * 3.3; // Assuming 12-bit ADC and 3.3V reference
    float temperature = voltage * 100.0; // Replace with your calibration factor
    return temperature;
}

void SystemClock_Config(void);

int main(void) {
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_ADC1_Init();

    HAL_ADC_Start(&hadc1);

    while (1) {
        HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
        uint16_t adcValue = HAL_ADC_GetValue(&hadc1);

        // Convert ADC value to temperature
        float temperature = convertToTemperature(adcValue);

        // Print temperature
        printf("Temperature: %.2f\n", temperature);

        HAL_Delay(500); // Adjust delay as needed
    }
}

void SystemClock_Config(void) {
    // Your clock configuration code here
}

void MX_ADC1_Init(void) {
    ADC_ChannelConfTypeDef sConfig = {0};

    __HAL_RCC_ADC1_CLK_ENABLE();

    /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
    */
    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.DiscontinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.NbrOfConversion = 1;
    hadc1.Init.DMAContinuousRequests = DISABLE;
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    if (HAL_ADC_Init(&hadc1) != HAL_OK) {
        Error_Handler();
    }

    /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
    */
    sConfig.Channel = ADC_CHANNEL_0; // Replace with the appropriate channel for your setup
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
        Error_Handler();
    }
}


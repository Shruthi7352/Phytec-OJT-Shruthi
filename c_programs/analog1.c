#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

// Simulated ADC reading function
int analogRead(int pin) {
    // Replace this with the actual ADC reading function provided by your RuggedBoard environment
    // For example, if the environment provides analogRead function, use it.
    // Otherwise, replace this with the appropriate ADC reading mechanism.
    // This is just a placeholder for demonstration purposes.
    return rand() % 1024;  // Simulating an ADC value between 0 and 1023
}

int main() {
    int adcValue;
    float R1 = 10000.0;
    float logR2, R2, T, K;
    float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

    while (1) {
        // Read ADC value from the analog pin
        adcValue = analogRead(73);  // Replace '73' with your actual analog pin

        // Calculate temperature
        R2 = R1 * (1023.0 / (float)adcValue - 1.0);
        logR2 = log(R2);
        K = 1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2);
        T = K - 273.15;

        // Print temperature to the console
        printf("The current temperature in Celsius: %.2f\r\n", T);

        // Delay for a while
        sleep(1);  // 1-second delay
    }

    return 0;
}

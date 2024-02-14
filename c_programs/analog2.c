#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Analog pin for temperature sensor
#define ANALOG_PIN 73

// GPIO pin for direction
#define GPIO_PIN 16 // Replace with the actual GPIO pin number

// Function to read ADC value from analog pin
int readADC(int analogPin) {
    // Open the analog input file for reading
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "/sys/class/hwmon/hwmon0/in%d_input", analogPin);

    int adcValue;
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening ADC file");
        exit(EXIT_FAILURE);
    }

    // Read the ADC value from the file
    fscanf(file, "%d", &adcValue);

    // Close the file
    fclose(file);

    return adcValue;
}

// Function to set GPIO direction
void setGPIODirection(int gpioPin, const char *direction) {
    // Open the GPIO direction file for writing
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "/sys/class/gpio/gpio%d/direction", gpioPin);

    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("Error opening GPIO direction file");
        exit(EXIT_FAILURE);
    }

    // Set the GPIO direction
    fprintf(file, "%s", direction);

    // Close the file
    fclose(file);
}

int main() {
    // Read ADC value from the analog temperature sensor
    int adcValue = readADC(ANALOG_PIN);
    printf("ADC Value: %d\r\n", adcValue);

    // Set GPIO pin direction (Replace "out" with "in" if you want INPUT)
    setGPIODirection(GPIO_PIN, "out");

    return 0;
}

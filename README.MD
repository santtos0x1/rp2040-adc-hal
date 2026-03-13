# RP2040 ADC Temperature HAL

A lightweight, bare-metal hardware abstraction layer (HAL) for the **RP2040** microcontroller, designed to monitor the internal temperature sensor.

This driver provides a clean interface to interact with hardware registers, abstracting low-level complexity. It is written in pure C and relies solely on standard C libraries, **requiring no external dependencies** (no Pico SDK required).

## Features
- **Zero-Dependency:** Runs on pure C with no external SDKs.
- **Modular Architecture:** Clean codebase separation, making it easy to integrate, read, and maintain.
- **Fixed-Point Arithmetic:** Optimized for performance by avoiding floating-point math, making it ideal for resource-constrained applications.

## Integration
To use this driver, simply include the header files in your project and ensure the RP2040 register definitions are accessible.

## Example Usage
```c
#include "thermal_manager.h"

int main() {
    // Initialize the thermal driver
    init_thermal_m();

    while(1) {
        // Retrieves temperature in milli-Celsius (e.g., 25000 = 25°C)
        uint32_t mcu_temp = get_thermal();
        
        // Handle logic...
    }
    return 0;
}

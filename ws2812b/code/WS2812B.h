#ifndef RPI_WS281X_WS2812B_H
#define RPI_WS281X_WS2812B_H

#include <stdint.h> // Include header file for integer types
#include <stdio.h> // Include header file for standard input/output
#include <stdlib.h> // Include header file for general utilities
#include <string.h> // Include header file for string handling
#include <unistd.h> // Include header file for Unix standard library
#include <sys/types.h> // Include header file for data types
#include <sys/stat.h> // Include header file for file information
#include <fcntl.h> // Include header file for file control options
#include <sys/mman.h> // Include header file for memory management
#include <signal.h> // Include header file for signal handling
#include <stdarg.h> // Include header file for handling variable argument lists
#include <getopt.h> // Include header file for command line option parsing

#include "clk.h" // Include header file for clock control
#include "gpio.h" // Include header file for GPIO control
#include "dma.h" // Include header file for DMA control
#include "pwm.h" // Include header file for PWM control
#include "version.h" // Include header file for version information

#include "ws2811.h" // Include header file for ws2811 library


// The following information is used to configure the ws2812b
#define TARGET_FREQ             WS2811_TARGET_FREQ // Define the triggering frequency
#define GPIO_PIN                18
#define DMA                     10
#define STRIP_TYPE              WS2811_STRIP_GBR // WS2812/SK6812RGB integrated chip+leds


#define LED_COUNT               100 // Define the number of LEDs
#define ARRAY_SIZE(stuff)       (sizeof(stuff) / sizeof(stuff[0])) // Macro for determining the size of an array

class WS2812B{
        public:
        int dotspos[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        ws2811_led_t dotcolors[8] = // Define an array of colors for the LEDs
        {
            0x00200000,  // red
                    0x00201000,  // orange
                    0x00202000,  // yellow
                    0x00002000,  // green
                    0x00002020,  // light blue
                    0x00000020,  // blue
                    0x00100010,  // purple
                    0x00200010,  // pink
        };
        /* Define colors */
        ws2811_led_t * matrix; // Pointer to an array of LED RGB values
        ws2811_t ledstring = // Define a structure for the ws2811 library
        {
            .freq = TARGET_FREQ, // Set the triggering frequency
            .dmanum = DMA, // Set the DMA number
            .channel =
                     {
                             [0] =
                                     {
                                             .gpionum = GPIO_PIN, // Set the GPIO pin
                                             .invert = 0,
                                             .count = LED_COUNT, // Set the number of LEDs
                                             .strip_type = STRIP_TYPE, // Set the LED strip type
                                             .brightness = 255, // Set the LED brightness
                                     },
                             [1] =
                                     {
                                             .gpionum = 0,
                                             .invert = 0,
                                             .count = 0,
                                             .brightness = 0,
                                     },
                     },
        };
        WS2812B(); // Constructor for WS2812B class
        int begin(); //
        int update(); // Function for updating the LED display
        int off(); // Function for turning off all LEDs
        void matrix_bottom(void); // Function for setting all LEDs to a specific lighting mode
};

#endif //RPI_WS281X_WS2812B_H

// Include header file WS2812B.h
#include "WS2812B.h" 

 // Include standard input/output stream library
#include <iostream>

 // Include header file for Unix standard library
#include <unistd.h>
using namespace std; // Use the standard namespace

int main() { // Main function
    WS2812B *ws2812b = new WS2812B(); 
    // Create an instance of WS2812B
    ws2812b->begin();
     // Initialize the WS2812B LEDs
    while (1) { 
        // Run the following code in an infinite loop
        ws2812b->matrix_bottom(); 
        // Set the LEDs to display a pattern
        ws2812b->update(); 
        // Update the LEDs with the new pattern
        usleep(1000000 / 15); 
        // Wait for 1/15th of a second
    }
}

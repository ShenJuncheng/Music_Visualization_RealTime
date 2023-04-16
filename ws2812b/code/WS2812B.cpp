#include "WS2812B.h" // Include header file WS2812B.h

WS2812B::WS2812B() {
    matrix = (ws2811_led_t *) malloc(sizeof(ws2811_led_t) * LED_COUNT); // Allocate memory for the LED buffer
}

int WS2812B::begin() {
    ws2811_return_t ret;
    /* Initialize ws2812b */
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS) { // If ws2811_init failed, print the error message and return the error code
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
}

/* Set all LED lights according to a specific lighting mode */
void WS2812B::matrix_bottom(void) {
    int i;

    for (i = 0; i < LED_COUNT; i++) { // Set each LED to display a random color from the dotcolors array
        matrix[i] = dotcolors[rand() % (sizeof(dotcolors) / sizeof(dotcolors[0]))];
    }
}

int WS2812B::update() {
    /* Update the LED display state */
    int loop = 0;
    /* Refresh bgr values to the LED buffer */
    for (loop = 0; loop < LED_COUNT; loop++) {
        ledstring.channel[0].leds[loop] = matrix[loop]; /* Configure the contents of the buffer to the WS2812 configuration space */
    }
    ws2811_return_t ret;
    /* Update the LED display */
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS) { // If ws2811_render failed, print the error message and return the error code
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
}

int WS2812B::off() {
    /* Turn off all LEDs */
    int loop = 0;
    for (loop = 0; loop < LED_COUNT; loop++) {
        matrix[loop] = 0; // Set each LED to off
    }
    update(); // Update the LED display with the off values
}

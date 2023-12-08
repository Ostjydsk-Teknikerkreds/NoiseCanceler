/*******************************************************************************
 * @file main.cpp
 * @date 2023-08-31
 * @author Markus Rytter (markus.r@live.dk)
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/

#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();
    
    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }

    return 0;
}
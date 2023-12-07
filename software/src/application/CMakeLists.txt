set(MODULE NoiseCanceler)

add_executable (${MODULE}
    main.cpp
)

target_link_libraries(${MODULE}
PUBLIC
PRIVATE
    pico_stdlib
    hardware_adc
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${MODULE})

# Enable USB serial
pico_enable_stdio_usb(${MODULE} 1)
pico_enable_stdio_uart(${MODULE} 0)
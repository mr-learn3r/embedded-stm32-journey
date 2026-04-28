# Week 0 - Bare Metal Blink

## Objective:Blinks LED (PC6) on STM32F072B-DISCO using direct register writes. Zero HAL/CubeMX.

## Registers used
- RCC_AHBENR (0x40021000 + 0x14): bit 19 enables GPIOC clock
- GPIOC_MODER (0x48000800 + 0x00): bits 13:12 = 01 sets PC6 as output
- GPIOC_ODR (0x48000800 + 0x14): bit 6 toggles PC6 HIGH/LOW

## Build & Flash
make        # build
make flash  # flash to board

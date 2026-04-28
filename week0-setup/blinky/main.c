#include <stdint.h>

#define RCC_BASE    0x40021000
#define GPIOC_BASE  0x48000800

#define RCC_AHBENR  *((volatile uint32_t *) (RCC_BASE + 0x14))
#define GPIOC_MODER *((volatile uint32_t *) (GPIOC_BASE + 0x00))
#define GPIOC_ODR   *((volatile uint32_t *) (GPIOC_BASE + 0x14))

void delay(volatile uint32_t count) {
    while(count--);
}

int main(){

    //Step 1: Enable GPIO clock
    RCC_AHBENR |= (1U << 19);
    
    //Step 2: Set GPIO Port C pin 6 in output mode
    GPIOC_MODER &= ~(3U << 12);
    GPIOC_MODER |= (1U << 12);

    while(1){
        //Step 3: Toggle LED on GPIO port c pin 6
        GPIOC_ODR |= (1U <<6);
        delay(20000);
        GPIOC_ODR &= ~(1U <<6);
        delay(20000);
    }

    return 0;
}
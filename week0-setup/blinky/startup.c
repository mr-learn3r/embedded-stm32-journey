#include <stdint.h>

// Forward declaration of main()
int main(void);

// Extern stack top from linker script
extern uint32_t _estack;

//Reset handler
void Reset_Handler(void){
    main();
    while(1);
}

__attribute__((section(".isr_vector")))
uint32_t vector_table []={
    (uint32_t)&_estack,
    (uint32_t)&Reset_Handler
};
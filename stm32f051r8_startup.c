#include "main.h"

extern unsigned long _data_flash;
extern unsigned long _data_begin;
extern unsigned long _data_end;
extern unsigned long _bss_begin;
extern unsigned long _bss_end;
extern unsigned long _stack_end;

void handler_default(void)
{
    while (1)
    {
    //loop
    }
}
void handler_reset(void){
    unsigned long *source;
    unsigned long *destination;

    source = &_data_flash;
    for(destination = &_data_begin; destination < &_data_end;)
        *(destination++) = *(source++);
    
    for(destination = &_bss_begin; destination < &_bss_end;)
        *(destination++) = 0;
    main();
}

__attribute__ ((section(".interrupt_vector")))
void (* const table_interrupt_vector[])(void) =
{
    (void *) &_stack_end, // 0 - stack
    handler_reset, // 1
    handler_default, // 2
    handler_default, // 3
    handler_default, // 4
    handler_default, // 5
    handler_default, // 6
    0, // 7
    0, // 8
    0, // 9
    0, // 10
    handler_default, // 11
    handler_default, // 12
    0, // 13
    handler_default, // 14
    handler_default, // 15
    // peripherals
    handler_default, // 0
    handler_default, // 1
    handler_default, // 2
    handler_default, // 3
    handler_default, // 4
    //
    handler_default, // 59
    handler_default // 60
};
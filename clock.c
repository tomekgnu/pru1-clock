#include <stdint.h>
#include <stdbool.h>
#include "resource_table_empty.h"
#include <pru_cfg.h>
#include <stdint.h>
#include "prugpio.h"

// Offset to PRU 0 AND PRU1 DRAM
#define PRU1_DRAM               0x00000
#define PRU0_DRAM               PRU1_DRAM + 8192
#define BUF_SIZE                1024
#define AUDIO_CLOCK_STATE       0
#define AUDIO_CLOCK_PIN         P8_46

volatile register uint32_t __R30;
volatile int16_t *shared_mem = (int16_t *) 0x00010000;
volatile uint16_t *info = (uint16_t *)(0x00010000 + 2);
extern my_delay_cycles(uint32_t);

int main(void)
{


    //Set the CFG Register to direct output instead of serial output
    CT_CFG.GPCFG0 = 0;
    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
   // *flags = 0xFFFFFFFF;
    __R30 = 0x00000000;

    while(1){
        __R30 |= AUDIO_CLOCK_PIN;
        info[AUDIO_CLOCK_STATE] = 1; //info[AUDIO_CLOCK_STATE] = 1;
        my_delay_cycles(2261);
        __R30 &= ~AUDIO_CLOCK_PIN;
        info[AUDIO_CLOCK_STATE] = 0; //info[AUDIO_CLOCK_STATE] = 0;
        my_delay_cycles(2264);

    }

    __halt();
}

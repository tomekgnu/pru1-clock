#include <stdint.h>
#include <stdbool.h>
#include "resource_table_empty.h"
#include <pru_cfg.h>
#include <stdint.h>
#include "prugpio.h"

// Offset to PRU 0 AND PRU1 DRAM
#define PRU1_DRAM       0x00000
#define PRU0_DRAM       PRU1_DRAM + 8192

#define P8_46           (1 << 1)
#define CLOCK             P8_46

volatile register uint32_t __R30;
volatile register uint32_t __R31;

volatile uint32_t value = 0x13131313;   // 0046
volatile uint32_t *pru0_dram = (uint32_t*) (PRU1_DRAM + 0x2000 + 0x200);
volatile uint32_t *shared_mem = (uint32_t*) 0x00010000;

extern my_delay_cycles(uint32_t);

int main(void)
{

    //volatile uint32_t *flags = pru0_dram;
    //Set the CFG Register to direct output instead of serial output
    CT_CFG.GPCFG0 = 0;
    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
   // *flags = 0xFFFFFFFF;
    __R30 = 0x00000000;

    while(1){
        __R30 |= CLOCK;
        shared_mem[0] = 1;
        my_delay_cycles(2261);
        __R30 &= ~CLOCK;
        shared_mem[0] = 0;
        my_delay_cycles(2264);

    }

    __halt();
}

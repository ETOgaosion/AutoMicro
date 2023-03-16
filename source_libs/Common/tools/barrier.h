#pragma once

#define rmb() __asm__ __volatile__("lfence": : :"memory") 
#define wmb() __asm__ __volatile__("sfence": : :"memory") 
#define mb() __asm__ __volatile__("mfence": : :"memory") 
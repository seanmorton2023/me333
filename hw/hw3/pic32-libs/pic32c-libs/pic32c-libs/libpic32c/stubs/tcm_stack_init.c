/*-------------------------------------------------------------------------
 * XC PIC32C Data Initialization
 *
 * Copyright (c) 2017, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 *
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above
 *         copyright notice, this list of conditions and the following
 *         disclaimer in the documentation and/or other materials provided
 *         with the distribution.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written
 *         permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#if defined(__ARM_ARCH_7EM__)
#include <stdint.h>

///\ to be provided by our the linker
extern uint32_t _sdtcm_stack;       ///\ stack start (DTCM)
extern uint32_t _min_stack_size;    ///\ stack size
extern uint32_t _stack;             ///\ stack in RAM

#define SRAM_STACK_BASE     ((void *)(&_stack - &_min_stack_size))
#define DTCM_STACK_BASE     ((void *)(&_sdtcm_stack - &_min_stack_size))
#define SRAM_STACK_LIMIT    ((void *)(&_stack))
#define DTCM_STACK_LIMIT    ((void *)(&_sdtcm_stack))


/** \brief  Get Main Stack Pointer
 
 This function returns the current value of the Main Stack Pointer (MSP).
 
 \return               MSP Register value
 */
__attribute__( ( always_inline ) ) static inline uint32_t __get_MSP(void)
{
    register uint32_t result;
    
    __asm volatile ("MRS %0, msp\n" : "=r" (result) );
    return(result);
}


/** \brief  Set Main Stack Pointer
 
 This function assigns the given value to the Main Stack Pointer (MSP).
 
 \param [in]    topOfMainStack  Main Stack Pointer value to set
 */
__attribute__( ( always_inline ) ) static inline void __set_MSP(uint32_t topOfMainStack)
{
    __asm volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) : "sp");
}


/** \brief  Get GCC Frame Pointer
 
 This function returns the current value of the GCC Frame Pointer (r7).
 
 \return               r7 Register value
 */
__attribute__( ( always_inline ) ) static inline uint32_t __get_MFP(void)
{
    register uint32_t result;
    
    __asm volatile ("MOV %0, r7 \n" : "=r" (result) );
    return(result);
}


/** \brief  Set GCC Frame Pointer
 
 This function assigns the given value to the GCC Frame Pointer (r7).
 
 \param [in]    topOfMainStack  GCC Frame Pointer value to set
 */
__attribute__( ( always_inline ) ) static inline void __set_MFP(uint32_t topOfMainStack)
{
    __asm volatile ("MOV r7, %0 \n" : : "r" (topOfMainStack) );
}



/** \brief  Change stack's location to DTCM
 
 The function changes the stack's location from SRAM to DTCM
 */
void __pic32c_TCM_StackInit();
void __pic32c_TCM_StackInit()
{
    static uint32_t offset;
    volatile static char *dst;
    volatile static char *src;
    static uint8_t* frame_pointer;
    static volatile char *cur_sp;
    
    offset     = (uint32_t)SRAM_STACK_LIMIT - (uint32_t)DTCM_STACK_LIMIT;
    dst  = (volatile char *)DTCM_STACK_LIMIT;
    src  = (volatile char *)SRAM_STACK_LIMIT;
    cur_sp = (volatile char *)__get_MSP();
    
    /* copy stack data from SRAM to DTCM */
    while ((src > (volatile char *)cur_sp))
    {
        *--dst = *--src;
    }
    __set_MSP(__get_MSP() - offset);
    
    frame_pointer = (uint8_t*)__get_MFP();
    
    ///\ r7 is used as frame pointer
    if (frame_pointer > (uint8_t*)SRAM_STACK_LIMIT)
        __set_MFP((uint32_t)(frame_pointer - offset));
}

#else /* __ARM_ARCH_7EM__ */

#ifndef __DISABLE_WARNINGS__
char __attribute__((section(".gnu.warning.__tcm_stack_init")))
__warning_pic32c_TCM_StackInit[] = "Linking __pic32_TCM_StackInit() but this feature is not supported for the selected target device";
#endif

void __pic32c_TCM_StackInit();
void __pic32c_TCM_StackInit()
{
  return;
}

#endif /* __ARM_ARCH_7EM__ */

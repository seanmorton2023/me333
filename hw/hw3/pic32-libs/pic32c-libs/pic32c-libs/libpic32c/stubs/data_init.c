/**
 * \file
 *
 * \brief MPLAB XC32 data initialization for SAM/PIC32C devices
 *
 * Copyright (c) 2018, Microchip Technology Inc. and its subsidiaries ("Microchip")
 *
 * \license_start
 *
 * \page License
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \license_stop
 *
 */

#include <stdint.h>

uint32_t __attribute__((weak)) _dinit_addr = 0;

extern uint8_t __attribute__((weak)) _sbss;
extern uint8_t __attribute__((weak)) _ebss;

void __pic32c_data_initialization(void)
{
    uint32_t       *pDinit;
    uint8_t        *pCopyVal, *pDst;
    uint32_t       sec_size, is_initialized;
    uint32_t       i;
    uint8_t        *pSrc;
    const uint8_t  *pEnd;
    
    /* Clear COMMON section mapped to BSS in linker script. */
    pEnd = (uint8_t*) &_ebss;
    for (pSrc = (uint8_t*) &_sbss; pSrc < pEnd; ++pSrc)
        *pSrc = 0;

    ///\ init pDinit with .dinit section address
    pDinit = &_dinit_addr;
    
    ///\ check the destination address
    while ((*pDinit != 0) || (*(pDinit+1) != 0))
    {
        ///\ take the destination address
        pDst = (uint8_t*)*pDinit;
        pDinit++;
        ///\ take the size of the section that should be copied
        sec_size = *pDinit;
        pDinit++;
        ///\ is initialized data(PROGBITS) or
        ///\ uninitialized data (NOBITS - like .bss)
        is_initialized = *pDinit;
        pDinit++;
        
        if (is_initialized)
        {
            ///\ if it is an initialized section, the data to be copied
            ///\ is in .dinit
            pCopyVal = (uint8_t*)pDinit;
            
            for (i = 0; i < sec_size; i++)
                *pDst++ = *pCopyVal++;
            
            ///\ update pDinit
            ///\ if sec_size is not a multiple of 4,
            ///\ the .dinit section is padded with 0,
            ///\ so that the address of the next section to be copied
            ///\ is 4-byte aligned
            pDinit += (sec_size/4 + (((sec_size%4) != 0)? 1:0));
        }
        else
        {
            ///\ uninitialized sections are filled with 0x0
            for (i = 0; i < sec_size; i++)
                *pDst++ = 0;
        }
    }
}

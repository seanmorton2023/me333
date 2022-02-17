 /**
 * \file
 *
 * \brief MPLAB XC32 header file for SAM/PIC32C devices
 *
 * Copyright (c) 2019, Microchip Technology Inc. and its subsidiaries ("Microchip")
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

#pragma once
#ifndef __XC_PIC32C_H
#define __XC_PIC32C_H

/* CEC */
#if defined(__CEC1702__)
#  include "proc/CEC/MCHP_CEC1702.h"

/* DEC15xx */
#elif defined(__DEC1501H_B0_Z2__)
#  include "proc/DEC15xx/dec1501h_b0_z2.h"
#elif defined(__DEC1515H_D0_Z2__)
#  include "proc/DEC15xx/dec1515h_d0_z2.h"

/* MEC15xx */
#elif defined(__MEC1501H_B0_SZ__)
#  include "proc/MEC15xx/mec1501h_b0_sz.h"
#elif defined(__MEC1501H_B0_TF__)
#  include "proc/MEC15xx/mec1501h_b0_tf.h"
#elif defined(__MEC1501H_B0_Z2__)
#  include "proc/MEC15xx/mec1501h_b0_z2.h"
#elif defined(__MEC1503__)
#  include "proc/MEC15xx/mec1503.h"
#elif defined(__MEC1503H_L1_3Y__)
#  include "proc/MEC15xx/mec1503h_l1_3y.h"
#elif defined(__MEC1503H_L1_SZ__)
#  include "proc/MEC15xx/mec1503h_l1_sz.h"
#elif defined(__MEC1507H_B0_SZ__)
#  include "proc/MEC15xx/mec1507h_b0_sz.h"
#elif defined(__MEC1507H_B0_TF__)
#  include "proc/MEC15xx/mec1507h_b0_tf.h"
#elif defined(__MEC1515H_D0_NB__)
#  include "proc/MEC15xx/mec1515h_d0_nb.h"

/* MEC17 */
#elif defined(__MEC1701H__)
#  include "proc/MEC17/mec1701h.h"
#elif defined(__MEC1701Q__)
#  include "proc/MEC17/mec1701q.h"
#elif defined(__MEC1703K__)
#  include "proc/MEC17/mec1703k.h"
#elif defined(__MEC1703Q__)
#  include "proc/MEC17/mec1703q.h"
#elif defined(__MEC1704Q__)
#  include "proc/MEC17/mec1704q.h"
#elif defined(__MEC1705Q__)
#  include "proc/MEC17/mec1705q.h"

/* PIC32CM */
#elif defined(__PIC32CM1216JH00032__) || defined(__32CM1216JH00032__)
#  include "proc/PIC32CM/pic32cm1216jh00032.h"
#elif defined(__PIC32CM1216JH00048__) || defined(__32CM1216JH00048__)
#  include "proc/PIC32CM/pic32cm1216jh00048.h"
#elif defined(__PIC32CM1216JH00064__) || defined(__32CM1216JH00064__)
#  include "proc/PIC32CM/pic32cm1216jh00064.h"
#elif defined(__PIC32CM1216JH00100__) || defined(__32CM1216JH00100__)
#  include "proc/PIC32CM/pic32cm1216jh00100.h"
#elif defined(__PIC32CM1216JH01032__) || defined(__32CM1216JH01032__)
#  include "proc/PIC32CM/pic32cm1216jh01032.h"
#elif defined(__PIC32CM1216JH01048__) || defined(__32CM1216JH01048__)
#  include "proc/PIC32CM/pic32cm1216jh01048.h"
#elif defined(__PIC32CM1216JH01064__) || defined(__32CM1216JH01064__)
#  include "proc/PIC32CM/pic32cm1216jh01064.h"
#elif defined(__PIC32CM1216JH01100__) || defined(__32CM1216JH01100__)
#  include "proc/PIC32CM/pic32cm1216jh01100.h"
#elif defined(__PIC32CM1216JH24032__) || defined(__32CM1216JH24032__)
#  include "proc/PIC32CM/pic32cm1216jh24032.h"
#elif defined(__PIC32CM1216JH24048__) || defined(__32CM1216JH24048__)
#  include "proc/PIC32CM/pic32cm1216jh24048.h"
#elif defined(__PIC32CM1216JH24064__) || defined(__32CM1216JH24064__)
#  include "proc/PIC32CM/pic32cm1216jh24064.h"
#elif defined(__PIC32CM1216JH24100__) || defined(__32CM1216JH24100__)
#  include "proc/PIC32CM/pic32cm1216jh24100.h"
#elif defined(__PIC32CM2532JH00032__) || defined(__32CM2532JH00032__)
#  include "proc/PIC32CM/pic32cm2532jh00032.h"
#elif defined(__PIC32CM2532JH00048__) || defined(__32CM2532JH00048__)
#  include "proc/PIC32CM/pic32cm2532jh00048.h"
#elif defined(__PIC32CM2532JH00064__) || defined(__32CM2532JH00064__)
#  include "proc/PIC32CM/pic32cm2532jh00064.h"
#elif defined(__PIC32CM2532JH00100__) || defined(__32CM2532JH00100__)
#  include "proc/PIC32CM/pic32cm2532jh00100.h"
#elif defined(__PIC32CM2532JH01032__) || defined(__32CM2532JH01032__)
#  include "proc/PIC32CM/pic32cm2532jh01032.h"
#elif defined(__PIC32CM2532JH01048__) || defined(__32CM2532JH01048__)
#  include "proc/PIC32CM/pic32cm2532jh01048.h"
#elif defined(__PIC32CM2532JH01064__) || defined(__32CM2532JH01064__)
#  include "proc/PIC32CM/pic32cm2532jh01064.h"
#elif defined(__PIC32CM2532JH01100__) || defined(__32CM2532JH01100__)
#  include "proc/PIC32CM/pic32cm2532jh01100.h"
#elif defined(__PIC32CM2532JH24032__) || defined(__32CM2532JH24032__)
#  include "proc/PIC32CM/pic32cm2532jh24032.h"
#elif defined(__PIC32CM2532JH24048__) || defined(__32CM2532JH24048__)
#  include "proc/PIC32CM/pic32cm2532jh24048.h"
#elif defined(__PIC32CM2532JH24064__) || defined(__32CM2532JH24064__)
#  include "proc/PIC32CM/pic32cm2532jh24064.h"
#elif defined(__PIC32CM2532JH24100__) || defined(__32CM2532JH24100__)
#  include "proc/PIC32CM/pic32cm2532jh24100.h"
#elif defined(__PIC32CM5164JH00032__) || defined(__32CM5164JH00032__)
#  include "proc/PIC32CM/pic32cm5164jh00032.h"
#elif defined(__PIC32CM5164JH00048__) || defined(__32CM5164JH00048__)
#  include "proc/PIC32CM/pic32cm5164jh00048.h"
#elif defined(__PIC32CM5164JH00064__) || defined(__32CM5164JH00064__)
#  include "proc/PIC32CM/pic32cm5164jh00064.h"
#elif defined(__PIC32CM5164JH00100__) || defined(__32CM5164JH00100__)
#  include "proc/PIC32CM/pic32cm5164jh00100.h"
#elif defined(__PIC32CM5164JH00100_FPGA__) || defined(__32CM5164JH00100_FPGA__)
#  include "proc/PIC32CM/pic32cm5164jh00100_fpga.h"
#elif defined(__PIC32CM5164JH01032__) || defined(__32CM5164JH01032__)
#  include "proc/PIC32CM/pic32cm5164jh01032.h"
#elif defined(__PIC32CM5164JH01048__) || defined(__32CM5164JH01048__)
#  include "proc/PIC32CM/pic32cm5164jh01048.h"
#elif defined(__PIC32CM5164JH01064__) || defined(__32CM5164JH01064__)
#  include "proc/PIC32CM/pic32cm5164jh01064.h"
#elif defined(__PIC32CM5164JH01100__) || defined(__32CM5164JH01100__)
#  include "proc/PIC32CM/pic32cm5164jh01100.h"
#elif defined(__PIC32CM5164JH24032__) || defined(__32CM5164JH24032__)
#  include "proc/PIC32CM/pic32cm5164jh24032.h"
#elif defined(__PIC32CM5164JH24048__) || defined(__32CM5164JH24048__)
#  include "proc/PIC32CM/pic32cm5164jh24048.h"
#elif defined(__PIC32CM5164JH24064__) || defined(__32CM5164JH24064__)
#  include "proc/PIC32CM/pic32cm5164jh24064.h"
#elif defined(__PIC32CM5164JH24100__) || defined(__32CM5164JH24100__)
#  include "proc/PIC32CM/pic32cm5164jh24100.h"

/* PIC32CX-SG */
#elif defined(__PIC32CX0525SG12084__) || defined(__32CX0525SG12084__)
#  include "proc/PIC32CX-SG/pic32cx0525sg12084.h"
#elif defined(__PIC32CX0525SG12144__) || defined(__32CX0525SG12144__)
#  include "proc/PIC32CX-SG/pic32cx0525sg12144.h"

/* PIC32CZ-CA */
#elif defined(__PIC32CZ8110CA90208__) || defined(__32CZ8110CA90208__)
#  include "proc/PIC32CZ-CA/pic32cz8110ca90208.h"
#elif defined(__PIC32CZ8110CA90208_FPGA__) || defined(__32CZ8110CA90208_FPGA__)
#  include "proc/PIC32CZ-CA/pic32cz8110ca90208_fpga.h"
#elif defined(__PIC32CZ8110CA90208S1__) || defined(__32CZ8110CA90208S1__)
#  include "proc/PIC32CZ-CA/pic32cz8110ca90208s1.h"
#elif defined(__PIC32CZ8110CA90208S1_FPGA__) || defined(__32CZ8110CA90208S1_FPGA__)
#  include "proc/PIC32CZ-CA/pic32cz8110ca90208s1_fpga.h"

/* PIC32CZ-DA */
#elif defined(__PIC32CZ1038DA70100__) || defined(__32CZ1038DA70100__)
#  include "proc/PIC32CZ-DA/pic32cz1038da70100.h"
#elif defined(__PIC32CZ1038DA70128__) || defined(__32CZ1038DA70128__)
#  include "proc/PIC32CZ-DA/pic32cz1038da70128.h"
#elif defined(__PIC32CZ1038DA71144__) || defined(__32CZ1038DA71144__)
#  include "proc/PIC32CZ-DA/pic32cz1038da71144.h"
#elif defined(__PIC32CZ1038DA71176__) || defined(__32CZ1038DA71176__)
#  include "proc/PIC32CZ-DA/pic32cz1038da71176.h"
#elif defined(__PIC32CZ1038DA72176__) || defined(__32CZ1038DA72176__)
#  include "proc/PIC32CZ-DA/pic32cz1038da72176.h"
#elif defined(__PIC32CZ1038DA72216__) || defined(__32CZ1038DA72216__)
#  include "proc/PIC32CZ-DA/pic32cz1038da72216.h"
#elif defined(__PIC32CZ1038DA75144__) || defined(__32CZ1038DA75144__)
#  include "proc/PIC32CZ-DA/pic32cz1038da75144.h"
#elif defined(__PIC32CZ1038DA75176__) || defined(__32CZ1038DA75176__)
#  include "proc/PIC32CZ-DA/pic32cz1038da75176.h"
#elif defined(__PIC32CZ1038DA78144__) || defined(__32CZ1038DA78144__)
#  include "proc/PIC32CZ-DA/pic32cz1038da78144.h"
#elif defined(__PIC32CZ1038DA78176__) || defined(__32CZ1038DA78176__)
#  include "proc/PIC32CZ-DA/pic32cz1038da78176.h"
#elif defined(__PIC32CZ5138DA70100__) || defined(__32CZ5138DA70100__)
#  include "proc/PIC32CZ-DA/pic32cz5138da70100.h"
#elif defined(__PIC32CZ5138DA70128__) || defined(__32CZ5138DA70128__)
#  include "proc/PIC32CZ-DA/pic32cz5138da70128.h"
#elif defined(__PIC32CZ5138DA71144__) || defined(__32CZ5138DA71144__)
#  include "proc/PIC32CZ-DA/pic32cz5138da71144.h"
#elif defined(__PIC32CZ5138DA71176__) || defined(__32CZ5138DA71176__)
#  include "proc/PIC32CZ-DA/pic32cz5138da71176.h"
#elif defined(__PIC32CZ5138DA72176__) || defined(__32CZ5138DA72176__)
#  include "proc/PIC32CZ-DA/pic32cz5138da72176.h"
#elif defined(__PIC32CZ5138DA72216__) || defined(__32CZ5138DA72216__)
#  include "proc/PIC32CZ-DA/pic32cz5138da72216.h"
#elif defined(__PIC32CZ5138DA75144__) || defined(__32CZ5138DA75144__)
#  include "proc/PIC32CZ-DA/pic32cz5138da75144.h"
#elif defined(__PIC32CZ5138DA75176__) || defined(__32CZ5138DA75176__)
#  include "proc/PIC32CZ-DA/pic32cz5138da75176.h"
#elif defined(__PIC32CZ5138DA78144__) || defined(__32CZ5138DA78144__)
#  include "proc/PIC32CZ-DA/pic32cz5138da78144.h"
#elif defined(__PIC32CZ5138DA78176__) || defined(__32CZ5138DA78176__)
#  include "proc/PIC32CZ-DA/pic32cz5138da78176.h"

/* SAMA5D2 */
#elif defined(__SAMA5D21__) || defined(__ATSAMA5D21__)
#  include "proc/SAMA5D2/sama5d21.h"
#elif defined(__SAMA5D22__) || defined(__ATSAMA5D22__)
#  include "proc/SAMA5D2/sama5d22.h"
#elif defined(__SAMA5D23__) || defined(__ATSAMA5D23__)
#  include "proc/SAMA5D2/sama5d23.h"
#elif defined(__SAMA5D24__) || defined(__ATSAMA5D24__)
#  include "proc/SAMA5D2/sama5d24.h"
#elif defined(__SAMA5D26__) || defined(__ATSAMA5D26__)
#  include "proc/SAMA5D2/sama5d26.h"
#elif defined(__SAMA5D27__) || defined(__ATSAMA5D27__)
#  include "proc/SAMA5D2/sama5d27.h"
#elif defined(__SAMA5D28__) || defined(__ATSAMA5D28__)
#  include "proc/SAMA5D2/sama5d28.h"

/* SAMC20 */
#elif defined(__SAMC20E15A__) || defined(__ATSAMC20E15A__)
#  include "proc/SAMC20/samc20e15a.h"
#elif defined(__SAMC20E16A__) || defined(__ATSAMC20E16A__)
#  include "proc/SAMC20/samc20e16a.h"
#elif defined(__SAMC20E17A__) || defined(__ATSAMC20E17A__)
#  include "proc/SAMC20/samc20e17a.h"
#elif defined(__SAMC20E18A__) || defined(__ATSAMC20E18A__)
#  include "proc/SAMC20/samc20e18a.h"
#elif defined(__SAMC20G15A__) || defined(__ATSAMC20G15A__)
#  include "proc/SAMC20/samc20g15a.h"
#elif defined(__SAMC20G16A__) || defined(__ATSAMC20G16A__)
#  include "proc/SAMC20/samc20g16a.h"
#elif defined(__SAMC20G17A__) || defined(__ATSAMC20G17A__)
#  include "proc/SAMC20/samc20g17a.h"
#elif defined(__SAMC20G18A__) || defined(__ATSAMC20G18A__)
#  include "proc/SAMC20/samc20g18a.h"
#elif defined(__SAMC20J15A__) || defined(__ATSAMC20J15A__)
#  include "proc/SAMC20/samc20j15a.h"
#elif defined(__SAMC20J16A__) || defined(__ATSAMC20J16A__)
#  include "proc/SAMC20/samc20j16a.h"
#elif defined(__SAMC20J17A__) || defined(__ATSAMC20J17A__)
#  include "proc/SAMC20/samc20j17a.h"
#elif defined(__SAMC20J17AU__) || defined(__ATSAMC20J17AU__)
#  include "proc/SAMC20/samc20j17au.h"
#elif defined(__SAMC20J18A__) || defined(__ATSAMC20J18A__)
#  include "proc/SAMC20/samc20j18a.h"
#elif defined(__SAMC20J18AU__) || defined(__ATSAMC20J18AU__)
#  include "proc/SAMC20/samc20j18au.h"

/* SAMC20N */
#elif defined(__SAMC20N17A__) || defined(__ATSAMC20N17A__)
#  include "proc/SAMC20N/samc20n17a.h"
#elif defined(__SAMC20N18A__) || defined(__ATSAMC20N18A__)
#  include "proc/SAMC20N/samc20n18a.h"

/* SAMC21 */
#elif defined(__SAMC21E15A__) || defined(__ATSAMC21E15A__)
#  include "proc/SAMC21/samc21e15a.h"
#elif defined(__SAMC21E16A__) || defined(__ATSAMC21E16A__)
#  include "proc/SAMC21/samc21e16a.h"
#elif defined(__SAMC21E17A__) || defined(__ATSAMC21E17A__)
#  include "proc/SAMC21/samc21e17a.h"
#elif defined(__SAMC21E18A__) || defined(__ATSAMC21E18A__)
#  include "proc/SAMC21/samc21e18a.h"
#elif defined(__SAMC21G15A__) || defined(__ATSAMC21G15A__)
#  include "proc/SAMC21/samc21g15a.h"
#elif defined(__SAMC21G16A__) || defined(__ATSAMC21G16A__)
#  include "proc/SAMC21/samc21g16a.h"
#elif defined(__SAMC21G17A__) || defined(__ATSAMC21G17A__)
#  include "proc/SAMC21/samc21g17a.h"
#elif defined(__SAMC21G18A__) || defined(__ATSAMC21G18A__)
#  include "proc/SAMC21/samc21g18a.h"
#elif defined(__SAMC21J15A__) || defined(__ATSAMC21J15A__)
#  include "proc/SAMC21/samc21j15a.h"
#elif defined(__SAMC21J16A__) || defined(__ATSAMC21J16A__)
#  include "proc/SAMC21/samc21j16a.h"
#elif defined(__SAMC21J17A__) || defined(__ATSAMC21J17A__)
#  include "proc/SAMC21/samc21j17a.h"
#elif defined(__SAMC21J17AU__) || defined(__ATSAMC21J17AU__)
#  include "proc/SAMC21/samc21j17au.h"
#elif defined(__SAMC21J18A__) || defined(__ATSAMC21J18A__)
#  include "proc/SAMC21/samc21j18a.h"
#elif defined(__SAMC21J18AU__) || defined(__ATSAMC21J18AU__)
#  include "proc/SAMC21/samc21j18au.h"

/* SAMC21N */
#elif defined(__SAMC21N17A__) || defined(__ATSAMC21N17A__)
#  include "proc/SAMC21N/samc21n17a.h"
#elif defined(__SAMC21N18A__) || defined(__ATSAMC21N18A__)
#  include "proc/SAMC21N/samc21n18a.h"

/* SAMD20 */
#elif defined(__SAMD20E14__) || defined(__ATSAMD20E14__)
#  include "proc/SAMD20/samd20e14.h"
#elif defined(__SAMD20E15__) || defined(__ATSAMD20E15__)
#  include "proc/SAMD20/samd20e15.h"
#elif defined(__SAMD20E16__) || defined(__ATSAMD20E16__)
#  include "proc/SAMD20/samd20e16.h"
#elif defined(__SAMD20E17__) || defined(__ATSAMD20E17__)
#  include "proc/SAMD20/samd20e17.h"
#elif defined(__SAMD20E18__) || defined(__ATSAMD20E18__)
#  include "proc/SAMD20/samd20e18.h"
#elif defined(__SAMD20G14__) || defined(__ATSAMD20G14__)
#  include "proc/SAMD20/samd20g14.h"
#elif defined(__SAMD20G15__) || defined(__ATSAMD20G15__)
#  include "proc/SAMD20/samd20g15.h"
#elif defined(__SAMD20G16__) || defined(__ATSAMD20G16__)
#  include "proc/SAMD20/samd20g16.h"
#elif defined(__SAMD20G17__) || defined(__ATSAMD20G17__)
#  include "proc/SAMD20/samd20g17.h"
#elif defined(__SAMD20G17U__) || defined(__ATSAMD20G17U__)
#  include "proc/SAMD20/samd20g17u.h"
#elif defined(__SAMD20G18__) || defined(__ATSAMD20G18__)
#  include "proc/SAMD20/samd20g18.h"
#elif defined(__SAMD20G18U__) || defined(__ATSAMD20G18U__)
#  include "proc/SAMD20/samd20g18u.h"
#elif defined(__SAMD20J14__) || defined(__ATSAMD20J14__)
#  include "proc/SAMD20/samd20j14.h"
#elif defined(__SAMD20J15__) || defined(__ATSAMD20J15__)
#  include "proc/SAMD20/samd20j15.h"
#elif defined(__SAMD20J16__) || defined(__ATSAMD20J16__)
#  include "proc/SAMD20/samd20j16.h"
#elif defined(__SAMD20J17__) || defined(__ATSAMD20J17__)
#  include "proc/SAMD20/samd20j17.h"
#elif defined(__SAMD20J18__) || defined(__ATSAMD20J18__)
#  include "proc/SAMD20/samd20j18.h"

/* SAMD20B */
#elif defined(__SAMD20E14B__) || defined(__ATSAMD20E14B__)
#  include "proc/SAMD20B/samd20e14b.h"
#elif defined(__SAMD20E15B__) || defined(__ATSAMD20E15B__)
#  include "proc/SAMD20B/samd20e15b.h"
#elif defined(__SAMD20E16B__) || defined(__ATSAMD20E16B__)
#  include "proc/SAMD20B/samd20e16b.h"
#elif defined(__SAMD20G14B__) || defined(__ATSAMD20G14B__)
#  include "proc/SAMD20B/samd20g14b.h"
#elif defined(__SAMD20G15B__) || defined(__ATSAMD20G15B__)
#  include "proc/SAMD20B/samd20g15b.h"
#elif defined(__SAMD20G16B__) || defined(__ATSAMD20G16B__)
#  include "proc/SAMD20B/samd20g16b.h"
#elif defined(__SAMD20J14B__) || defined(__ATSAMD20J14B__)
#  include "proc/SAMD20B/samd20j14b.h"
#elif defined(__SAMD20J15B__) || defined(__ATSAMD20J15B__)
#  include "proc/SAMD20B/samd20j15b.h"
#elif defined(__SAMD20J16B__) || defined(__ATSAMD20J16B__)
#  include "proc/SAMD20B/samd20j16b.h"

/* SAMD21A */
#elif defined(__SAMD21E15A__) || defined(__ATSAMD21E15A__)
#  include "proc/SAMD21A/samd21e15a.h"
#elif defined(__SAMD21E16A__) || defined(__ATSAMD21E16A__)
#  include "proc/SAMD21A/samd21e16a.h"
#elif defined(__SAMD21E17A__) || defined(__ATSAMD21E17A__)
#  include "proc/SAMD21A/samd21e17a.h"
#elif defined(__SAMD21E18A__) || defined(__ATSAMD21E18A__)
#  include "proc/SAMD21A/samd21e18a.h"
#elif defined(__SAMD21G15A__) || defined(__ATSAMD21G15A__)
#  include "proc/SAMD21A/samd21g15a.h"
#elif defined(__SAMD21G16A__) || defined(__ATSAMD21G16A__)
#  include "proc/SAMD21A/samd21g16a.h"
#elif defined(__SAMD21G17A__) || defined(__ATSAMD21G17A__)
#  include "proc/SAMD21A/samd21g17a.h"
#elif defined(__SAMD21G17AU__) || defined(__ATSAMD21G17AU__)
#  include "proc/SAMD21A/samd21g17au.h"
#elif defined(__SAMD21G18A__) || defined(__ATSAMD21G18A__)
#  include "proc/SAMD21A/samd21g18a.h"
#elif defined(__SAMD21G18AU__) || defined(__ATSAMD21G18AU__)
#  include "proc/SAMD21A/samd21g18au.h"
#elif defined(__SAMD21J15A__) || defined(__ATSAMD21J15A__)
#  include "proc/SAMD21A/samd21j15a.h"
#elif defined(__SAMD21J16A__) || defined(__ATSAMD21J16A__)
#  include "proc/SAMD21A/samd21j16a.h"
#elif defined(__SAMD21J17A__) || defined(__ATSAMD21J17A__)
#  include "proc/SAMD21A/samd21j17a.h"
#elif defined(__SAMD21J18A__) || defined(__ATSAMD21J18A__)
#  include "proc/SAMD21A/samd21j18a.h"

/* SAMD21B */
#elif defined(__SAMD21E15BU__) || defined(__ATSAMD21E15BU__)
#  include "proc/SAMD21B/samd21e15bu.h"
#elif defined(__SAMD21E16BU__) || defined(__ATSAMD21E16BU__)
#  include "proc/SAMD21B/samd21e16bu.h"

/* SAMD21C */
#elif defined(__SAMD21E15B__) || defined(__ATSAMD21E15B__)
#  include "proc/SAMD21C/samd21e15b.h"
#elif defined(__SAMD21E15CU__) || defined(__ATSAMD21E15CU__)
#  include "proc/SAMD21C/samd21e15cu.h"
#elif defined(__SAMD21E15L__) || defined(__ATSAMD21E15L__)
#  include "proc/SAMD21C/samd21e15l.h"
#elif defined(__SAMD21E16B__) || defined(__ATSAMD21E16B__)
#  include "proc/SAMD21C/samd21e16b.h"
#elif defined(__SAMD21E16CU__) || defined(__ATSAMD21E16CU__)
#  include "proc/SAMD21C/samd21e16cu.h"
#elif defined(__SAMD21E16L__) || defined(__ATSAMD21E16L__)
#  include "proc/SAMD21C/samd21e16l.h"
#elif defined(__SAMD21G15B__) || defined(__ATSAMD21G15B__)
#  include "proc/SAMD21C/samd21g15b.h"
#elif defined(__SAMD21G15L__) || defined(__ATSAMD21G15L__)
#  include "proc/SAMD21C/samd21g15l.h"
#elif defined(__SAMD21G16B__) || defined(__ATSAMD21G16B__)
#  include "proc/SAMD21C/samd21g16b.h"
#elif defined(__SAMD21G16L__) || defined(__ATSAMD21G16L__)
#  include "proc/SAMD21C/samd21g16l.h"
#elif defined(__SAMD21J15B__) || defined(__ATSAMD21J15B__)
#  include "proc/SAMD21C/samd21j15b.h"
#elif defined(__SAMD21J16B__) || defined(__ATSAMD21J16B__)
#  include "proc/SAMD21C/samd21j16b.h"

/* SAMD21D */
#elif defined(__SAMD21E17D__) || defined(__ATSAMD21E17D__)
#  include "proc/SAMD21D/samd21e17d.h"
#elif defined(__SAMD21E17DAZ__) || defined(__ATSAMD21E17DAZ__)
#  include "proc/SAMD21D/samd21e17daz.h"
#elif defined(__SAMD21E17DMZ__) || defined(__ATSAMD21E17DMZ__)
#  include "proc/SAMD21D/samd21e17dmz.h"
#elif defined(__SAMD21E17DU__) || defined(__ATSAMD21E17DU__)
#  include "proc/SAMD21D/samd21e17du.h"
#elif defined(__SAMD21E17L__) || defined(__ATSAMD21E17L__)
#  include "proc/SAMD21D/samd21e17l.h"
#elif defined(__SAMD21E17LAF__) || defined(__ATSAMD21E17LAF__)
#  include "proc/SAMD21D/samd21e17laf.h"
#elif defined(__SAMD21E17LMF__) || defined(__ATSAMD21E17LMF__)
#  include "proc/SAMD21D/samd21e17lmf.h"
#elif defined(__SAMD21G17D__) || defined(__ATSAMD21G17D__)
#  include "proc/SAMD21D/samd21g17d.h"
#elif defined(__SAMD21G17DAZ__) || defined(__ATSAMD21G17DAZ__)
#  include "proc/SAMD21D/samd21g17daz.h"
#elif defined(__SAMD21G17DMZ__) || defined(__ATSAMD21G17DMZ__)
#  include "proc/SAMD21D/samd21g17dmz.h"
#elif defined(__SAMD21G17L__) || defined(__ATSAMD21G17L__)
#  include "proc/SAMD21D/samd21g17l.h"
#elif defined(__SAMD21J17D__) || defined(__ATSAMD21J17D__)
#  include "proc/SAMD21D/samd21j17d.h"
#elif defined(__SAMD21J17DAZ__) || defined(__ATSAMD21J17DAZ__)
#  include "proc/SAMD21D/samd21j17daz.h"
#elif defined(__SAMD21J17DMZ__) || defined(__ATSAMD21J17DMZ__)
#  include "proc/SAMD21D/samd21j17dmz.h"

/* SAMD51A */
#elif defined(__SAMD51G18A__) || defined(__ATSAMD51G18A__)
#  include "proc/SAMD51A/samd51g18a.h"
#elif defined(__SAMD51G19A__) || defined(__ATSAMD51G19A__)
#  include "proc/SAMD51A/samd51g19a.h"
#elif defined(__SAMD51J18A__) || defined(__ATSAMD51J18A__)
#  include "proc/SAMD51A/samd51j18a.h"
#elif defined(__SAMD51J19A__) || defined(__ATSAMD51J19A__)
#  include "proc/SAMD51A/samd51j19a.h"
#elif defined(__SAMD51J20A__) || defined(__ATSAMD51J20A__)
#  include "proc/SAMD51A/samd51j20a.h"
#elif defined(__SAMD51N19A__) || defined(__ATSAMD51N19A__)
#  include "proc/SAMD51A/samd51n19a.h"
#elif defined(__SAMD51N20A__) || defined(__ATSAMD51N20A__)
#  include "proc/SAMD51A/samd51n20a.h"
#elif defined(__SAMD51P19A__) || defined(__ATSAMD51P19A__)
#  include "proc/SAMD51A/samd51p19a.h"
#elif defined(__SAMD51P20A__) || defined(__ATSAMD51P20A__)
#  include "proc/SAMD51A/samd51p20a.h"

/* SAME51 */
#elif defined(__SAME51J18A__) || defined(__ATSAME51J18A__)
#  include "proc/SAME51/same51j18a.h"
#elif defined(__SAME51J19A__) || defined(__ATSAME51J19A__)
#  include "proc/SAME51/same51j19a.h"
#elif defined(__SAME51J20A__) || defined(__ATSAME51J20A__)
#  include "proc/SAME51/same51j20a.h"
#elif defined(__SAME51N19A__) || defined(__ATSAME51N19A__)
#  include "proc/SAME51/same51n19a.h"
#elif defined(__SAME51N20A__) || defined(__ATSAME51N20A__)
#  include "proc/SAME51/same51n20a.h"

/* SAME53 */
#elif defined(__SAME53J18A__) || defined(__ATSAME53J18A__)
#  include "proc/SAME53/same53j18a.h"
#elif defined(__SAME53J19A__) || defined(__ATSAME53J19A__)
#  include "proc/SAME53/same53j19a.h"
#elif defined(__SAME53J20A__) || defined(__ATSAME53J20A__)
#  include "proc/SAME53/same53j20a.h"
#elif defined(__SAME53N19A__) || defined(__ATSAME53N19A__)
#  include "proc/SAME53/same53n19a.h"
#elif defined(__SAME53N20A__) || defined(__ATSAME53N20A__)
#  include "proc/SAME53/same53n20a.h"

/* SAME54 */
#elif defined(__SAME54N19A__) || defined(__ATSAME54N19A__)
#  include "proc/SAME54/same54n19a.h"
#elif defined(__SAME54N20A__) || defined(__ATSAME54N20A__)
#  include "proc/SAME54/same54n20a.h"
#elif defined(__SAME54P19A__) || defined(__ATSAME54P19A__)
#  include "proc/SAME54/same54p19a.h"
#elif defined(__SAME54P20A__) || defined(__ATSAME54P20A__)
#  include "proc/SAME54/same54p20a.h"

/* SAME70A */
#elif defined(__SAME70J19__) || defined(__ATSAME70J19__)
#  include "proc/SAME70A/same70j19.h"
#elif defined(__SAME70J20__) || defined(__ATSAME70J20__)
#  include "proc/SAME70A/same70j20.h"
#elif defined(__SAME70J21__) || defined(__ATSAME70J21__)
#  include "proc/SAME70A/same70j21.h"
#elif defined(__SAME70N19__) || defined(__ATSAME70N19__)
#  include "proc/SAME70A/same70n19.h"
#elif defined(__SAME70N20__) || defined(__ATSAME70N20__)
#  include "proc/SAME70A/same70n20.h"
#elif defined(__SAME70N21__) || defined(__ATSAME70N21__)
#  include "proc/SAME70A/same70n21.h"
#elif defined(__SAME70Q19__) || defined(__ATSAME70Q19__)
#  include "proc/SAME70A/same70q19.h"
#elif defined(__SAME70Q20__) || defined(__ATSAME70Q20__)
#  include "proc/SAME70A/same70q20.h"
#elif defined(__SAME70Q21__) || defined(__ATSAME70Q21__)
#  include "proc/SAME70A/same70q21.h"

/* SAME70B */
#elif defined(__SAME70J19B__) || defined(__ATSAME70J19B__)
#  include "proc/SAME70B/same70j19b.h"
#elif defined(__SAME70J20B__) || defined(__ATSAME70J20B__)
#  include "proc/SAME70B/same70j20b.h"
#elif defined(__SAME70J21B__) || defined(__ATSAME70J21B__)
#  include "proc/SAME70B/same70j21b.h"
#elif defined(__SAME70N19B__) || defined(__ATSAME70N19B__)
#  include "proc/SAME70B/same70n19b.h"
#elif defined(__SAME70N20B__) || defined(__ATSAME70N20B__)
#  include "proc/SAME70B/same70n20b.h"
#elif defined(__SAME70N21B__) || defined(__ATSAME70N21B__)
#  include "proc/SAME70B/same70n21b.h"
#elif defined(__SAME70Q19B__) || defined(__ATSAME70Q19B__)
#  include "proc/SAME70B/same70q19b.h"
#elif defined(__SAME70Q20B__) || defined(__ATSAME70Q20B__)
#  include "proc/SAME70B/same70q20b.h"
#elif defined(__SAME70Q21B__) || defined(__ATSAME70Q21B__)
#  include "proc/SAME70B/same70q21b.h"

/* SAMG51 */
#elif defined(__SAMG51G18__) || defined(__ATSAMG51G18__)
#  include "proc/SAMG51/samg51g18.h"
#elif defined(__SAMG51N18__) || defined(__ATSAMG51N18__)
#  include "proc/SAMG51/samg51n18.h"

/* SAMG53 */
#elif defined(__SAMG53G19__) || defined(__ATSAMG53G19__)
#  include "proc/SAMG53/samg53g19.h"
#elif defined(__SAMG53N19__) || defined(__ATSAMG53N19__)
#  include "proc/SAMG53/samg53n19.h"

/* SAMG54 */
#elif defined(__SAMG54G19__) || defined(__ATSAMG54G19__)
#  include "proc/SAMG54/samg54g19.h"
#elif defined(__SAMG54J19__) || defined(__ATSAMG54J19__)
#  include "proc/SAMG54/samg54j19.h"
#elif defined(__SAMG54N19__) || defined(__ATSAMG54N19__)
#  include "proc/SAMG54/samg54n19.h"

/* SAMG55 */
#elif defined(__SAMG55G19__) || defined(__ATSAMG55G19__)
#  include "proc/SAMG55/samg55g19.h"
#elif defined(__SAMG55J19__) || defined(__ATSAMG55J19__)
#  include "proc/SAMG55/samg55j19.h"

/* SAML10 */
#elif defined(__SAML10D14A__) || defined(__ATSAML10D14A__)
#  include "proc/SAML10/saml10d14a.h"
#elif defined(__SAML10D15A__) || defined(__ATSAML10D15A__)
#  include "proc/SAML10/saml10d15a.h"
#elif defined(__SAML10D16A__) || defined(__ATSAML10D16A__)
#  include "proc/SAML10/saml10d16a.h"
#elif defined(__SAML10E14A__) || defined(__ATSAML10E14A__)
#  include "proc/SAML10/saml10e14a.h"
#elif defined(__SAML10E15A__) || defined(__ATSAML10E15A__)
#  include "proc/SAML10/saml10e15a.h"
#elif defined(__SAML10E16A__) || defined(__ATSAML10E16A__)
#  include "proc/SAML10/saml10e16a.h"

/* SAML11 */
#elif defined(__SAML11D14A__) || defined(__ATSAML11D14A__)
#  include "proc/SAML11/saml11d14a.h"
#elif defined(__SAML11D15A__) || defined(__ATSAML11D15A__)
#  include "proc/SAML11/saml11d15a.h"
#elif defined(__SAML11D16A__) || defined(__ATSAML11D16A__)
#  include "proc/SAML11/saml11d16a.h"
#elif defined(__SAML11E14A__) || defined(__ATSAML11E14A__)
#  include "proc/SAML11/saml11e14a.h"
#elif defined(__SAML11E15A__) || defined(__ATSAML11E15A__)
#  include "proc/SAML11/saml11e15a.h"
#elif defined(__SAML11E16A__) || defined(__ATSAML11E16A__)
#  include "proc/SAML11/saml11e16a.h"

/* SAML21A1 */
#elif defined(__SAML21E18A__) || defined(__ATSAML21E18A__)
#  include "proc/SAML21A1/saml21e18a.h"
#elif defined(__SAML21G18A__) || defined(__ATSAML21G18A__)
#  include "proc/SAML21A1/saml21g18a.h"
#elif defined(__SAML21J18A__) || defined(__ATSAML21J18A__)
#  include "proc/SAML21A1/saml21j18a.h"

/* SAML21B */
#elif defined(__SAML21E15B__) || defined(__ATSAML21E15B__)
#  include "proc/SAML21B/saml21e15b.h"
#elif defined(__SAML21E16B__) || defined(__ATSAML21E16B__)
#  include "proc/SAML21B/saml21e16b.h"
#elif defined(__SAML21E17B__) || defined(__ATSAML21E17B__)
#  include "proc/SAML21B/saml21e17b.h"
#elif defined(__SAML21E18B__) || defined(__ATSAML21E18B__)
#  include "proc/SAML21B/saml21e18b.h"
#elif defined(__SAML21G16B__) || defined(__ATSAML21G16B__)
#  include "proc/SAML21B/saml21g16b.h"
#elif defined(__SAML21G17B__) || defined(__ATSAML21G17B__)
#  include "proc/SAML21B/saml21g17b.h"
#elif defined(__SAML21G18B__) || defined(__ATSAML21G18B__)
#  include "proc/SAML21B/saml21g18b.h"
#elif defined(__SAML21J16B__) || defined(__ATSAML21J16B__)
#  include "proc/SAML21B/saml21j16b.h"
#elif defined(__SAML21J17B__) || defined(__ATSAML21J17B__)
#  include "proc/SAML21B/saml21j17b.h"
#elif defined(__SAML21J17BU__) || defined(__ATSAML21J17BU__)
#  include "proc/SAML21B/saml21j17bu.h"
#elif defined(__SAML21J18B__) || defined(__ATSAML21J18B__)
#  include "proc/SAML21B/saml21j18b.h"
#elif defined(__SAML21J18BU__) || defined(__ATSAML21J18BU__)
#  include "proc/SAML21B/saml21j18bu.h"

/* SAML22 */
#elif defined(__SAML22G16A__) || defined(__ATSAML22G16A__)
#  include "proc/SAML22/saml22g16a.h"
#elif defined(__SAML22G17A__) || defined(__ATSAML22G17A__)
#  include "proc/SAML22/saml22g17a.h"
#elif defined(__SAML22G18A__) || defined(__ATSAML22G18A__)
#  include "proc/SAML22/saml22g18a.h"
#elif defined(__SAML22J16A__) || defined(__ATSAML22J16A__)
#  include "proc/SAML22/saml22j16a.h"
#elif defined(__SAML22J17A__) || defined(__ATSAML22J17A__)
#  include "proc/SAML22/saml22j17a.h"
#elif defined(__SAML22J18A__) || defined(__ATSAML22J18A__)
#  include "proc/SAML22/saml22j18a.h"
#elif defined(__SAML22N16A__) || defined(__ATSAML22N16A__)
#  include "proc/SAML22/saml22n16a.h"
#elif defined(__SAML22N17A__) || defined(__ATSAML22N17A__)
#  include "proc/SAML22/saml22n17a.h"
#elif defined(__SAML22N18A__) || defined(__ATSAML22N18A__)
#  include "proc/SAML22/saml22n18a.h"

/* SAMR21 */
#elif defined(__SAMR21E16A__) || defined(__ATSAMR21E16A__)
#  include "proc/SAMR21/samr21e16a.h"
#elif defined(__SAMR21E17A__) || defined(__ATSAMR21E17A__)
#  include "proc/SAMR21/samr21e17a.h"
#elif defined(__SAMR21E18A__) || defined(__ATSAMR21E18A__)
#  include "proc/SAMR21/samr21e18a.h"
#elif defined(__SAMR21E19A__) || defined(__ATSAMR21E19A__)
#  include "proc/SAMR21/samr21e19a.h"
#elif defined(__SAMR21G16A__) || defined(__ATSAMR21G16A__)
#  include "proc/SAMR21/samr21g16a.h"
#elif defined(__SAMR21G17A__) || defined(__ATSAMR21G17A__)
#  include "proc/SAMR21/samr21g17a.h"
#elif defined(__SAMR21G18A__) || defined(__ATSAMR21G18A__)
#  include "proc/SAMR21/samr21g18a.h"

/* SAMR30 */
#elif defined(__SAMR30E18A__) || defined(__ATSAMR30E18A__)
#  include "proc/SAMR30/samr30e18a.h"
#elif defined(__SAMR30G18A__) || defined(__ATSAMR30G18A__)
#  include "proc/SAMR30/samr30g18a.h"

/* SAMR34 */
#elif defined(__SAMR34J16B__) || defined(__ATSAMR34J16B__)
#  include "proc/SAMR34/samr34j16b.h"
#elif defined(__SAMR34J17B__) || defined(__ATSAMR34J17B__)
#  include "proc/SAMR34/samr34j17b.h"
#elif defined(__SAMR34J18B__) || defined(__ATSAMR34J18B__)
#  include "proc/SAMR34/samr34j18b.h"

/* SAMR35 */
#elif defined(__SAMR35J16B__) || defined(__ATSAMR35J16B__)
#  include "proc/SAMR35/samr35j16b.h"
#elif defined(__SAMR35J17B__) || defined(__ATSAMR35J17B__)
#  include "proc/SAMR35/samr35j17b.h"
#elif defined(__SAMR35J18B__) || defined(__ATSAMR35J18B__)
#  include "proc/SAMR35/samr35j18b.h"

/* SAMRH71 */
#elif defined(__SAMRH71F20B__) || defined(__ATSAMRH71F20B__)
#  include "proc/SAMRH71/samrh71f20b.h"

/* SAMS70A */
#elif defined(__SAMS70J19__) || defined(__ATSAMS70J19__)
#  include "proc/SAMS70A/sams70j19.h"
#elif defined(__SAMS70J20__) || defined(__ATSAMS70J20__)
#  include "proc/SAMS70A/sams70j20.h"
#elif defined(__SAMS70J21__) || defined(__ATSAMS70J21__)
#  include "proc/SAMS70A/sams70j21.h"
#elif defined(__SAMS70N19__) || defined(__ATSAMS70N19__)
#  include "proc/SAMS70A/sams70n19.h"
#elif defined(__SAMS70N20__) || defined(__ATSAMS70N20__)
#  include "proc/SAMS70A/sams70n20.h"
#elif defined(__SAMS70N21__) || defined(__ATSAMS70N21__)
#  include "proc/SAMS70A/sams70n21.h"
#elif defined(__SAMS70Q19__) || defined(__ATSAMS70Q19__)
#  include "proc/SAMS70A/sams70q19.h"
#elif defined(__SAMS70Q20__) || defined(__ATSAMS70Q20__)
#  include "proc/SAMS70A/sams70q20.h"
#elif defined(__SAMS70Q21__) || defined(__ATSAMS70Q21__)
#  include "proc/SAMS70A/sams70q21.h"

/* SAMS70B */
#elif defined(__SAMS70J19B__) || defined(__ATSAMS70J19B__)
#  include "proc/SAMS70B/sams70j19b.h"
#elif defined(__SAMS70J20B__) || defined(__ATSAMS70J20B__)
#  include "proc/SAMS70B/sams70j20b.h"
#elif defined(__SAMS70J21B__) || defined(__ATSAMS70J21B__)
#  include "proc/SAMS70B/sams70j21b.h"
#elif defined(__SAMS70N19B__) || defined(__ATSAMS70N19B__)
#  include "proc/SAMS70B/sams70n19b.h"
#elif defined(__SAMS70N20B__) || defined(__ATSAMS70N20B__)
#  include "proc/SAMS70B/sams70n20b.h"
#elif defined(__SAMS70N21B__) || defined(__ATSAMS70N21B__)
#  include "proc/SAMS70B/sams70n21b.h"
#elif defined(__SAMS70Q19B__) || defined(__ATSAMS70Q19B__)
#  include "proc/SAMS70B/sams70q19b.h"
#elif defined(__SAMS70Q20B__) || defined(__ATSAMS70Q20B__)
#  include "proc/SAMS70B/sams70q20b.h"
#elif defined(__SAMS70Q21B__) || defined(__ATSAMS70Q21B__)
#  include "proc/SAMS70B/sams70q21b.h"

/* SAMV70 */
#elif defined(__SAMV70J19__) || defined(__ATSAMV70J19__)
#  include "proc/SAMV70/samv70j19.h"
#elif defined(__SAMV70J20__) || defined(__ATSAMV70J20__)
#  include "proc/SAMV70/samv70j20.h"
#elif defined(__SAMV70N19__) || defined(__ATSAMV70N19__)
#  include "proc/SAMV70/samv70n19.h"
#elif defined(__SAMV70N20__) || defined(__ATSAMV70N20__)
#  include "proc/SAMV70/samv70n20.h"
#elif defined(__SAMV70Q19__) || defined(__ATSAMV70Q19__)
#  include "proc/SAMV70/samv70q19.h"
#elif defined(__SAMV70Q20__) || defined(__ATSAMV70Q20__)
#  include "proc/SAMV70/samv70q20.h"

/* SAMV70B */
#elif defined(__SAMV70J19B__) || defined(__ATSAMV70J19B__)
#  include "proc/SAMV70B/samv70j19b.h"
#elif defined(__SAMV70J20B__) || defined(__ATSAMV70J20B__)
#  include "proc/SAMV70B/samv70j20b.h"
#elif defined(__SAMV70N19B__) || defined(__ATSAMV70N19B__)
#  include "proc/SAMV70B/samv70n19b.h"
#elif defined(__SAMV70N20B__) || defined(__ATSAMV70N20B__)
#  include "proc/SAMV70B/samv70n20b.h"
#elif defined(__SAMV70Q19B__) || defined(__ATSAMV70Q19B__)
#  include "proc/SAMV70B/samv70q19b.h"
#elif defined(__SAMV70Q20B__) || defined(__ATSAMV70Q20B__)
#  include "proc/SAMV70B/samv70q20b.h"

/* SAMV71 */
#elif defined(__SAMV71J19__) || defined(__ATSAMV71J19__)
#  include "proc/SAMV71/samv71j19.h"
#elif defined(__SAMV71J20__) || defined(__ATSAMV71J20__)
#  include "proc/SAMV71/samv71j20.h"
#elif defined(__SAMV71J21__) || defined(__ATSAMV71J21__)
#  include "proc/SAMV71/samv71j21.h"
#elif defined(__SAMV71N19__) || defined(__ATSAMV71N19__)
#  include "proc/SAMV71/samv71n19.h"
#elif defined(__SAMV71N20__) || defined(__ATSAMV71N20__)
#  include "proc/SAMV71/samv71n20.h"
#elif defined(__SAMV71N21__) || defined(__ATSAMV71N21__)
#  include "proc/SAMV71/samv71n21.h"
#elif defined(__SAMV71Q19__) || defined(__ATSAMV71Q19__)
#  include "proc/SAMV71/samv71q19.h"
#elif defined(__SAMV71Q20__) || defined(__ATSAMV71Q20__)
#  include "proc/SAMV71/samv71q20.h"
#elif defined(__SAMV71Q21__) || defined(__ATSAMV71Q21__)
#  include "proc/SAMV71/samv71q21.h"

/* SAMV71B */
#elif defined(__SAMV71J19B__) || defined(__ATSAMV71J19B__)
#  include "proc/SAMV71B/samv71j19b.h"
#elif defined(__SAMV71J20B__) || defined(__ATSAMV71J20B__)
#  include "proc/SAMV71B/samv71j20b.h"
#elif defined(__SAMV71J21B__) || defined(__ATSAMV71J21B__)
#  include "proc/SAMV71B/samv71j21b.h"
#elif defined(__SAMV71N19B__) || defined(__ATSAMV71N19B__)
#  include "proc/SAMV71B/samv71n19b.h"
#elif defined(__SAMV71N20B__) || defined(__ATSAMV71N20B__)
#  include "proc/SAMV71B/samv71n20b.h"
#elif defined(__SAMV71N21B__) || defined(__ATSAMV71N21B__)
#  include "proc/SAMV71B/samv71n21b.h"
#elif defined(__SAMV71Q19B__) || defined(__ATSAMV71Q19B__)
#  include "proc/SAMV71B/samv71q19b.h"
#elif defined(__SAMV71Q20B__) || defined(__ATSAMV71Q20B__)
#  include "proc/SAMV71B/samv71q20b.h"
#elif defined(__SAMV71Q21B__) || defined(__ATSAMV71Q21B__)
#  include "proc/SAMV71B/samv71q21b.h"

#else
#  error Missing device-specific header file
#endif

#if defined (__LANGUAGE_C__) || defined (__LANGUAGE_C_PLUS_PLUS__)

#ifndef _nop
#define _nop() __builtin_nop()
#endif /* _nop */

#ifndef Nop
/* Consider using _nop rather than Nop */
#define Nop()  _nop()
#endif /* Nop */

#endif /* defined (__LANGUAGE_C__) || defined (__LANGUAGE_C_PLUS_PLUS__) */


#endif

/*-------------------------------------------------------------------------
 * XC processor header
 * Build date : May 20 2021
 *
 * Copyright (c) 2019, Microchip Technology Inc. and its subsidiaries ("Microchip")
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
 *         with the distribution. Publication is not required when this 
 *         file is used in an embedded application.
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

#pragma once
#ifndef __XC_PIC32M_H
#define __XC_PIC32M_H

#ifndef __XC32_PART_SUPPORT_VERSION
#define __XC32_PART_SUPPORT_VERSION 2300
#endif
#ifndef __XC32_PART_SUPPORT_UPDATE
#define __XC32_PART_SUPPORT_UPDATE A
#endif

#if 0
/* MECxxxx */
#elif defined(__MEC1404__)
# include <proc/MECxxxx/pmec1404.h>
#elif defined(__MEC1406__)
# include <proc/MECxxxx/pmec1406.h>
#elif defined(__MEC1408__)
# include <proc/MECxxxx/pmec1408.h>
#elif defined(__MEC1414__)
# include <proc/MECxxxx/pmec1414.h>
#elif defined(__MEC1416__)
# include <proc/MECxxxx/pmec1416.h>
#elif defined(__MEC1418__)
# include <proc/MECxxxx/pmec1418.h>
#elif defined(__MEC1428__)
# include <proc/MECxxxx/pmec1428.h>
#elif defined(__MGC3140__)
# include <proc/MECxxxx/pmgc3140.h>
#elif defined(__MTCH6303__)
# include <proc/MECxxxx/pmtch6303.h>
/* PIC32MK-GP */
#elif defined(__32MK0256GPG048__) || defined(__PIC32MK0256GPG048__)
# include <proc/PIC32MK-GP/p32mk0256gpg048.h>
#elif defined(__32MK0256GPG064__) || defined(__PIC32MK0256GPG064__)
# include <proc/PIC32MK-GP/p32mk0256gpg064.h>
#elif defined(__32MK0512GPD064__) || defined(__PIC32MK0512GPD064__)
# include <proc/PIC32MK-GP/p32mk0512gpd064.h>
#elif defined(__32MK0512GPD100__) || defined(__PIC32MK0512GPD100__)
# include <proc/PIC32MK-GP/p32mk0512gpd100.h>
#elif defined(__32MK0512GPE064__) || defined(__PIC32MK0512GPE064__)
# include <proc/PIC32MK-GP/p32mk0512gpe064.h>
#elif defined(__32MK0512GPE100__) || defined(__PIC32MK0512GPE100__)
# include <proc/PIC32MK-GP/p32mk0512gpe100.h>
#elif defined(__32MK0512GPG048__) || defined(__PIC32MK0512GPG048__)
# include <proc/PIC32MK-GP/p32mk0512gpg048.h>
#elif defined(__32MK0512GPG064__) || defined(__PIC32MK0512GPG064__)
# include <proc/PIC32MK-GP/p32mk0512gpg064.h>
#elif defined(__32MK0512GPK064__) || defined(__PIC32MK0512GPK064__)
# include <proc/PIC32MK-GP/p32mk0512gpk064.h>
#elif defined(__32MK0512GPK100__) || defined(__PIC32MK0512GPK100__)
# include <proc/PIC32MK-GP/p32mk0512gpk100.h>
#elif defined(__32MK1024GPD064__) || defined(__PIC32MK1024GPD064__)
# include <proc/PIC32MK-GP/p32mk1024gpd064.h>
#elif defined(__32MK1024GPD100__) || defined(__PIC32MK1024GPD100__)
# include <proc/PIC32MK-GP/p32mk1024gpd100.h>
#elif defined(__32MK1024GPE064__) || defined(__PIC32MK1024GPE064__)
# include <proc/PIC32MK-GP/p32mk1024gpe064.h>
#elif defined(__32MK1024GPE100__) || defined(__PIC32MK1024GPE100__)
# include <proc/PIC32MK-GP/p32mk1024gpe100.h>
#elif defined(__32MK1024GPK064__) || defined(__PIC32MK1024GPK064__)
# include <proc/PIC32MK-GP/p32mk1024gpk064.h>
#elif defined(__32MK1024GPK100__) || defined(__PIC32MK1024GPK100__)
# include <proc/PIC32MK-GP/p32mk1024gpk100.h>
/* PIC32MK-MC */
#elif defined(__32MK0256MCJ048__) || defined(__PIC32MK0256MCJ048__)
# include <proc/PIC32MK-MC/p32mk0256mcj048.h>
#elif defined(__32MK0256MCJ064__) || defined(__PIC32MK0256MCJ064__)
# include <proc/PIC32MK-MC/p32mk0256mcj064.h>
#elif defined(__32MK0512MCF064__) || defined(__PIC32MK0512MCF064__)
# include <proc/PIC32MK-MC/p32mk0512mcf064.h>
#elif defined(__32MK0512MCF100__) || defined(__PIC32MK0512MCF100__)
# include <proc/PIC32MK-MC/p32mk0512mcf100.h>
#elif defined(__32MK0512MCJ048__) || defined(__PIC32MK0512MCJ048__)
# include <proc/PIC32MK-MC/p32mk0512mcj048.h>
#elif defined(__32MK0512MCJ064__) || defined(__PIC32MK0512MCJ064__)
# include <proc/PIC32MK-MC/p32mk0512mcj064.h>
#elif defined(__32MK0512MCM064__) || defined(__PIC32MK0512MCM064__)
# include <proc/PIC32MK-MC/p32mk0512mcm064.h>
#elif defined(__32MK0512MCM100__) || defined(__PIC32MK0512MCM100__)
# include <proc/PIC32MK-MC/p32mk0512mcm100.h>
#elif defined(__32MK1024MCF064__) || defined(__PIC32MK1024MCF064__)
# include <proc/PIC32MK-MC/p32mk1024mcf064.h>
#elif defined(__32MK1024MCF100__) || defined(__PIC32MK1024MCF100__)
# include <proc/PIC32MK-MC/p32mk1024mcf100.h>
#elif defined(__32MK1024MCM064__) || defined(__PIC32MK1024MCM064__)
# include <proc/PIC32MK-MC/p32mk1024mcm064.h>
#elif defined(__32MK1024MCM100__) || defined(__PIC32MK1024MCM100__)
# include <proc/PIC32MK-MC/p32mk1024mcm100.h>
/* PIC32MM-GPL-0XX */
#elif defined(__32MM0016GPL020__) || defined(__PIC32MM0016GPL020__)
# include <proc/PIC32MM-GPL-0XX/p32mm0016gpl020.h>
#elif defined(__32MM0016GPL028__) || defined(__PIC32MM0016GPL028__)
# include <proc/PIC32MM-GPL-0XX/p32mm0016gpl028.h>
#elif defined(__32MM0016GPL036__) || defined(__PIC32MM0016GPL036__)
# include <proc/PIC32MM-GPL-0XX/p32mm0016gpl036.h>
#elif defined(__32MM0032GPL020__) || defined(__PIC32MM0032GPL020__)
# include <proc/PIC32MM-GPL-0XX/p32mm0032gpl020.h>
#elif defined(__32MM0032GPL028__) || defined(__PIC32MM0032GPL028__)
# include <proc/PIC32MM-GPL-0XX/p32mm0032gpl028.h>
#elif defined(__32MM0032GPL036__) || defined(__PIC32MM0032GPL036__)
# include <proc/PIC32MM-GPL-0XX/p32mm0032gpl036.h>
#elif defined(__32MM0064GPL020__) || defined(__PIC32MM0064GPL020__)
# include <proc/PIC32MM-GPL-0XX/p32mm0064gpl020.h>
#elif defined(__32MM0064GPL028__) || defined(__PIC32MM0064GPL028__)
# include <proc/PIC32MM-GPL-0XX/p32mm0064gpl028.h>
#elif defined(__32MM0064GPL036__) || defined(__PIC32MM0064GPL036__)
# include <proc/PIC32MM-GPL-0XX/p32mm0064gpl036.h>
/* PIC32MM-GPM-0XX */
#elif defined(__32MM0064GPM028__) || defined(__PIC32MM0064GPM028__)
# include <proc/PIC32MM-GPM-0XX/p32mm0064gpm028.h>
#elif defined(__32MM0064GPM036__) || defined(__PIC32MM0064GPM036__)
# include <proc/PIC32MM-GPM-0XX/p32mm0064gpm036.h>
#elif defined(__32MM0064GPM048__) || defined(__PIC32MM0064GPM048__)
# include <proc/PIC32MM-GPM-0XX/p32mm0064gpm048.h>
#elif defined(__32MM0064GPM064__) || defined(__PIC32MM0064GPM064__)
# include <proc/PIC32MM-GPM-0XX/p32mm0064gpm064.h>
#elif defined(__32MM0128GPM028__) || defined(__PIC32MM0128GPM028__)
# include <proc/PIC32MM-GPM-0XX/p32mm0128gpm028.h>
#elif defined(__32MM0128GPM036__) || defined(__PIC32MM0128GPM036__)
# include <proc/PIC32MM-GPM-0XX/p32mm0128gpm036.h>
#elif defined(__32MM0128GPM048__) || defined(__PIC32MM0128GPM048__)
# include <proc/PIC32MM-GPM-0XX/p32mm0128gpm048.h>
#elif defined(__32MM0128GPM064__) || defined(__PIC32MM0128GPM064__)
# include <proc/PIC32MM-GPM-0XX/p32mm0128gpm064.h>
#elif defined(__32MM0256GPM028__) || defined(__PIC32MM0256GPM028__)
# include <proc/PIC32MM-GPM-0XX/p32mm0256gpm028.h>
#elif defined(__32MM0256GPM036__) || defined(__PIC32MM0256GPM036__)
# include <proc/PIC32MM-GPM-0XX/p32mm0256gpm036.h>
#elif defined(__32MM0256GPM048__) || defined(__PIC32MM0256GPM048__)
# include <proc/PIC32MM-GPM-0XX/p32mm0256gpm048.h>
#elif defined(__32MM0256GPM064__) || defined(__PIC32MM0256GPM064__)
# include <proc/PIC32MM-GPM-0XX/p32mm0256gpm064.h>
/* PIC32MX */
#elif defined(__32MX110F016B__) || defined(__PIC32MX110F016B__)
# include <proc/PIC32MX/p32mx110f016b.h>
#elif defined(__32MX110F016C__) || defined(__PIC32MX110F016C__)
# include <proc/PIC32MX/p32mx110f016c.h>
#elif defined(__32MX110F016D__) || defined(__PIC32MX110F016D__)
# include <proc/PIC32MX/p32mx110f016d.h>
#elif defined(__32MX120F032B__) || defined(__PIC32MX120F032B__)
# include <proc/PIC32MX/p32mx120f032b.h>
#elif defined(__32MX120F032C__) || defined(__PIC32MX120F032C__)
# include <proc/PIC32MX/p32mx120f032c.h>
#elif defined(__32MX120F032D__) || defined(__PIC32MX120F032D__)
# include <proc/PIC32MX/p32mx120f032d.h>
#elif defined(__32MX120F064H__) || defined(__PIC32MX120F064H__)
# include <proc/PIC32MX/p32mx120f064h.h>
#elif defined(__32MX130F064B__) || defined(__PIC32MX130F064B__)
# include <proc/PIC32MX/p32mx130f064b.h>
#elif defined(__32MX130F064C__) || defined(__PIC32MX130F064C__)
# include <proc/PIC32MX/p32mx130f064c.h>
#elif defined(__32MX130F064D__) || defined(__PIC32MX130F064D__)
# include <proc/PIC32MX/p32mx130f064d.h>
#elif defined(__32MX130F128H__) || defined(__PIC32MX130F128H__)
# include <proc/PIC32MX/p32mx130f128h.h>
#elif defined(__32MX130F128L__) || defined(__PIC32MX130F128L__)
# include <proc/PIC32MX/p32mx130f128l.h>
#elif defined(__32MX130F256B__) || defined(__PIC32MX130F256B__)
# include <proc/PIC32MX/p32mx130f256b.h>
#elif defined(__32MX130F256D__) || defined(__PIC32MX130F256D__)
# include <proc/PIC32MX/p32mx130f256d.h>
#elif defined(__32MX150F128B__) || defined(__PIC32MX150F128B__)
# include <proc/PIC32MX/p32mx150f128b.h>
#elif defined(__32MX150F128C__) || defined(__PIC32MX150F128C__)
# include <proc/PIC32MX/p32mx150f128c.h>
#elif defined(__32MX150F128D__) || defined(__PIC32MX150F128D__)
# include <proc/PIC32MX/p32mx150f128d.h>
#elif defined(__32MX150F256H__) || defined(__PIC32MX150F256H__)
# include <proc/PIC32MX/p32mx150f256h.h>
#elif defined(__32MX150F256L__) || defined(__PIC32MX150F256L__)
# include <proc/PIC32MX/p32mx150f256l.h>
#elif defined(__32MX154F128B__) || defined(__PIC32MX154F128B__)
# include <proc/PIC32MX/p32mx154f128b.h>
#elif defined(__32MX154F128D__) || defined(__PIC32MX154F128D__)
# include <proc/PIC32MX/p32mx154f128d.h>
#elif defined(__32MX170F256B__) || defined(__PIC32MX170F256B__)
# include <proc/PIC32MX/p32mx170f256b.h>
#elif defined(__32MX170F256D__) || defined(__PIC32MX170F256D__)
# include <proc/PIC32MX/p32mx170f256d.h>
#elif defined(__32MX170F512H__) || defined(__PIC32MX170F512H__)
# include <proc/PIC32MX/p32mx170f512h.h>
#elif defined(__32MX170F512L__) || defined(__PIC32MX170F512L__)
# include <proc/PIC32MX/p32mx170f512l.h>
#elif defined(__32MX174F256B__) || defined(__PIC32MX174F256B__)
# include <proc/PIC32MX/p32mx174f256b.h>
#elif defined(__32MX174F256D__) || defined(__PIC32MX174F256D__)
# include <proc/PIC32MX/p32mx174f256d.h>
#elif defined(__32MX210F016B__) || defined(__PIC32MX210F016B__)
# include <proc/PIC32MX/p32mx210f016b.h>
#elif defined(__32MX210F016C__) || defined(__PIC32MX210F016C__)
# include <proc/PIC32MX/p32mx210f016c.h>
#elif defined(__32MX210F016D__) || defined(__PIC32MX210F016D__)
# include <proc/PIC32MX/p32mx210f016d.h>
#elif defined(__32MX220F032B__) || defined(__PIC32MX220F032B__)
# include <proc/PIC32MX/p32mx220f032b.h>
#elif defined(__32MX220F032C__) || defined(__PIC32MX220F032C__)
# include <proc/PIC32MX/p32mx220f032c.h>
#elif defined(__32MX220F032D__) || defined(__PIC32MX220F032D__)
# include <proc/PIC32MX/p32mx220f032d.h>
#elif defined(__32MX230F064B__) || defined(__PIC32MX230F064B__)
# include <proc/PIC32MX/p32mx230f064b.h>
#elif defined(__32MX230F064C__) || defined(__PIC32MX230F064C__)
# include <proc/PIC32MX/p32mx230f064c.h>
#elif defined(__32MX230F064D__) || defined(__PIC32MX230F064D__)
# include <proc/PIC32MX/p32mx230f064d.h>
#elif defined(__32MX230F128H__) || defined(__PIC32MX230F128H__)
# include <proc/PIC32MX/p32mx230f128h.h>
#elif defined(__32MX230F128L__) || defined(__PIC32MX230F128L__)
# include <proc/PIC32MX/p32mx230f128l.h>
#elif defined(__32MX230F256B__) || defined(__PIC32MX230F256B__)
# include <proc/PIC32MX/p32mx230f256b.h>
#elif defined(__32MX230F256D__) || defined(__PIC32MX230F256D__)
# include <proc/PIC32MX/p32mx230f256d.h>
#elif defined(__32MX250F128B__) || defined(__PIC32MX250F128B__)
# include <proc/PIC32MX/p32mx250f128b.h>
#elif defined(__32MX250F128C__) || defined(__PIC32MX250F128C__)
# include <proc/PIC32MX/p32mx250f128c.h>
#elif defined(__32MX250F128D__) || defined(__PIC32MX250F128D__)
# include <proc/PIC32MX/p32mx250f128d.h>
#elif defined(__32MX250F256H__) || defined(__PIC32MX250F256H__)
# include <proc/PIC32MX/p32mx250f256h.h>
#elif defined(__32MX250F256L__) || defined(__PIC32MX250F256L__)
# include <proc/PIC32MX/p32mx250f256l.h>
#elif defined(__32MX254F128B__) || defined(__PIC32MX254F128B__)
# include <proc/PIC32MX/p32mx254f128b.h>
#elif defined(__32MX254F128D__) || defined(__PIC32MX254F128D__)
# include <proc/PIC32MX/p32mx254f128d.h>
#elif defined(__32MX270F256B__) || defined(__PIC32MX270F256B__)
# include <proc/PIC32MX/p32mx270f256b.h>
#elif defined(__32MX270F256D__) || defined(__PIC32MX270F256D__)
# include <proc/PIC32MX/p32mx270f256d.h>
#elif defined(__32MX270F512H__) || defined(__PIC32MX270F512H__)
# include <proc/PIC32MX/p32mx270f512h.h>
#elif defined(__32MX270F512L__) || defined(__PIC32MX270F512L__)
# include <proc/PIC32MX/p32mx270f512l.h>
#elif defined(__32MX274F256B__) || defined(__PIC32MX274F256B__)
# include <proc/PIC32MX/p32mx274f256b.h>
#elif defined(__32MX274F256D__) || defined(__PIC32MX274F256D__)
# include <proc/PIC32MX/p32mx274f256d.h>
#elif defined(__32MX320F032H__) || defined(__PIC32MX320F032H__)
# include <proc/PIC32MX/p32mx320f032h.h>
#elif defined(__32MX320F064H__) || defined(__PIC32MX320F064H__)
# include <proc/PIC32MX/p32mx320f064h.h>
#elif defined(__32MX320F128H__) || defined(__PIC32MX320F128H__)
# include <proc/PIC32MX/p32mx320f128h.h>
#elif defined(__32MX320F128L__) || defined(__PIC32MX320F128L__)
# include <proc/PIC32MX/p32mx320f128l.h>
#elif defined(__32MX330F064H__) || defined(__PIC32MX330F064H__)
# include <proc/PIC32MX/p32mx330f064h.h>
#elif defined(__32MX330F064L__) || defined(__PIC32MX330F064L__)
# include <proc/PIC32MX/p32mx330f064l.h>
#elif defined(__32MX340F128H__) || defined(__PIC32MX340F128H__)
# include <proc/PIC32MX/p32mx340f128h.h>
#elif defined(__32MX340F128L__) || defined(__PIC32MX340F128L__)
# include <proc/PIC32MX/p32mx340f128l.h>
#elif defined(__32MX340F256H__) || defined(__PIC32MX340F256H__)
# include <proc/PIC32MX/p32mx340f256h.h>
#elif defined(__32MX340F512H__) || defined(__PIC32MX340F512H__)
# include <proc/PIC32MX/p32mx340f512h.h>
#elif defined(__32MX350F128H__) || defined(__PIC32MX350F128H__)
# include <proc/PIC32MX/p32mx350f128h.h>
#elif defined(__32MX350F128L__) || defined(__PIC32MX350F128L__)
# include <proc/PIC32MX/p32mx350f128l.h>
#elif defined(__32MX350F256H__) || defined(__PIC32MX350F256H__)
# include <proc/PIC32MX/p32mx350f256h.h>
#elif defined(__32MX350F256L__) || defined(__PIC32MX350F256L__)
# include <proc/PIC32MX/p32mx350f256l.h>
#elif defined(__32MX360F256L__) || defined(__PIC32MX360F256L__)
# include <proc/PIC32MX/p32mx360f256l.h>
#elif defined(__32MX360F512L__) || defined(__PIC32MX360F512L__)
# include <proc/PIC32MX/p32mx360f512l.h>
#elif defined(__32MX370F512H__) || defined(__PIC32MX370F512H__)
# include <proc/PIC32MX/p32mx370f512h.h>
#elif defined(__32MX370F512L__) || defined(__PIC32MX370F512L__)
# include <proc/PIC32MX/p32mx370f512l.h>
#elif defined(__32MX420F032H__) || defined(__PIC32MX420F032H__)
# include <proc/PIC32MX/p32mx420f032h.h>
#elif defined(__32MX430F064H__) || defined(__PIC32MX430F064H__)
# include <proc/PIC32MX/p32mx430f064h.h>
#elif defined(__32MX430F064L__) || defined(__PIC32MX430F064L__)
# include <proc/PIC32MX/p32mx430f064l.h>
#elif defined(__32MX440F128H__) || defined(__PIC32MX440F128H__)
# include <proc/PIC32MX/p32mx440f128h.h>
#elif defined(__32MX440F128L__) || defined(__PIC32MX440F128L__)
# include <proc/PIC32MX/p32mx440f128l.h>
#elif defined(__32MX440F256H__) || defined(__PIC32MX440F256H__)
# include <proc/PIC32MX/p32mx440f256h.h>
#elif defined(__32MX440F512H__) || defined(__PIC32MX440F512H__)
# include <proc/PIC32MX/p32mx440f512h.h>
#elif defined(__32MX450F128H__) || defined(__PIC32MX450F128H__)
# include <proc/PIC32MX/p32mx450f128h.h>
#elif defined(__32MX450F128L__) || defined(__PIC32MX450F128L__)
# include <proc/PIC32MX/p32mx450f128l.h>
#elif defined(__32MX450F256H__) || defined(__PIC32MX450F256H__)
# include <proc/PIC32MX/p32mx450f256h.h>
#elif defined(__32MX450F256L__) || defined(__PIC32MX450F256L__)
# include <proc/PIC32MX/p32mx450f256l.h>
#elif defined(__32MX460F256L__) || defined(__PIC32MX460F256L__)
# include <proc/PIC32MX/p32mx460f256l.h>
#elif defined(__32MX460F512L__) || defined(__PIC32MX460F512L__)
# include <proc/PIC32MX/p32mx460f512l.h>
#elif defined(__32MX470F512H__) || defined(__PIC32MX470F512H__)
# include <proc/PIC32MX/p32mx470f512h.h>
#elif defined(__32MX470F512L__) || defined(__PIC32MX470F512L__)
# include <proc/PIC32MX/p32mx470f512l.h>
#elif defined(__32MX530F128H__) || defined(__PIC32MX530F128H__)
# include <proc/PIC32MX/p32mx530f128h.h>
#elif defined(__32MX530F128L__) || defined(__PIC32MX530F128L__)
# include <proc/PIC32MX/p32mx530f128l.h>
#elif defined(__32MX534F064H__) || defined(__PIC32MX534F064H__)
# include <proc/PIC32MX/p32mx534f064h.h>
#elif defined(__32MX534F064L__) || defined(__PIC32MX534F064L__)
# include <proc/PIC32MX/p32mx534f064l.h>
#elif defined(__32MX550F256H__) || defined(__PIC32MX550F256H__)
# include <proc/PIC32MX/p32mx550f256h.h>
#elif defined(__32MX550F256L__) || defined(__PIC32MX550F256L__)
# include <proc/PIC32MX/p32mx550f256l.h>
#elif defined(__32MX564F064H__) || defined(__PIC32MX564F064H__)
# include <proc/PIC32MX/p32mx564f064h.h>
#elif defined(__32MX564F064L__) || defined(__PIC32MX564F064L__)
# include <proc/PIC32MX/p32mx564f064l.h>
#elif defined(__32MX564F128H__) || defined(__PIC32MX564F128H__)
# include <proc/PIC32MX/p32mx564f128h.h>
#elif defined(__32MX564F128L__) || defined(__PIC32MX564F128L__)
# include <proc/PIC32MX/p32mx564f128l.h>
#elif defined(__32MX570F512H__) || defined(__PIC32MX570F512H__)
# include <proc/PIC32MX/p32mx570f512h.h>
#elif defined(__32MX570F512L__) || defined(__PIC32MX570F512L__)
# include <proc/PIC32MX/p32mx570f512l.h>
#elif defined(__32MX575F256H__) || defined(__PIC32MX575F256H__)
# include <proc/PIC32MX/p32mx575f256h.h>
#elif defined(__32MX575F256L__) || defined(__PIC32MX575F256L__)
# include <proc/PIC32MX/p32mx575f256l.h>
#elif defined(__32MX575F512H__) || defined(__PIC32MX575F512H__)
# include <proc/PIC32MX/p32mx575f512h.h>
#elif defined(__32MX575F512L__) || defined(__PIC32MX575F512L__)
# include <proc/PIC32MX/p32mx575f512l.h>
#elif defined(__32MX664F064H__) || defined(__PIC32MX664F064H__)
# include <proc/PIC32MX/p32mx664f064h.h>
#elif defined(__32MX664F064L__) || defined(__PIC32MX664F064L__)
# include <proc/PIC32MX/p32mx664f064l.h>
#elif defined(__32MX664F128H__) || defined(__PIC32MX664F128H__)
# include <proc/PIC32MX/p32mx664f128h.h>
#elif defined(__32MX664F128L__) || defined(__PIC32MX664F128L__)
# include <proc/PIC32MX/p32mx664f128l.h>
#elif defined(__32MX675F256H__) || defined(__PIC32MX675F256H__)
# include <proc/PIC32MX/p32mx675f256h.h>
#elif defined(__32MX675F256L__) || defined(__PIC32MX675F256L__)
# include <proc/PIC32MX/p32mx675f256l.h>
#elif defined(__32MX675F512H__) || defined(__PIC32MX675F512H__)
# include <proc/PIC32MX/p32mx675f512h.h>
#elif defined(__32MX675F512L__) || defined(__PIC32MX675F512L__)
# include <proc/PIC32MX/p32mx675f512l.h>
#elif defined(__32MX695F512H__) || defined(__PIC32MX695F512H__)
# include <proc/PIC32MX/p32mx695f512h.h>
#elif defined(__32MX695F512L__) || defined(__PIC32MX695F512L__)
# include <proc/PIC32MX/p32mx695f512l.h>
#elif defined(__32MX764F128H__) || defined(__PIC32MX764F128H__)
# include <proc/PIC32MX/p32mx764f128h.h>
#elif defined(__32MX764F128L__) || defined(__PIC32MX764F128L__)
# include <proc/PIC32MX/p32mx764f128l.h>
#elif defined(__32MX775F256H__) || defined(__PIC32MX775F256H__)
# include <proc/PIC32MX/p32mx775f256h.h>
#elif defined(__32MX775F256L__) || defined(__PIC32MX775F256L__)
# include <proc/PIC32MX/p32mx775f256l.h>
#elif defined(__32MX775F512H__) || defined(__PIC32MX775F512H__)
# include <proc/PIC32MX/p32mx775f512h.h>
#elif defined(__32MX775F512L__) || defined(__PIC32MX775F512L__)
# include <proc/PIC32MX/p32mx775f512l.h>
#elif defined(__32MX795F512H__) || defined(__PIC32MX795F512H__)
# include <proc/PIC32MX/p32mx795f512h.h>
#elif defined(__32MX795F512L__) || defined(__PIC32MX795F512L__)
# include <proc/PIC32MX/p32mx795f512l.h>
/* PIC32MZ-DA */
#elif defined(__32MZ1025DAA169__) || defined(__PIC32MZ1025DAA169__)
# include <proc/PIC32MZ-DA/p32mz1025daa169.h>
#elif defined(__32MZ1025DAA176__) || defined(__PIC32MZ1025DAA176__)
# include <proc/PIC32MZ-DA/p32mz1025daa176.h>
#elif defined(__32MZ1025DAA288__) || defined(__PIC32MZ1025DAA288__)
# include <proc/PIC32MZ-DA/p32mz1025daa288.h>
#elif defined(__32MZ1025DAB169__) || defined(__PIC32MZ1025DAB169__)
# include <proc/PIC32MZ-DA/p32mz1025dab169.h>
#elif defined(__32MZ1025DAB176__) || defined(__PIC32MZ1025DAB176__)
# include <proc/PIC32MZ-DA/p32mz1025dab176.h>
#elif defined(__32MZ1025DAB288__) || defined(__PIC32MZ1025DAB288__)
# include <proc/PIC32MZ-DA/p32mz1025dab288.h>
#elif defined(__32MZ1025DAG169__) || defined(__PIC32MZ1025DAG169__)
# include <proc/PIC32MZ-DA/p32mz1025dag169.h>
#elif defined(__32MZ1025DAG176__) || defined(__PIC32MZ1025DAG176__)
# include <proc/PIC32MZ-DA/p32mz1025dag176.h>
#elif defined(__32MZ1025DAH169__) || defined(__PIC32MZ1025DAH169__)
# include <proc/PIC32MZ-DA/p32mz1025dah169.h>
#elif defined(__32MZ1025DAH176__) || defined(__PIC32MZ1025DAH176__)
# include <proc/PIC32MZ-DA/p32mz1025dah176.h>
#elif defined(__32MZ1025DAK169__) || defined(__PIC32MZ1025DAK169__)
# include <proc/PIC32MZ-DA/p32mz1025dak169.h>
#elif defined(__32MZ1025DAK176__) || defined(__PIC32MZ1025DAK176__)
# include <proc/PIC32MZ-DA/p32mz1025dak176.h>
#elif defined(__32MZ1025DAL169__) || defined(__PIC32MZ1025DAL169__)
# include <proc/PIC32MZ-DA/p32mz1025dal169.h>
#elif defined(__32MZ1025DAL176__) || defined(__PIC32MZ1025DAL176__)
# include <proc/PIC32MZ-DA/p32mz1025dal176.h>
#elif defined(__32MZ1025DAR169__) || defined(__PIC32MZ1025DAR169__)
# include <proc/PIC32MZ-DA/p32mz1025dar169.h>
#elif defined(__32MZ1025DAR176__) || defined(__PIC32MZ1025DAR176__)
# include <proc/PIC32MZ-DA/p32mz1025dar176.h>
#elif defined(__32MZ1025DAS169__) || defined(__PIC32MZ1025DAS169__)
# include <proc/PIC32MZ-DA/p32mz1025das169.h>
#elif defined(__32MZ1025DAS176__) || defined(__PIC32MZ1025DAS176__)
# include <proc/PIC32MZ-DA/p32mz1025das176.h>
#elif defined(__32MZ1064DAA169__) || defined(__PIC32MZ1064DAA169__)
# include <proc/PIC32MZ-DA/p32mz1064daa169.h>
#elif defined(__32MZ1064DAA176__) || defined(__PIC32MZ1064DAA176__)
# include <proc/PIC32MZ-DA/p32mz1064daa176.h>
#elif defined(__32MZ1064DAA288__) || defined(__PIC32MZ1064DAA288__)
# include <proc/PIC32MZ-DA/p32mz1064daa288.h>
#elif defined(__32MZ1064DAB169__) || defined(__PIC32MZ1064DAB169__)
# include <proc/PIC32MZ-DA/p32mz1064dab169.h>
#elif defined(__32MZ1064DAB176__) || defined(__PIC32MZ1064DAB176__)
# include <proc/PIC32MZ-DA/p32mz1064dab176.h>
#elif defined(__32MZ1064DAB288__) || defined(__PIC32MZ1064DAB288__)
# include <proc/PIC32MZ-DA/p32mz1064dab288.h>
#elif defined(__32MZ1064DAG169__) || defined(__PIC32MZ1064DAG169__)
# include <proc/PIC32MZ-DA/p32mz1064dag169.h>
#elif defined(__32MZ1064DAG176__) || defined(__PIC32MZ1064DAG176__)
# include <proc/PIC32MZ-DA/p32mz1064dag176.h>
#elif defined(__32MZ1064DAH169__) || defined(__PIC32MZ1064DAH169__)
# include <proc/PIC32MZ-DA/p32mz1064dah169.h>
#elif defined(__32MZ1064DAH176__) || defined(__PIC32MZ1064DAH176__)
# include <proc/PIC32MZ-DA/p32mz1064dah176.h>
#elif defined(__32MZ1064DAK169__) || defined(__PIC32MZ1064DAK169__)
# include <proc/PIC32MZ-DA/p32mz1064dak169.h>
#elif defined(__32MZ1064DAK176__) || defined(__PIC32MZ1064DAK176__)
# include <proc/PIC32MZ-DA/p32mz1064dak176.h>
#elif defined(__32MZ1064DAL169__) || defined(__PIC32MZ1064DAL169__)
# include <proc/PIC32MZ-DA/p32mz1064dal169.h>
#elif defined(__32MZ1064DAL176__) || defined(__PIC32MZ1064DAL176__)
# include <proc/PIC32MZ-DA/p32mz1064dal176.h>
#elif defined(__32MZ1064DAR169__) || defined(__PIC32MZ1064DAR169__)
# include <proc/PIC32MZ-DA/p32mz1064dar169.h>
#elif defined(__32MZ1064DAR176__) || defined(__PIC32MZ1064DAR176__)
# include <proc/PIC32MZ-DA/p32mz1064dar176.h>
#elif defined(__32MZ1064DAS169__) || defined(__PIC32MZ1064DAS169__)
# include <proc/PIC32MZ-DA/p32mz1064das169.h>
#elif defined(__32MZ1064DAS176__) || defined(__PIC32MZ1064DAS176__)
# include <proc/PIC32MZ-DA/p32mz1064das176.h>
#elif defined(__32MZ2025DAA169__) || defined(__PIC32MZ2025DAA169__)
# include <proc/PIC32MZ-DA/p32mz2025daa169.h>
#elif defined(__32MZ2025DAA176__) || defined(__PIC32MZ2025DAA176__)
# include <proc/PIC32MZ-DA/p32mz2025daa176.h>
#elif defined(__32MZ2025DAA288__) || defined(__PIC32MZ2025DAA288__)
# include <proc/PIC32MZ-DA/p32mz2025daa288.h>
#elif defined(__32MZ2025DAB169__) || defined(__PIC32MZ2025DAB169__)
# include <proc/PIC32MZ-DA/p32mz2025dab169.h>
#elif defined(__32MZ2025DAB176__) || defined(__PIC32MZ2025DAB176__)
# include <proc/PIC32MZ-DA/p32mz2025dab176.h>
#elif defined(__32MZ2025DAB288__) || defined(__PIC32MZ2025DAB288__)
# include <proc/PIC32MZ-DA/p32mz2025dab288.h>
#elif defined(__32MZ2025DAG169__) || defined(__PIC32MZ2025DAG169__)
# include <proc/PIC32MZ-DA/p32mz2025dag169.h>
#elif defined(__32MZ2025DAG176__) || defined(__PIC32MZ2025DAG176__)
# include <proc/PIC32MZ-DA/p32mz2025dag176.h>
#elif defined(__32MZ2025DAH169__) || defined(__PIC32MZ2025DAH169__)
# include <proc/PIC32MZ-DA/p32mz2025dah169.h>
#elif defined(__32MZ2025DAH176__) || defined(__PIC32MZ2025DAH176__)
# include <proc/PIC32MZ-DA/p32mz2025dah176.h>
#elif defined(__32MZ2025DAK169__) || defined(__PIC32MZ2025DAK169__)
# include <proc/PIC32MZ-DA/p32mz2025dak169.h>
#elif defined(__32MZ2025DAK176__) || defined(__PIC32MZ2025DAK176__)
# include <proc/PIC32MZ-DA/p32mz2025dak176.h>
#elif defined(__32MZ2025DAL169__) || defined(__PIC32MZ2025DAL169__)
# include <proc/PIC32MZ-DA/p32mz2025dal169.h>
#elif defined(__32MZ2025DAL176__) || defined(__PIC32MZ2025DAL176__)
# include <proc/PIC32MZ-DA/p32mz2025dal176.h>
#elif defined(__32MZ2025DAR169__) || defined(__PIC32MZ2025DAR169__)
# include <proc/PIC32MZ-DA/p32mz2025dar169.h>
#elif defined(__32MZ2025DAR176__) || defined(__PIC32MZ2025DAR176__)
# include <proc/PIC32MZ-DA/p32mz2025dar176.h>
#elif defined(__32MZ2025DAS169__) || defined(__PIC32MZ2025DAS169__)
# include <proc/PIC32MZ-DA/p32mz2025das169.h>
#elif defined(__32MZ2025DAS176__) || defined(__PIC32MZ2025DAS176__)
# include <proc/PIC32MZ-DA/p32mz2025das176.h>
#elif defined(__32MZ2064DAA169__) || defined(__PIC32MZ2064DAA169__)
# include <proc/PIC32MZ-DA/p32mz2064daa169.h>
#elif defined(__32MZ2064DAA176__) || defined(__PIC32MZ2064DAA176__)
# include <proc/PIC32MZ-DA/p32mz2064daa176.h>
#elif defined(__32MZ2064DAA288__) || defined(__PIC32MZ2064DAA288__)
# include <proc/PIC32MZ-DA/p32mz2064daa288.h>
#elif defined(__32MZ2064DAB169__) || defined(__PIC32MZ2064DAB169__)
# include <proc/PIC32MZ-DA/p32mz2064dab169.h>
#elif defined(__32MZ2064DAB176__) || defined(__PIC32MZ2064DAB176__)
# include <proc/PIC32MZ-DA/p32mz2064dab176.h>
#elif defined(__32MZ2064DAB288__) || defined(__PIC32MZ2064DAB288__)
# include <proc/PIC32MZ-DA/p32mz2064dab288.h>
#elif defined(__32MZ2064DAG169__) || defined(__PIC32MZ2064DAG169__)
# include <proc/PIC32MZ-DA/p32mz2064dag169.h>
#elif defined(__32MZ2064DAG176__) || defined(__PIC32MZ2064DAG176__)
# include <proc/PIC32MZ-DA/p32mz2064dag176.h>
#elif defined(__32MZ2064DAH169__) || defined(__PIC32MZ2064DAH169__)
# include <proc/PIC32MZ-DA/p32mz2064dah169.h>
#elif defined(__32MZ2064DAH176__) || defined(__PIC32MZ2064DAH176__)
# include <proc/PIC32MZ-DA/p32mz2064dah176.h>
#elif defined(__32MZ2064DAK169__) || defined(__PIC32MZ2064DAK169__)
# include <proc/PIC32MZ-DA/p32mz2064dak169.h>
#elif defined(__32MZ2064DAK176__) || defined(__PIC32MZ2064DAK176__)
# include <proc/PIC32MZ-DA/p32mz2064dak176.h>
#elif defined(__32MZ2064DAL169__) || defined(__PIC32MZ2064DAL169__)
# include <proc/PIC32MZ-DA/p32mz2064dal169.h>
#elif defined(__32MZ2064DAL176__) || defined(__PIC32MZ2064DAL176__)
# include <proc/PIC32MZ-DA/p32mz2064dal176.h>
#elif defined(__32MZ2064DAR169__) || defined(__PIC32MZ2064DAR169__)
# include <proc/PIC32MZ-DA/p32mz2064dar169.h>
#elif defined(__32MZ2064DAR176__) || defined(__PIC32MZ2064DAR176__)
# include <proc/PIC32MZ-DA/p32mz2064dar176.h>
#elif defined(__32MZ2064DAS169__) || defined(__PIC32MZ2064DAS169__)
# include <proc/PIC32MZ-DA/p32mz2064das169.h>
#elif defined(__32MZ2064DAS176__) || defined(__PIC32MZ2064DAS176__)
# include <proc/PIC32MZ-DA/p32mz2064das176.h>
/* PIC32MZ-EC */
#elif defined(__32MZ1024ECG064__) || defined(__PIC32MZ1024ECG064__)
# include <proc/PIC32MZ-EC/p32mz1024ecg064.h>
#elif defined(__32MZ1024ECG100__) || defined(__PIC32MZ1024ECG100__)
# include <proc/PIC32MZ-EC/p32mz1024ecg100.h>
#elif defined(__32MZ1024ECG124__) || defined(__PIC32MZ1024ECG124__)
# include <proc/PIC32MZ-EC/p32mz1024ecg124.h>
#elif defined(__32MZ1024ECG144__) || defined(__PIC32MZ1024ECG144__)
# include <proc/PIC32MZ-EC/p32mz1024ecg144.h>
#elif defined(__32MZ1024ECH064__) || defined(__PIC32MZ1024ECH064__)
# include <proc/PIC32MZ-EC/p32mz1024ech064.h>
#elif defined(__32MZ1024ECH100__) || defined(__PIC32MZ1024ECH100__)
# include <proc/PIC32MZ-EC/p32mz1024ech100.h>
#elif defined(__32MZ1024ECH124__) || defined(__PIC32MZ1024ECH124__)
# include <proc/PIC32MZ-EC/p32mz1024ech124.h>
#elif defined(__32MZ1024ECH144__) || defined(__PIC32MZ1024ECH144__)
# include <proc/PIC32MZ-EC/p32mz1024ech144.h>
#elif defined(__32MZ1024ECM064__) || defined(__PIC32MZ1024ECM064__)
# include <proc/PIC32MZ-EC/p32mz1024ecm064.h>
#elif defined(__32MZ1024ECM100__) || defined(__PIC32MZ1024ECM100__)
# include <proc/PIC32MZ-EC/p32mz1024ecm100.h>
#elif defined(__32MZ1024ECM124__) || defined(__PIC32MZ1024ECM124__)
# include <proc/PIC32MZ-EC/p32mz1024ecm124.h>
#elif defined(__32MZ1024ECM144__) || defined(__PIC32MZ1024ECM144__)
# include <proc/PIC32MZ-EC/p32mz1024ecm144.h>
#elif defined(__32MZ2048ECG064__) || defined(__PIC32MZ2048ECG064__)
# include <proc/PIC32MZ-EC/p32mz2048ecg064.h>
#elif defined(__32MZ2048ECG100__) || defined(__PIC32MZ2048ECG100__)
# include <proc/PIC32MZ-EC/p32mz2048ecg100.h>
#elif defined(__32MZ2048ECG124__) || defined(__PIC32MZ2048ECG124__)
# include <proc/PIC32MZ-EC/p32mz2048ecg124.h>
#elif defined(__32MZ2048ECG144__) || defined(__PIC32MZ2048ECG144__)
# include <proc/PIC32MZ-EC/p32mz2048ecg144.h>
#elif defined(__32MZ2048ECH064__) || defined(__PIC32MZ2048ECH064__)
# include <proc/PIC32MZ-EC/p32mz2048ech064.h>
#elif defined(__32MZ2048ECH100__) || defined(__PIC32MZ2048ECH100__)
# include <proc/PIC32MZ-EC/p32mz2048ech100.h>
#elif defined(__32MZ2048ECH124__) || defined(__PIC32MZ2048ECH124__)
# include <proc/PIC32MZ-EC/p32mz2048ech124.h>
#elif defined(__32MZ2048ECH144__) || defined(__PIC32MZ2048ECH144__)
# include <proc/PIC32MZ-EC/p32mz2048ech144.h>
#elif defined(__32MZ2048ECM064__) || defined(__PIC32MZ2048ECM064__)
# include <proc/PIC32MZ-EC/p32mz2048ecm064.h>
#elif defined(__32MZ2048ECM100__) || defined(__PIC32MZ2048ECM100__)
# include <proc/PIC32MZ-EC/p32mz2048ecm100.h>
#elif defined(__32MZ2048ECM124__) || defined(__PIC32MZ2048ECM124__)
# include <proc/PIC32MZ-EC/p32mz2048ecm124.h>
#elif defined(__32MZ2048ECM144__) || defined(__PIC32MZ2048ECM144__)
# include <proc/PIC32MZ-EC/p32mz2048ecm144.h>
/* PIC32MZ-EF */
#elif defined(__32MZ0512EFE064__) || defined(__PIC32MZ0512EFE064__)
# include <proc/PIC32MZ-EF/p32mz0512efe064.h>
#elif defined(__32MZ0512EFE100__) || defined(__PIC32MZ0512EFE100__)
# include <proc/PIC32MZ-EF/p32mz0512efe100.h>
#elif defined(__32MZ0512EFE124__) || defined(__PIC32MZ0512EFE124__)
# include <proc/PIC32MZ-EF/p32mz0512efe124.h>
#elif defined(__32MZ0512EFE144__) || defined(__PIC32MZ0512EFE144__)
# include <proc/PIC32MZ-EF/p32mz0512efe144.h>
#elif defined(__32MZ0512EFF064__) || defined(__PIC32MZ0512EFF064__)
# include <proc/PIC32MZ-EF/p32mz0512eff064.h>
#elif defined(__32MZ0512EFF100__) || defined(__PIC32MZ0512EFF100__)
# include <proc/PIC32MZ-EF/p32mz0512eff100.h>
#elif defined(__32MZ0512EFF124__) || defined(__PIC32MZ0512EFF124__)
# include <proc/PIC32MZ-EF/p32mz0512eff124.h>
#elif defined(__32MZ0512EFF144__) || defined(__PIC32MZ0512EFF144__)
# include <proc/PIC32MZ-EF/p32mz0512eff144.h>
#elif defined(__32MZ0512EFK064__) || defined(__PIC32MZ0512EFK064__)
# include <proc/PIC32MZ-EF/p32mz0512efk064.h>
#elif defined(__32MZ0512EFK100__) || defined(__PIC32MZ0512EFK100__)
# include <proc/PIC32MZ-EF/p32mz0512efk100.h>
#elif defined(__32MZ0512EFK124__) || defined(__PIC32MZ0512EFK124__)
# include <proc/PIC32MZ-EF/p32mz0512efk124.h>
#elif defined(__32MZ0512EFK144__) || defined(__PIC32MZ0512EFK144__)
# include <proc/PIC32MZ-EF/p32mz0512efk144.h>
#elif defined(__32MZ1024EFE064__) || defined(__PIC32MZ1024EFE064__)
# include <proc/PIC32MZ-EF/p32mz1024efe064.h>
#elif defined(__32MZ1024EFE100__) || defined(__PIC32MZ1024EFE100__)
# include <proc/PIC32MZ-EF/p32mz1024efe100.h>
#elif defined(__32MZ1024EFE124__) || defined(__PIC32MZ1024EFE124__)
# include <proc/PIC32MZ-EF/p32mz1024efe124.h>
#elif defined(__32MZ1024EFE144__) || defined(__PIC32MZ1024EFE144__)
# include <proc/PIC32MZ-EF/p32mz1024efe144.h>
#elif defined(__32MZ1024EFF064__) || defined(__PIC32MZ1024EFF064__)
# include <proc/PIC32MZ-EF/p32mz1024eff064.h>
#elif defined(__32MZ1024EFF100__) || defined(__PIC32MZ1024EFF100__)
# include <proc/PIC32MZ-EF/p32mz1024eff100.h>
#elif defined(__32MZ1024EFF124__) || defined(__PIC32MZ1024EFF124__)
# include <proc/PIC32MZ-EF/p32mz1024eff124.h>
#elif defined(__32MZ1024EFF144__) || defined(__PIC32MZ1024EFF144__)
# include <proc/PIC32MZ-EF/p32mz1024eff144.h>
#elif defined(__32MZ1024EFG064__) || defined(__PIC32MZ1024EFG064__)
# include <proc/PIC32MZ-EF/p32mz1024efg064.h>
#elif defined(__32MZ1024EFG100__) || defined(__PIC32MZ1024EFG100__)
# include <proc/PIC32MZ-EF/p32mz1024efg100.h>
#elif defined(__32MZ1024EFG124__) || defined(__PIC32MZ1024EFG124__)
# include <proc/PIC32MZ-EF/p32mz1024efg124.h>
#elif defined(__32MZ1024EFG144__) || defined(__PIC32MZ1024EFG144__)
# include <proc/PIC32MZ-EF/p32mz1024efg144.h>
#elif defined(__32MZ1024EFH064__) || defined(__PIC32MZ1024EFH064__)
# include <proc/PIC32MZ-EF/p32mz1024efh064.h>
#elif defined(__32MZ1024EFH100__) || defined(__PIC32MZ1024EFH100__)
# include <proc/PIC32MZ-EF/p32mz1024efh100.h>
#elif defined(__32MZ1024EFH124__) || defined(__PIC32MZ1024EFH124__)
# include <proc/PIC32MZ-EF/p32mz1024efh124.h>
#elif defined(__32MZ1024EFH144__) || defined(__PIC32MZ1024EFH144__)
# include <proc/PIC32MZ-EF/p32mz1024efh144.h>
#elif defined(__32MZ1024EFK064__) || defined(__PIC32MZ1024EFK064__)
# include <proc/PIC32MZ-EF/p32mz1024efk064.h>
#elif defined(__32MZ1024EFK100__) || defined(__PIC32MZ1024EFK100__)
# include <proc/PIC32MZ-EF/p32mz1024efk100.h>
#elif defined(__32MZ1024EFK124__) || defined(__PIC32MZ1024EFK124__)
# include <proc/PIC32MZ-EF/p32mz1024efk124.h>
#elif defined(__32MZ1024EFK144__) || defined(__PIC32MZ1024EFK144__)
# include <proc/PIC32MZ-EF/p32mz1024efk144.h>
#elif defined(__32MZ1024EFM064__) || defined(__PIC32MZ1024EFM064__)
# include <proc/PIC32MZ-EF/p32mz1024efm064.h>
#elif defined(__32MZ1024EFM100__) || defined(__PIC32MZ1024EFM100__)
# include <proc/PIC32MZ-EF/p32mz1024efm100.h>
#elif defined(__32MZ1024EFM124__) || defined(__PIC32MZ1024EFM124__)
# include <proc/PIC32MZ-EF/p32mz1024efm124.h>
#elif defined(__32MZ1024EFM144__) || defined(__PIC32MZ1024EFM144__)
# include <proc/PIC32MZ-EF/p32mz1024efm144.h>
#elif defined(__32MZ2048EFG064__) || defined(__PIC32MZ2048EFG064__)
# include <proc/PIC32MZ-EF/p32mz2048efg064.h>
#elif defined(__32MZ2048EFG100__) || defined(__PIC32MZ2048EFG100__)
# include <proc/PIC32MZ-EF/p32mz2048efg100.h>
#elif defined(__32MZ2048EFG124__) || defined(__PIC32MZ2048EFG124__)
# include <proc/PIC32MZ-EF/p32mz2048efg124.h>
#elif defined(__32MZ2048EFG144__) || defined(__PIC32MZ2048EFG144__)
# include <proc/PIC32MZ-EF/p32mz2048efg144.h>
#elif defined(__32MZ2048EFH064__) || defined(__PIC32MZ2048EFH064__)
# include <proc/PIC32MZ-EF/p32mz2048efh064.h>
#elif defined(__32MZ2048EFH100__) || defined(__PIC32MZ2048EFH100__)
# include <proc/PIC32MZ-EF/p32mz2048efh100.h>
#elif defined(__32MZ2048EFH124__) || defined(__PIC32MZ2048EFH124__)
# include <proc/PIC32MZ-EF/p32mz2048efh124.h>
#elif defined(__32MZ2048EFH144__) || defined(__PIC32MZ2048EFH144__)
# include <proc/PIC32MZ-EF/p32mz2048efh144.h>
#elif defined(__32MZ2048EFM064__) || defined(__PIC32MZ2048EFM064__)
# include <proc/PIC32MZ-EF/p32mz2048efm064.h>
#elif defined(__32MZ2048EFM100__) || defined(__PIC32MZ2048EFM100__)
# include <proc/PIC32MZ-EF/p32mz2048efm100.h>
#elif defined(__32MZ2048EFM124__) || defined(__PIC32MZ2048EFM124__)
# include <proc/PIC32MZ-EF/p32mz2048efm124.h>
#elif defined(__32MZ2048EFM144__) || defined(__PIC32MZ2048EFM144__)
# include <proc/PIC32MZ-EF/p32mz2048efm144.h>
/* PIC32MZ-W */
#elif defined(__32MZ1025W104132__) || defined(__PIC32MZ1025W104132__)
# include <proc/PIC32MZ-W/p32mz1025w104132.h>
#elif defined(__32MXGENERIC__)
#  include <proc/p32mxgeneric.h>
#else
#  error Unknown processor!
#endif

#ifdef __LANGUAGE_ASSEMBLY__
/*
 * Conventional register names.
 */

/* Zero register:  Always returns 0 */
#define zero               $0

/* Assembler temporary register:  Reserved for use by the assembler */
#define at_reg             $1
#define AT_reg             $1

/* Return value registers:  Value returned by subroutine */
#define v0                 $2
#define v1                 $3

/* Argument registers:  First few parameters for a subroutine */
#define a0                 $4
#define a1                 $5
#define a2                 $6
#define a3                 $7

/* Subroutine register temporaries:  Registers that subroutines can use
 * without saving
 */
#define t0                 $8
#define t1                 $9
#define t2                 $10
#define t3                 $11
#define t4                 $12
#define t5                 $13
#define t6                 $14
#define t7                 $15
#define t8                 $24
#define t9                 $25

/* Subroutine register variables:  A subroutine that writes one of these
 * must save the old value and restore it before it exists, so the calling
 * routine sees the values preserved
 */
#define s0                 $16
#define s1                 $17
#define s2                 $18
#define s3                 $19
#define s4                 $20
#define s5                 $21
#define s6                 $22
#define s7                 $23

/* Ninth subroutine register variable:  Can either be used as above or
 * as the frame pointer for functions that require one
 */
#define s8                 $30
#define fp                 $30

/* Interrupt/Trap handler registers:  Reserved for use by interrupt/trap
 * handler.  May change under your feet!
 */
#define k0                 $26
#define k1                 $27

/* Global pointer register:  Gives easy access to (some) `static' or `extern'
 * variables
 */
#define gp                 $28

/* Stack pointer register:  Stack pointer */
#define sp                 $29

/* Return address register:  Contains the return address for the subroutine */
#define ra                 $31
#endif

#if defined (__LANGUAGE_C__) || defined (__LANGUAGE_C_PLUS_PLUS__)

#if defined(__XC32_VERSION) && (__XC32_VERSION >= 2490)
#include <pic32m_builtins.h>
#endif

/*
 * __XC_UART selects the default UART port that read() and write() will use.
 * read() is called by fscanf and family, while write() is called by printf
 * and family.
 */
extern int __XC_UART;

/* 
 * When __DEBUG is defined, __debug_break() resolves to an MPLAB XC32 builtin 
 * function, which creates a MIPS32 software debug-breakpoint (sddbp 0) 
 * instruction.
 */
/* #if defined(__DEBUG)
 *  #define __debug_break() __builtin_software_breakpoint()
 * #else
 *  #define __debug_break() ((void)0)
 * #endif
 */

typedef unsigned long _reg_t;

/*
 * Inline assembly macros
 */

#ifndef _nop
#ifdef __mips16
#define _nop()  __asm__ __volatile__ (" move $0,$16" : :) 
#else
#define _nop()  __asm__ __volatile__ ("%(ssnop%)" : :) 
#endif
#endif

#ifndef Nop
/* Consider using _nop rather than Nop */
#define Nop()  _nop()
#endif

#ifndef _ehb
#define _ehb()  __asm__ __volatile__ ("%(ehb%)" : :) 
#endif

#ifdef __mips16
extern void __attribute__((__nomips16__)) _sync(void);
#else
#define _sync() __asm__ __volatile__ ("sync" : : : "memory")
#endif

#define _wait() __asm__ __volatile__ ("wait")

#if defined(__GCC_HAVE_BUILTIN_MIPS_CACHE) && defined(__PIC32_HAS_L1CACHE)
#  define _cache(op,addr)      __builtin_mips_cache(op,addr)
#else /* _cache() */
#  define _cache(op,addr)      _Pragma("message (\"Warning - Using _cache(op,addr) on an uncached target device\")")
#endif /* _cache */

#if defined(__PIC32_HAS_L1CACHE)
#  define _synci(x) __extension__({ \
       __asm__ ("synci %a0" :: "d" (x)); \
   })
#else /* _synci */
#  define _synci(addr)         _Pragma("message (\"Warning - Using _synci(addr) on an uncached target device\")")
#endif /* _synci */

#if defined(__PIC32_HAS_L1CACHE)
#  define _prefetch(hint,x) __extension__({ \
      __asm__ ("pref %0, %a1" :: "JYA" (hint), "d" (x) : "memory"); \
   })
#else /* _prefetch */
#  define _prefetch(hint,addr) _Pragma("message (\"Warning - Using _prefetch(hint,addr) on an uncached target device\")")
#endif /* _prefetch */

#define _mfc0(rn, sel)            __builtin_mfc0(rn,sel)
#define _mtc0(rn, sel, v)         __builtin_mtc0(rn,sel,v)
/* exchange (swap) VAL and CP0 register REG,SEL */
#define _mxc0(rn, sel, v)         __builtin_mxc0(rn,sel,v)
/* bit clear non-zero bits from CLR in CP0 register REG,SEL */
#define _bcc0(rn, sel, clr)       __builtin_bcc0(rn,sel,clr)
/* bit set non-zero bits from SET in CP0 register REG,SEL */
#define _bsc0(rn, sel, set)       __builtin_bsc0(rn,sel,set)
/* bit clear non-zero bits from CLR and set non-zero bits from SET in REG,SEL */
#define _bcsc0(rn, sel, clr, set) __builtin_bcsc0(rn,sel,clr,set)

/* count leading zeroes */
#define _clz(x) __builtin_clz (x)

/* count trailing zeroes */
#define _ctz(x) __builtin_ctz (x)

#if ! __mips16
/* count leading ones */
#define _clo(x) __extension__({ \
    unsigned int __x = (x); \
    unsigned int __v; \
    __asm__ ("clo %0,%1" : "=d" (__v) : "d" (__x)); \
    __v; \
})

/* Simulate 64-bit count leading zeroes */
#define _dclz(x) __extension__({ \
    unsigned long long __x = (x); \
    unsigned int __hx = (__x >> 32); \
    __hx ? _clz(__hx) : 32 + _clz(__x); \
})

/* Simulate 64-bit count leading ones */
#define _dclo(x) __extension__({ \
    unsigned long long __llx = (x); \
    unsigned int __hx = (__llx >> 32); \
    (~__hx) ? _clo(__hx) : 32 + _clo(__llx); \
})

/* Simulate 64-bit count trailing zeroes */
#define _dctz(x) __extension__({ \
    unsigned long long __dx = (x); \
    unsigned int __ldx = __dx; \
    unsigned int __hdx = __dx >> 32; \
    __ldx ? _ctz(__ldx) : (63 ^ _clz(__hdx & -__hdx)); \
   })

/* MIPS32r2 wsbh opcode */
#define _wsbh(x) __extension__({ \
    unsigned int __x = (x), __v; \
    __asm__ ("wsbh %0,%1" \
             : "=d" (__v) \
             : "d" (__x)); \
    __v; \
})

/* MIPS32r2 byte-swap word */
#define _bswapw(x) __extension__({ \
    unsigned int __x = (x), __v; \
    __asm__ ("wsbh %0,%1; rotr %0,16" \
             : "=d" (__v) \
             : "d" (__x)); \
    __v; \
})

/* MIPS32r2 insert bits */
#define _ins(tgt,val,pos,sz) __extension__({ \
    unsigned int __t = (tgt), __v = (val); \
    __asm__ ("ins %0,%z1,%2,%3" \
             : "+d" (__t) \
             : "dJ" (__v), "I" (pos), "I" (sz)); \
    __t; \
})

/* MIPS32r2 extract bits */
#define _ext(x,pos,sz) __extension__({ \
    unsigned int __x = (x), __v; \
    __asm__ ("ext %0,%z1,%2,%3" \
             : "=d" (__v) \
             : "dJ" (__x), "I" (pos), "I" (sz)); \
    __v; \
})

/* MIPS32r2 jr.hb */
#define _jr_hb() __asm__ __volatile__( \
       "bltzal  $0,0f\n"               \
"0:     addiu   $31,1f-0b\n"           \
"       jr.hb   $31\n"                 \
"1:"                                   \
        : : : "$31")

/* MIPS32r2 write previous gpr */
#define _wrpgpr(regno, val) \
do { \
    __asm __volatile__ ("wrpgpr $%0,%z1" \
                        : /* no outputs */ \
                        : "JK" (regno), "dJ" (val)); \
} while (0)

/* MIPS32r2 read previous gpr */
#define _rdpgpr(regno) \
__extension__({ \
    _reg_t __val; \
    __asm __volatile__ ("rdpgpr %0,$%1" \
                        : "=d" (__val) \
                        : "JK" (regno)); \
    __val; \
})

/* MIPS32r2 set SRSCtl.PSS (previous shadow set), returning old value */
extern unsigned int _xchsrspss (unsigned int);
#endif

#define _get_byte(addr, errp)   (*(volatile unsigned char *)(addr))
#define _get_half(addr, errp)   (*(volatile unsigned short *)(addr))
#define _get_word(addr, errp)   (*(volatile unsigned int *)(addr))
#define _get_dword(addr, errp)  (*(volatile unsigned long long *)(addr))

#define _put_byte(addr, v)      (*(volatile unsigned char *)(addr)=(v), 0)
#define _put_half(addr, v)      (*(volatile unsigned short *)(addr)=(v), 0)
#define _put_word(addr, v)      (*(volatile unsigned int *)(addr)=(v), 0)
#define _put_dword(addr, v)     (*(volatile unsigned long long *)(addr)=(v), 0)
#endif

#include <cp0defs.h>

#if defined (__LANGUAGE_C__) || defined (__LANGUAGE_C_PLUS_PLUS__)
#  include <sys/appio.h>
#  include <sys/l1cache.h>
#endif

#endif

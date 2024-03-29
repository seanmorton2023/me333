/*
 * ****************************Begin Copyright 1D**********************************
 * Unpublished work (c) MIPS Technologies, Inc.  All rights reserved.
 * Unpublished rights reserved under the copyright laws of the United States
 * of America and other countries.
 * 
 * This code is confidential and proprietary to MIPS Technologies, Inc. ("MIPS
 * Technologies") and  may be disclosed only as permitted in writing by MIPS
 * Technologies or an authorized third party.  Any copying, reproducing,
 * modifying, use or disclosure of this code (in whole or in part) that is not
 * expressly permitted in writing by MIPS Technologies or an authorized third
 * party is strictly prohibited.  At a minimum, this code is protected under
 * trade secret, unfair competition, and copyright laws.  Violations thereof
 * may result in criminal penalties and fines.
 * 
 * MIPS Technologies reserves the right to change this code to improve function,
 * design or otherwise.  MIPS Technologies does not assume any liability arising
 * out of the application or use of this code, or of any error or omission in
 * such code.  Any warranties, whether express, statutory, implied or otherwise,
 * including but not limited to the implied warranties of merchantability or 
 * fitness for a particular purpose, are excluded.  Except as expressly provided
 * in any written license agreement from MIPS Technologies or an authorized third
 * party, the furnishing of this code does not give recipient any license to any
 * intellectual property rights, including any patent rights, that cover this code.
 * 
 * This code shall not be exported or transferred for the purpose of reexporting
 * in violation of any U.S. or non-U.S. regulation, treaty, Executive Order, law,
 * statute, amendment or supplement thereto.
 * 
 * This code may only be disclosed to the United States government ("Government"),
 * or to Government users, with prior written consent from MIPS Technologies or an
 * authorized third party.  This code constitutes one or more of the following:
 * commercial computer software, commercial computer software documentation or
 * other commercial items.  If the user of this code, or any related documentation
 * of any kind, including related technical data or manuals, is an agency,
 * department, or other entity of the Government, the use, duplication,
 * reproduction, release, modification, disclosure, or transfer of this code, or
 * any related documentation of any kind, is restricted in accordance with Federal
 * Acquisition Regulation 12.212 for civilian agencies and Defense Federal
 * Acquisition Regulation Supplement 227.7202 for military agencies.  The use of
 * this code by the Government is further restricted in accordance with the terms
 * of the license agreement(s) and/or applicable contract terms and conditions
 * covering this code from MIPS Technologies or an authorized third party.
 * *******************************End Copyright************************************
 */

#include "dsplib_video.h"


/* Inverse quantization coefficients per 8.5.5 of JVT-G050 (JVT:8.5.5). */

int16 mips_h264_iq_coeffs[6][4][4] =
{
	{{10, 13, 10, 13}, {13, 16, 13, 16}, {10, 13, 10, 13}, {13, 16, 13, 16}},
	{{11, 14, 11, 14}, {14, 18, 14, 18}, {11, 14, 11, 14}, {14, 18, 14, 18}},
	{{13, 16, 13, 16}, {16, 20, 16, 20}, {13, 16, 13, 16}, {16, 20, 16, 20}},
	{{14, 18, 14, 18}, {18, 23, 18, 23}, {14, 18, 14, 18}, {18, 23, 18, 23}},
	{{16, 20, 16, 20}, {20, 25, 20, 25}, {16, 20, 16, 20}, {20, 25, 20, 25}},
	{{18, 23, 18, 23}, {23, 29, 23, 29}, {18, 23, 18, 23}, {23, 29, 23, 29}}
};


/* Precompute an inverse quantization matrix */

void mips_h264_iqt_setup(int16 iq[4][4], int16 q[6][4][4], int16 qp)
{
	int i;

	int qp6  = qp / 6;
	int qp6r = qp % 6;

	/* note: qp / 6 can be computed as: */
	/*   qp / 6 = (43 * qp) >> 8 = (171 * qp) >> 10 */

	for (i = 0; i < 4; i++)
	{
		iq[i][0] = q[qp6r][i][0] << qp6;
		iq[i][1] = q[qp6r][i][1] << qp6;
		iq[i][2] = q[qp6r][i][2] << qp6;
		iq[i][3] = q[qp6r][i][3] << qp6;
	}
}


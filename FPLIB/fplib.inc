;=============================================================================
; Module        : FPLIB.INC
; Version       : V0.1  07-jun-2010
; Author        : Michel Bernard - mailto:michel.bernard@advalvas.be
; Object        : Single Precision Floating Point Math Library
; Requires	: INOUT - Serial I/O Comms Library
; Target        : 8051 family
; Assembler	: Micro Series 8051 Assembler 2.02/DOS - IAR 1990
; Copyright (c) 2010 GmE Belgium - All Rights Reserved
;		: Redistribution and use in source and binary forms, with or 
;		: without modification, are permitted provided that the 
;		: following conditions are met:
;		: 1. Redistributions of source code must retain the above 
;		: copyright notice, this list of conditions and the following 
;		: disclaimer.
;		: 2. Redistributions in binary form must reproduce the above 
;		: copyright notice, this list of conditions and the following 
;		: disclaimer in the documentation and/or other materials 
;		: provided with the distribution.
;		: 3. The name of the author may not be used to endorse or 
;		: promote products derived from this software without specific 
;		: prior written permission.
; Disclaimer	: This software is in its early alpha stage.  It's not meant 
;		: to be used for production code, and the API might change in 
;		: the future.  Despite this, it might be useful in some 
;		: situations and you are encouraged to try it by yourself. 
;		: Suggestions, bug-reports and even better patches are welcome.
;		: THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS 
;		: OR IMPLIED WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR 
;		: GmE MAKES ANY REPRESENTATION OR WARRANTY OF ANY KIND 
;		: CONCERNING THE MERCHANTABILITY OF THIS SOFTWARE OR ITS 
;		: FITNESS FOR ANY PARTICULAR PURPOSE.
;=============================================================================



	extern	fp_version		;fplib version string
	extern	fp_copyright		;fplib copyright string

	extern	fp_setstobuf		;init storage buffer (xdata)
	extern	fp_setstrbuf		;init string buffer (xdata)

	extern	fp_run_pc		;run fp code at current pc location
	extern	fp_run_cdptr		;run fp code at dptr (code memory)
	extern	fp_run_xdptr		;run fp code at dptr (xdata memory)

	extern	wr_acc			;write character to buffer
	extern	wr_cdptr		;write code string to buffer
	extern	outstrbuf		;send string buffer to console
	extern	rwdstrbuf		;rewind string buffer
	extern	clrstrbuf		;clear string buffer
	extern	instrbuf		;read string from terminal to string buffer; rewind buffer
	extern	rd_acc			;read char from string buffer (strbufptr incremented if char not null)
	extern	writefp			;write fp value @r0 to string buffer
	extern	readfp			;read fp value @r0 from string buffer

	extern	testfp			;Unpack and test value @r0
	extern	addfp			;Addition of values @r0 and @r1, result @r0
	extern	subfp			;Subtraction of value @r0 with value @r1, result @r0
	extern	chsfp			;change sign of packed value @r0
	extern	intfp			;integer portion of value @r0
	extern	fracfp			;fractional portion of value @r0
	extern	mulfp			;Multiply value @r0 by value @r1
	extern	divfp			;Divide value @r0 by value @r1
	extern	invfp			;Inverse of value @r0
	extern	sqrtfp			;Square root of value @r0
	extern	pow2fp			;Square of value @r0
	extern	lnfp			;Natural logarithm of value @r0
	extern	logfp			;Base 10 logarithm of value @r0
	extern	expfp			;exponential of value @r0
	extern	sinfp			;sine of value @r0
	extern	cosfp			;cosine of value @r0
	extern	tanfp			;tangent of value @r0
	extern	atanfp			;arctangent of value @r0
	extern	asinfp			;arcsine of value @r0
	extern	acosfp			;arccosine of value @r0
	extern	powfp			;exponentiation of value @r0 by value @r1
	extern	pifp			;load PI
	extern	efp			;load E
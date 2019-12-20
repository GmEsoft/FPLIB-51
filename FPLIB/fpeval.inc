;=============================================================================
; Module        : FPEVAL.INC
; Version       : V0.1  07-jun-2010
; Author        : Michel Bernard - mailto:michel.bernard@advalvas.be
; Object        : Mathematic Formula Evaluation
; Requires	: FPLIB - Single Precision Floating Point Math Library
;		  INOUT - Serial I/O Comms Library
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
;
;
	extern	fpeval			;evaluate expressions

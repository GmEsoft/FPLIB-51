;=============================================================================
; Header	: FPMACROS.INC
; Version       : V0.1  07-jun-2010
; Author        : Michel Bernard
; Object        : Macros language definition for FPLIB using FP opcodes
; Requires	: FPLIB - Single Precision Floating Point Math Library
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


	macro	%nop
	db	00h
	endmac
	
	macro	%ret
	db	01h
	endmac
	
	macro	%call
	db	02h
	db	high \0
	db	low \0
	endmac
	
	macro	%push
	db	03h
	endmac
	
	macro	%stox
	db	04h
	db	high \0
	db	low \0
	endmac
	
	macro	%rclx
	db	05h
	db	high \0
	db	low \0
	endmac
	
	macro	%swap
	db	06h
	endmac
	
	macro	%rldn
	db	07h
	endmac
	
	macro	%add
	db	08h
	endmac
	
	macro	%sub
	db	09h
	endmac
	
	macro	%mul
	db	0Ah
	endmac
	
	macro	%div
	db	0Bh
	endmac
	
	macro	%pow
	db	0Ch
	endmac
	
	macro	%chs
	db	0Dh
	endmac
	
	macro	%inv
	db	0Eh
	endmac
	
	macro	%lastx
	db	0Fh
	endmac
	
	macro	%input
	db	10h
	endmac
	
	macro	%write
	db	11h
	db	\0,0
	endmac
	
	macro	%prompt
	db	12h
	endmac
	
	macro	%readx
	db	13h
	endmac
	
	macro	%writex
	db	14h
	endmac
	
	macro	%ln
	db	15h
	endmac
	
	macro	%exp
	db	16h
	endmac
	
	macro	%sin
	db	17h
	endmac
	
	macro	%cos
	db	18h
	endmac
	
	macro	%tan
	db	19h
	endmac
	
	macro	%asin
	db	1Ah
	endmac
	
	macro	%acos
	db	1Bh
	endmac
	
	macro	%atan
	db	1Ch
	endmac
	
	macro	%log
	db	1Dh
	endmac
	
	macro	%pow2
	db	1Eh
	endmac
	
	macro	%sqrt	
	db	1Fh
	endmac
	
	macro	%enter
	db	20h
	dd	"\0
	endmac

	macro	%aclear
	db	21h
	endmac

	macro	%clear
	db	22h
	endmac

	macro	%print
	db	23h
	endmac

	macro	%int
	db	24h
	endmac
	
	macro	%frac
	db	25h
	endmac

	macro	%sto
	db	26h
	db	\0
	endmac
	
	macro	%rcl
	db	27h
	db	\0
	endmac
	
	macro	%cint
	db	28h
	endmac
	
	macro	%pi
	db	29h
	endmac
	
	macro	%e
	db	2Ah
	endmac
	
	macro	%stow
	db	2Bh
	db	\0
	endmac
	
	macro	%rclw
	db	2Ch
	db	\0
	endmac

	macro	%cmp
	db	2Dh
	endmac

	macro	%jmp
	db	2Eh
	db	high \0
	db	low \0
	endmac

	macro	%jc
	db	2Fh
	db	high \0
	db	low \0
	endmac

	macro	%jnc
	db	30h
	db	high \0
	db	low \0
	endmac

	macro	%jz
	db	31h
	db	high \0
	db	low \0
	endmac

	macro	%jnz
	db	32h
	db	high \0
	db	low \0
	endmac

	macro	%je
	db	33h
	db	high \0
	db	low \0
	endmac

	macro	%jne
	db	34h
	db	high \0
	db	low \0
	endmac

	macro	%djnz
	db	35h
	db	\0
	db	high \1
	db	low \1
	endmac

	macro	%test
	db	36h
	endmac

	macro	%fmt
	db	37h
	db	\0
	endmac

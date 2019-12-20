;=============================================================================
; Module        : XMACRO.INC
; Version       : V0.1  07-jun-2010
; Author        : Michel Bernard - mailto:michel.bernard@advalvas.be
;		: macro instructions set for
;		: 	- easy register bank switching
;		: 		%pushregs, %popregs
;		: 	- long conditional jumps
;		: 		%ljz, %ljnz, %djnz, ...
;		: 	- bitwise exclusive or
;		: 		%xrl
; Requires	: 
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



;_______________________________________________
;syntax :       %decdptr
;purpose:       decrement dptr
;
        macro   %decdptr
        xch     a,dpl
        add     a,#0FFh
        xch     a,dpl
        xch     a,dph
        addc    a,#0FFh
        xch     a,dph
        endmac
;

;_______________________________________________
;syntax :       %pushregs
;purpose:       push psw to stack and select next register bank
        macro   %pushregs
        push    psw
        xch     a,psw
        add     a,#00001000b
        xch     a,psw
        endmac

;_______________________________________________
;syntax :       %popregs
;purpose:       pop psw from stack and restore bank selection

        macro   %popregs
        pop     psw
        endmac

;_______________________________________________
;syntax :       %ljnz   label
;purpose:       conditional long jump

        macro   %ljnz
        jz      $+5
        ljmp    \0
        endmac

;_______________________________________________
;syntax :       %ljz    label
;purpose:       conditional long jump

        macro   %ljz
        jnz     $+5
        ljmp    \0
        endmac

;_______________________________________________
;syntax :       %ljnc   label
;purpose:       conditional long jump

        macro   %ljnc
        jc      $+5
        ljmp    \0
        endmac

;_______________________________________________
;syntax :       %ljc    label
;purpose:       conditional long jump

        macro   %ljc
        jnc     $+5
        ljmp    \0
        endmac

;_______________________________________________
;syntax :       %ljb    bit,label
;purpose:       conditional long jump

        macro   %ljb
        jnb     \0,$+6
        ljmp    \1
        endmac

;_______________________________________________
;syntax :       %ljnb   bit,label
;purpose:       conditional long jump

        macro   %ljnb
        jb      \0,$+6
        ljmp    \1
        endmac

;_______________________________________________
;syntax :       %ldjnz  reg,label
;purpose:       conditional long jump

        macro   %ldjnz
        djnz    \0,$+5
        sjmp    $+6
        nop                             ;for use of macro with R0-R7
        ljmp    \1
        endmac

;_______________________________________________
;syntax :       %xrl	c,bit
;purpose:       bitwise exclusive or
	
	macro	%xrl
	
	jnb	\1,$+4
	cpl	\0
	
	endmac



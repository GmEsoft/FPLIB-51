;=============================================================================
; Module        : INOUT.INC
; Version       : V0.1  07-jun-2010
; Author        : Michel Bernard - mailto:michel.bernard@advalvas.be
; Object        : Common Serial Input/Output routines
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

USE_FLAGS equ	1
USE_LINKS equ	1
;code
	extern	inout_init		;initialize module statics
        extern  outacc                  ;output single char in 'acc' using out enable flag and vector
        extern  outaccf                 ;output single char in 'acc' to v24 only, fast
        extern  outcrlf                 ;output newline
        extern  outcdptr                ;output zstring in code memory @ dptr
        extern  outxdptr                ;output zstring in xdata memory @ dptr
        extern  outcsp                  ;output zstring in code memory @ (sp) and
                                        ; set (sp) to next byte
        extern  outhexacc               ;output 'acc' as hex string (2 digits)
        extern  outdecacc               ;output 'acc' as dec string (2 or 3 digits)
        extern  outhexdptr              ;output 'dptr' as hex string (4 digits)
        extern  outdecdptr              ;output 'dptr' as dec string (5 digits)
        extern  outblk                  ;output single white space
        extern  outcinddptr             ;output a-th string in table in code memory
                                        ; @ DPTR to V24 line
        extern  outdatedptr             ;Output packed date in DPTR
        extern  outtimehmdptr           ;Output packed time in DPTR
        extern  inaccxmodem             ;read char in 'acc' using XMODEM timeout
        extern  chkinacc                ;check for input and read char in 'acc' using terminal timeout & XON/XOFF
        extern  inacc                   ;read char in 'acc' using terminal timeout
if USE_FLAGS
        extern  inaccret                ;use to identify 'restart' cause
endif
        extern  inxdptr                 ;read zstring in xdata memory @ dptr without echo
        extern  inxdptre                ;read zstring in xdata memory @ dptr with echo
        extern  inxdptreu               ;Input upper-case string to address pointed by
                                        ; DPTR (terminated by null)
        extern  inhexacc                ;read 'acc' from input as hex string
        extern  strmatchcsp             ;Compare string pointed by DPTR with string
                                        ; pointed by @(SP:SP+1)
        extern  strmatchchar            ;Compare character pointed by DPTR in XDATA with
                                        ; character following the call instruction
        extern  strmatchxr20            ;Compare string pointed by DPTR with string
                                        ; pointed by R2:R0
        extern  strskip                 ;Skip to blank or NUL in zstring in xdata memory @ 'dptr'
        extern  strskipblk              ;Skip blanks in zstring in xdata memory @ 'dptr'
        extern  strskiphex              ;Skip hex digits in zstring in xdata memory @ 'dptr'
        extern  strtoupper              ;Convert zstring in xdata memory @ 'dptr' to
                                        ; upper case
        extern  readhexacc              ;Read hexadecimal digits from string @DPTR in XDATA
                                        ; to 'acc'
        extern  readhexdptr             ;Read hexadecimal digits from string @DPTR in XDATA
                                        ; to 'dptr'
        extern  readdecacc              ;Read decimal digits from string @DPTR in XDATA
                                        ; to 'acc'
        extern  readsdecdptr            ;Read signed decimal digits from string @DPTR in XDATA
                                        ; to 'dptr'
        extern  readdecdptr             ;Read decimal digits from string @DPTR in XDATA
                                        ; to 'dptr'
        extern  readcindacc             ;Read position of string pointed by R2:R0 in
                                        ; table pointed by DPTR
        extern  readtimehmdptr          ;Read time (H:M) in 16 bits from string @DPTR in
                                        ; XDATA to 'dptr' (HH*60+MM)
        extern  readdatedptr            ;Read date in 16 bits from string @DPTR in XDATA
                                        ; to 'dptr' ((YYYY-1980)*16+MM)*32+DD
        extern  isdigitxdptr            ;Test if x-memory character pointed by DPTR is a
                                        ; digit
        extern  memcpyc                 ;Copy memory from CODE (DPTR to R3:R1) to
                                        ; XDATA (R2:R0)
        extern  memcpy                  ;Copy memory from XDATA (DPTR to R3:R1) to
                                        ; XDATA (R2:R0)
        extern  strcpy                  ;Copy zstring from XDATA (DPTR) to XDATA (R2:R0)
        extern  strcpyc                 ;Copy zstring from CODE (DPTR) to XDATA (R2:R0)
        extern  writedecacc             ;write 'acc' as dec string (2 or 3 digits) @r2:r0
        extern  incr20                  ;R2:R0 ++
        extern  incr31                  ;R3:R1 ++
        extern  cmpr20                  ;DPTR  =? R2:R0 (Z, C, ACC)
        extern  cmpr31                  ;DPTR  =? R3:R1 (Z, C, ACC)
        extern  cmpr20r31               ;R2:R0 =? R3:R1 (Z, C, ACC)
        extern  cmpba                   ;DPTR  =? B:A   (Z, C, ACC)
        extern  addba                   ;DPTR  += B:A
        extern  addr20                  ;DPTR  += R2:R0
        extern  addr31                  ;DPTR  += R3:R1
        extern  adddptr                 ;DPTR  += DPTR (or DPTR *= 2)
        extern  subbr20                 ;DPTR  -= R2:R0 + C
        extern  incxdptr16              ;x@(DPTR):x@(DPTR+1) ++
        extern  divb                    ;DPTR  /= B ; B = DPTR mod B
        extern  divr20                  ;DPTR  /= R2:R0 ; R2:R0 = DPTR mod R2:R0
        extern  div32s                  ;dptr:r3:r1, r2:r0 = dptr:r3:r1 / r2:r0
        extern  xxstart                 ;Start XMODEM transmission
        extern  xxblock                 ;Send XMODEM 128-byte block
        extern  xxcrcblock              ;Send XMODEM 128-byte or 1k crc16/cksum block
        extern  xxend                   ;End XMODEM transmission
        extern  xxcheck                 ;Check XMODEM transmission

;data

if USE_FLAGS
        extern  binacctime
        extern  boutenable
        extern  bechocmd
endif

if USE_LINKS
	extern	uo_vec			;user output routine vector
endif

cr      equ     0Dh
lf      equ     0ah

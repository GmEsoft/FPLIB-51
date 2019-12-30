FPLIB-51
========

Experimental MCS-51 Family Single Precision Floating Point Math Library
-----------------------------------------------------------------------

This project is a free implementation of single precision floating-point math routines for the MCS-51 family of micro-controllers.

The project contains the following assembly source files:
- `INOUT.S03`: terminal I/O routines.
- `FPLIB.S03`: the floating-point math routines and FP Executive;
- `FPEVAL.S03`: a math expression parser and evaluator;
- `FPTEST.S03`: a sample test program;


FP executive
------------
The FP Executive is a calculator that performs FP calculations specified by a sequence of P-Code instructions each specifying the math operation or function call. The operations are performed using reverse Polish notation and a stack of 4 registers X, Y, Z and T.

The sequence of instructions can be stored either in CODE memory (called using `call fp_run_pc` if the sequence immediately follows this call, or using `call fp_run_cdptr` where the sequence is pointed by DPTR) or in XDATA memory (called using `call fp_run_xdptr` where the sequence is pointed by DPTR). This sequence is terminated with `%ret`, and the control returns to the calling program.

The P-Code statements are:

| P-Code      | Operation                                                                                      |
| ----------  | ---------------------------------------------------------------------------------------------- |
| `%nop`      | NOP:    No operation                                                                           |
| `%ret`      | RET:    Return to caller / End of P-Code sequence                                              |
| `%call a`   | CALL:   call procedure at given address                                                        |
| `%push`     | PUSH:   Push X on stack push X on stack	(roll stack up, keeping X)                             |
| `%stox a`   | STOX:   store X to xdata memory at given address                                               |
| `%rclx a`   | RCLX:   recall from xdata memory at given address to X (roll stack up)                         |
| `%swap`     | SWAP:   swap X and Y values                                                                    |
| `%rldn`     | RLDN:   roll stack down (T -> Z -> Y -> X -> T)                                                |
| `%add`      | ADD:    X <- Y + X; Y <- Z; Z <- T                                                             |
| `%sub`      | SUB:    X <- Y - X; Y <- Z; Z <- T                                                             |
| `%mul`      | MUL:    X <- Y * X; Y <- Z; Z <- T                                                             |
| `%div`      | DIV:    X <- Y / X; Y <- Z; Z <- T                                                             |
| `%pow`      | POW:    X <- Y ^ X; Y <- Z; Z <- T                                                             |
| `%chs`      | CHS:    X <- -X                                                                                |
| `%inv`      | INV:    X <- 1 / X                                                                             |
| `%lastx`    | LASTX:  T <- Z; Z <- Y; Y <- X; X <- LASTX                                                     |
| `%input`    | INPUT:  T <- Z; Z <- Y; Y <- X; X <- user input                                                |
| `%write s`  | WRITE:  write text to string buffer until null char                                            |
| `%prompt`   | PROMPT: write string from string buffer to terminal and wait user input                        |
| `%readx`    | READX:  T <- Z; Z <- Y; Y <- X; X <- value in string buffer                                    |
| `%writex`   | WRITEX: print X to string buffer                                                               |
| `%ln`       | LN:     X <- ln(X)                                                                             |
| `%exp`      | EXP:    X <- exp(X)                                                                            |
| `%sin`      | SIN:    X <- sin(X)                                                                            |
| `%cos`      | COS:    X <- cos(X)                                                                            |
| `%tan`      | TAN:    X <- tan(X)                                                                            |
| `%asin`     | ASIN:   X <- asin(X)                                                                           |
| `%acos`     | ACOS:   X <- acos(X)                                                                           |
| `%atan`     | ATAN:   X <- atan(X)                                                                           |
| `%log`      | LOG:    X <- log(X)                                                                            |
| `%pow2`     | POW2:   X <- X * X                                                                             |
| `%sqrt`     | SQRT:   X <- sqrt(x)                                                                           |
| `%enter f`  | ENTER:  T <- Z; Z <- Y; Y <- X; X <- immediate value                                           |
| `%aclear`   | ACLEAR: clear string buffer                                                                    |
| `%clear`    | CLEAR:  X <- 0; Y <- 0; Z <- 0; T <- 0                                                         |
| `%print`    | PRINT:  print string to terminal                                                               |
| `%int`      | INT:    integer portion                                                                        |
| `%frac`     | FRAC:   fractional portion                                                                     |
| `%sto n`    | STO:    store X to storage area                                                                |
| `%rcl n`    | RCL:    recall from storage area to X (roll stack up)                                          |
| `%cint`     | CINT:   convert X to unsigned integer                                                          |
| `%pi`       | PI:     load PI                                                                                |
| `%e`        | E:      load e = exp(1)                                                                        |
| `%stow n`   | STOW:   store X as 16 bit unsigned int to storage area using half registers                    |
| `%rclw n`   | RCL:    recall 16 bit unsigned int from storage area to X (roll stack up) using half registers |
| `%cmp`      | CMP:    compare                                                                                |
| `%jmp a`    | JMP:    jump                                                                                   |
| `%jc a`     | JC:     jump if carry                                                                          |
| `%jnc a`    | JNC:    jump if no carry                                                                       |
| `%jz a`     | JZ:     jump if zero                                                                           |
| `%jnz a`    | JNZ:    jump if not zero                                                                       |
| `%je a`     | JE:     jump if error                                                                          |
| `%jne a`    | JNE:    jump if no error                                                                       |
| `%djnz n,a` | DJNZ:   decrement register and jump if not zero                                                |
| `%test`     | TEST:   test register X                                                                        |
| `%fmt n`    | FMT:    set output format                                                                      |


`FPLIB`: the floating-point math ROUTINES
-----------------------------------------

The following public routines are implemented:

- Routines on packed values in internal memory via pointers:
    - `addfp`: @r0 := @r0 + @r1
    - `subfp`: @r0 := @r0 - @r1
    - `chsfp`: @r0 := -@r0
    - `intfp`: @r0 := int(@r0)
    - `fracfp`: @r0 := @r0-int(@r0)
    - `mulfp`: @r0 := @r0 * @r1
    - `divfp`: @r0 := @r0 / @r1
    - `invfp`: @r0 := 1 / @r0
    - `sqrtfp`: @r0 := sqrt( @r0 ) [Newton-Raphson]
    - `pow2fp`: @r0 := @r0 * @r0
    - `lnfp`: @r0 := ln( @r0 ) = log2( @r0 ) * ln( 2 )
    - `logfp`: @r0 := log( @r0 ) = ln( @r0 ) / ln( 10 )
    - `expfp`: @r0 := exp( @r0 ) [Taylor expansion]
    - `sinfp`: @r0 := sin( @r0 ) [Taylor expansion]
    - `cosfp`: @r0 := cos( @r0 ) = sin( @r0 + Pi/2 )
    - `tanfp`: @r0 := sin( @r0 ) / cos( @r0 )
    - `atanfp`: @r0 := arctan( @r0 ) [Taylor expansion]
    - `asinfp`: @r0 := arctan( @r0 / sqrt( 1 - @r0 * @r0 ) )
    - `acosfp`: @r0 := Pi / 1 - arcsin( @r0 )
    - `powfp`: @r0 := pow( @r0, @r1 ) = exp( @r0 * ln( @r1 ) )
    - `pifp`: @r0 := Pi
    - `efp`: @r0 := E = exp( 1 )
    - `writefp`: write @r0 to string buffer
    - `readfp`: parse and read @rO from string buffer
- Routines using X-Y-Z-T stack and the FP Executive (see below):
    - `fp_run_pc`: execute FP Executive code from CODE memory at current PC
    - `fp_run_xdptr`: execute FP Executive code from DATA memory at dptr
    - `fp_run_cdptr`: execute FP Executive code from CODE memory at dptr


`FPEVAL`: the floating-point math expression evaluator
------------------------------------------------------
The procedure `fpeval` in this module can parse and evaluate a math expression stored in XDATA memory and pointer by
DPTR.

The result of the expression is stored in internal DATA memory at the location pointed by R0.

The syntax is:
```
expr   := sum

sum    := prod
       |  sum + prod
       |  sum - prod

prod    := pow
        |  prod * pow
        |  prod / pow

pow     := func
        |  func ^ pow

func    := value
        |  PI
        |  func_id value

value   := ( expr )
        |  number

number  := -expr
        |  [[0-9...].]0-9...

func_id := SQRT | SQR | LOG | LN | EXP | SIN | COS | TAN | ASIN | ACOS | ATAN | INT | FRAC
```

(tbc)

# TNAC - Tnac is Not A Computer
## or, This is Not A Computer
### unlike GNU, this recursive acronym does actually terminate.

## Introduction
TNAC is intended to be an education tool to teach courses in Computer Architecture and Compiler Design. Its a simulator for a basic computer which comes with its own memory - simulated - and a small OS.

TNAC is the result of my undergraduate degree project. So if you're a recruiter and coming here from my resume, it was named ProcessK. No, I didn't provide you link to a random GitHub and passed it off as mine.

## Documentation: 
## Instruction Set 
| Pnemonic | Operands |         Addressing Modes         |            Description           | Opcode |
|:--------:|:--------:|:--------------------------------:|:--------------------------------:|:------:|
|    CPY   |  R1, R2  | Register ref, Reg/Indirect on R2 |        CoPY from R1 to R2        |    1   |
|    LDR   |  adr, R  | Direct on adr, Register ref on R |         LoaD to Register         |    2   |
|    LRI   |  val, R  |   Immediate, Register ref on R   |    Load to Register Immediate    |    3   |
|    LDA   |    adr   |         Direct/Indirect          |        LoaD to Accumulator       |    4   |
|    LAI   |    val   |             Immediate            |   Load to Accumulator Immediate  |    5   |
|    STA   |     R    |        Register reference        |      STore from Accumulator      |    6   |
|    SAI   |    adr   |              Direct              |  Store from Accumulator Immediat |    7   |
|    INC   |     R    |        Register reference        |             INCrement            |    8   |
|    DEC   |     R    |        Register reference        |             DECrement            |    9   |
|    ISP   |          |                                  |      Increment Stack Pointer     |   10   |
|    NOT   |     R    |   Register reference, Indirect   |            bitwise NOT           |   11   |
|    NTI   |    val   |             Immediate            |       bitwise NOT Immediate      |   12   |
|    MOD   |     R    |   Register reference, Indirect   |              MODulo              |   13   |
|    MDI   |    val   |             Immediate            |         MoDulo Immediate         |   14   |
|    DIV   |     R    |   Register reference, Indirect   |              DIVide              |   15   |
|    DVI   |    val   |             Immediate            |         DiVide Immediate         |   16   |
|    MUL   |     R    |   Register reference, Indirect   |             MULtiply             |   17   |
|    MLI   |    val   |             Immediate            |        MuLtiply Immediate        |   18   |
|    ADD   |     R    |   Register reference, Indirect   |                ADD               |   19   |
|    ADI   |    val   |             Immediate            |           ADd Immediate          |   20   |
|    SUB   |     R    |   Register reference, Indirect   |             SUBtract             |   21   |
|    SBI   |    val   |             Immediate            |        SuBtract Immediate        |   22   |
|    ILT   |     R    |   Register reference, Indirect   |           If Less Than           |   23   |
|    LTI   |    val   |             Immediate            |       Less Than Immediate        |   24   |
|    ILE   |     R    |   Register reference, Indirect   |        If Less than Equals       |   25   |
|    LEI   |    val   |             Immediate            |    Less than Equals Immediate    |   26   |
|    IGT   |     R    |   Register reference, Indirect   |          If Greater Than         |   27   |
|    GTI   |    val   |             Immediate            |      Greater Than Immediate      |   28   |
|    IGE   |     R    |   Register reference, Indirect   |      If Greater than Equals      |   29   |
|    GEI   |    val   |             Immediate            |   Greater than Equals Immediate  |   30   |
|    IEQ   |     R    |   Register reference, Indirect   |             If EQual             |   31   |
|    EQI   |    val   |             Immediate            |          Equal Immediate         |   32   |
|    INQ   |     R    |   Register reference, Indirect   |           If Not eQual           |   33   |
|    NQI   |    val   |             Immediate            |        Not eQual Immediate       |   34   |
|    INT   |     R    |   Register reference, Indirect   | bitwise INTersection (logic AND) |   35   |
|    ITI   |    val   |             Immediate            |      InTersection Immediate      |   36   |
|    XOR   |     R    |   Register reference, Indirect   |            bitwise XOR           |   37   |
|    XRI   |    val   |             Immediate            |       bitwise XoR Immediate      |   38   |
|    UNN   |     R    |   Register reference, Indirect   |     bitwise UNioN (logic OR)     |   39   |
|    UNI   |    val   |             Immediate            |         UNion  Immediate         |   40   |
|    JMP   |     R    |        Register reference        |        JuMP unconditional        |   41   |
|    JIT   |     R    |        Register reference        |           JumP If True           |   42   |
|    JNT   |     R    |        Register reference        |         Jump if Not True         |   43   |
|    CLL   |     R    |        Register reference        |        CaLL unconditional        |   44   |
|    CIT   |     R    |        Register reference        |           Call If True           |   45   |
|    CNT   |     R    |        Register reference        |         Call if Not True         |   46   |
|    RET   |          |                                  |              RETurn              |   47   |
|    RIT   |          |                                  |          Return If True          |   48   |
|    RNT   |          |                                  |        Return if Not True        |   49   |
|    PMT   |     R    |        Register reference        |              ProMpT              |   50   |
|    OUT   |     R    |        Register reference        |              OUTput              |   51   |
|    CLR   |     R    |        Register reference        |               CLeaR              |   52   |
|    RST   |    FLG   |          Flag reference          |               ReSeT              |   53   |
|    SET   |    FLG   |          Flag reference          |                SET               |   54   |
|    TOG   |    FLG   |          Flag reference          |              TOGgle              |   55   |
|    HLT   |          |                                  |               HaLT               |   56   |

## Flags:
| Flag |     Description     |                Value               | Encoding |
|:----:|:-------------------:|:----------------------------------:|:--------:|
|  Tr  |        Truth        |         1 - True; 0 - False        |     0    |
| IndA | Indirect Addressing | 1 - Indirect addr; 0 - Direct addr |    -1    |

## Registers
|     Register     |        Description        |        Encoding        |   |   |
|:----------------:|:-------------------------:|:----------------------:|---|---|
| A, B, C, D, E, F | General Purpose Registers | 65, 66, 67, 68, 69, 70 |   |   |
|        AC        |        Accumulator        |           71           |   |   |
|        IR        |    Instruction Register   |           72           |   |   |
|        PC        |      Program Counter      |           73           |   |   |
|        SP        |       Stack Pointer       |           74           |   |   |
|        MAR       |  Memory Address Register  |           75           |   |   |
|        MDR       |    Memory Data Register   |           76           |   |   |

## Interrupts
| Interrupt |                                 Description                                | Vector |
|:---------:|:--------------------------------------------------------------------------:|:------:|
|    RES    | Jump to restricted memory, Divide by Zero, Invalid register/flag reference |    1   |

## Addressing Modes
## Register Reference
    The instruction use the value at the register referred to in the operand. A reference 65 will use the value at register A. This mode will be used with instructions that support this mode and when IndA flag is reset
## Flag Reference
    The instructions will use the current state of the flag being referenced. A reference -1 will use the state of Sn flag. If an instruction expects a flag reference and finds something invalid, it triggers TRAP interrupt.
## Direct
    The instructions that take adr as their operands use this mode. The value stored at memory location adr will be used. Direct addressing will be used if instruction takes adr as an operand and IndA flag is reset.
## Indirect
    The instructions that take adr or register reference may use this mode by setting the IndA flag. When the IndA flag is set, the value at memory location pointed at by the address in register to adr is used. For eg if register A has a value of 2001, and current instruction operand is an indirect register reference of 65, then value at memory[2001]  will be used as operand.
## Immediate
    The value to be used is specified directly in the next memory location. No flags are checked for this mode. Most instructions have their corresponding instructions that use immediate addressing.

See Instruction Set table above to know which instruction supports which addressing modes.


## Usage
When the processor is initialised it executes a loop residing in the restricted memory. The loop essentially asks the user if he wants to enter program mode or execute more. A choice of 0 corresponds to execute mode. The choice of 1 (or anything else) forces is into program mode. 

The user can then enter instructions.

Once done, user should press character ‘e’ (without quotes) to trigger the TRAP interrupt that gives control pack to the OS. 

The choice is again asked. Pressing 0 will make the processor ask for starting dress of the program and jump to that address.

Once the program has been executed, the control is returned to the main loop and the choice of mode is asked again.


## Misc.
All operations and storage are in decimal instead of binary for ease of understanding.

 Attached memory size is 4096 words; int memory[4096]; 4001 = stack top when empty
 
 Stack grows by incrementing. Hence, pushing beyond address 4095 causes overflow and triggers TRAP interrupt.
 
 MDR is not used as an intermediate between the memory and processor; MDR is used as a temporary 
 register to hold the operand for every instruction. Every instruction is destructive to MDR and hence should not be used as a general purpose register.
 
 All mathematical (arithmetic, LOGICAL) operations results are stored in AC.
 
 IO interrupts may be introduced if memory runs in separate thread
 
 TRAP is vectored to memory[1].
 
Stack is NOT considered restricted memory and care should be taken while manipulating SP. It should also be noted that if HALT instruction is not found, PC might move into the stack.


## Future
Write a 'Memory' class and run it in a seperate thread. Likewise have an 'IO' class. 

Needless to say, remove PMT and OUT instructions and introduce software and IO interrupts, control flags and related stuff.

Introduce a SYS instruction to provide a way for software interrupts. Also, write interrupt routines and probably a better OS.

Write an assembler that targets TNAC. And maybe, just maybe, even a compiler for C language. C99 perhaps.

Whatever your heart desires.

## Assembly code TNAC is initialised with...
## code for RES at memory[1]
 TRAP would be reset at this point
1       LRI 4001 SP
4       RST Tr
6       RST Sn
8       RST OF
10     RST IndA
12     CLR A
14     CLR B
16     CLR C
18     CLR D
20     CLR E
22     CLR F
24     CLR AC
26     CLR MAR
28     CLR MDR

 ## code for OS at memory[30]
30  LRI -- A   //load jump location in R1 - execute mode
33  LR1 -- B  //load jump location in R2 - programming loop
36  LAI 0        //Load 0 in AC
38  PMT C     //Prompt choice, 0 - execute, 1 - program mode
40  IEQ C    //If choice equal to 0
42  JIT A     //Jump if true to location 1
44  PMT D     //Prompt for starting adress of programm
46  OUT D     //echo starting adress
48  PMT E    //prompt for instruction
50  SET IndA
52  CPY E D  //store instruction in memory
55  RST IndA
57  INC D     //increment adress pointer
59  JMP B     //else jump to location 2; making a loop
61  PMT D     //location foe execution
63  CLL D     //call instruction in R4
  
  


//
//  core.cpp
//  Processor
//
//  Created by Kabir  on 16/12/20.
//

#include "core.hpp"
#include <iostream>
#include <string>

bool* core :: flagResolver(int FLG){
    bool* fl;
    switch (FLG) {
        case 0: fl = &Tr;
            break;
        case -1: fl = &IndA;
            break;
            
        default: RES = true;
            return &nullFlg;
    }
    
    return fl;
}

int* core :: registerResolver(int MAR){
    int* reg;
    switch(MAR){
        case 65: reg = &A;
            break;
        case 66: reg = &B;
            break;
        case 67: reg = &C;
            break;
        case 68: reg = &D;
            break;
        case 69: reg = &E;
            break;
        case 70: reg = &F;
            break;
        case 71: reg = &AC;
            break;
        case 72: reg = &IR;
            break;
        case 73: reg = &PC;
            break;
        case 74: reg = &SP;
            break;
        case 75: reg = &MAR;
            break;
        case 76: reg = &MDR;
            break;
            
        default: RES = true;
            return &nullReg;
    }
    
    return reg;
}
//****************************************************************************************
void core::CPY(){
    //Copy
    PC++;
    MAR = fetch(PC);
    MDR = *(registerResolver(MAR));
    
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        store(MDR, MAR);
        return;
    }

    *(registerResolver(MAR)) = MDR;
}

void core :: LDR(){
    //LoaD to Register
    PC++;
    MAR = fetch(PC);

    MDR = fetch(MAR);
    
    PC++;
    MAR = fetch(PC);
        
    *(registerResolver(MAR)) = MDR;
}

void core :: LRI(){
    //Load to Register Immediate
    PC++;
    MDR = fetch(PC);
    
    PC++;
    MAR = fetch(PC);

    *(registerResolver(MAR)) = MDR;
}

void core::LDA(){
    //LoaD to Accumulator
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = fetch(MAR);
    }
    MDR = fetch(MAR);
    
    AC = MDR;
}

void core::LAI(){
    //Load to Accumulator Immediate
    PC++;
    MDR = fetch(PC);
    AC = MDR;
}

void core:: STA(){
    //STore from Accumulator
    PC++;
    MAR = fetch(PC);
    
    //always assumes indirect adressing
    MAR = *(registerResolver(MAR));
    store(AC, MAR);
}

void core :: SAI(){
    //Store from Accumulator Immediate
    PC++;
    MAR = fetch(PC);
    store(AC, MAR);
}

//****************************************************************************************
void core :: INC() {
    //INCrement
    PC++;
    MAR = fetch(PC);
    *(registerResolver(MAR)) += 1;
}
void core :: DEC() {
    //DECrement
    PC++;
    MAR = fetch(PC);
    *(registerResolver(MAR)) -= 1;
}
void core::ISP(){
    //Increment Stack Pointer
    SP++;
}

void core :: NOT() {
    //bitwise NOT
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        AC = fetch(MAR);
    }else
        AC = *(registerResolver(MAR));
    
    AC = ~AC;
}

void core :: NTI(){
    //bitwise NoT Immediate
    PC++;
    AC = fetch(PC);
    AC = ~AC;
}

void core :: MOD(){
    //MODulo
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    AC %= MDR;
}

void core :: MDI(){
    //MoDulo Immediate
    PC++;
    MDR = fetch(PC);
    
    AC %= MDR;
}

void core :: DIV(){
    //DIVide
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    if (MDR == 0){
        RES = true;
        return;
    }
    
    AC /= MDR;
}

void core :: DVI(){
    //DiVide Immediate
    PC++;
    MDR = fetch(PC);
    AC /= MDR;
}

void core :: MUL(){
    //MULtiply
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    AC *= MDR;
}

void core :: MLI(){
    //MuLtiply Immediate
    PC++;
    MDR = fetch(PC);
    AC *= MDR;
}

void core :: ADD(){
    //ADD
    PC++;
    MAR = fetch(PC);
    
    if (IndA) {
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    
    AC += MDR;
}

void core :: ADI(){
    //ADd Immediate
    PC++;
    MDR = fetch(PC);
    AC += MDR;
}

void core :: SUB(){
    //SUBtract
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    AC -= MDR;
}

void core :: SBI(){
    //SuBtract Immediate
    PC++;
    MDR = fetch(PC);
    AC -= MDR;
}

void core :: ILT(){
    //If Less Than
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    Tr = (MDR < AC)? true : false;
}

void core :: LTI(){
    //Less Than Immediate
    PC++;
    MDR = fetch(PC);
    
    Tr = (MDR < AC)? true : false;
}

void core::ILE(){
    //If Less than or Equal to
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    Tr = (MDR <= AC)? true : false;
}
void core :: LEI(){
    //Less than or Equal to Immediate
    PC++;
    MDR = fetch(PC);
    
    Tr = (MDR <= AC)? true : false;
}

void core :: IGT(){
    //If Greater Than
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    Tr = (MDR > AC)? true : false;
}

void core :: GTI(){
    //Greater Than Immediate
    PC++;
    MDR = fetch(PC);
    
    Tr = (MDR > AC)? true : false;
}

void core :: IGE(){
    //If Greater than or Equal to
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    Tr = (MDR >= AC)? true : false;
}

void core :: GEI(){
    //Geater then or Equal to Immediate
    PC++;
    MDR = fetch(PC);
    
    Tr = (MDR >= AC)? true : false;
}

void core :: IEQ(){
    //If EQual
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    Tr = (MDR == AC)? true : false;
}

void core :: EQI(){
    //EQual Imediate
    PC++;
    MDR = fetch(PC);
    
    Tr = (MDR == AC)? true : false;
}

void core :: INQ(){
    //If Not Equal
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    Tr = (MDR != AC)? true : false;
}
void core :: NQI(){
    //Not eQual Immediate
    PC++;
    MDR = fetch(PC);
    
    Tr = (MDR != AC)? true : false;
}

void core :: INT(){
    //bitwise INTersection (logic AND)
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    AC = AC & MDR;
}

void core :: ITI(){
    //bitwise InTersection Immediate (Logic AND)
    PC++;
    MDR = fetch(PC);
    AC = AC & MDR;
}

void core :: XOR(){
    //bitwise XOR
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    AC = AC ^ MDR;
}

void core :: XRI(){
    //bitwise XoR Immediate
    PC++;
    MDR = fetch(PC);
    AC = AC ^ MDR;
}

void core :: UNN(){
    //bitwise UNioN (logic OR)
    PC++;
    MAR = fetch(PC);
    
    if(IndA){
        MAR = *(registerResolver(MAR));
        MDR = fetch(MAR);
    }else
        MDR = *(registerResolver(MAR));
    
    AC = AC | MDR;
}

void core :: UNI(){
    //bitwise UNion Immediate (logic OR)
    PC++;
    MDR = fetch(PC);
    AC = AC | MDR;
}
//****************************************************************************************
void core :: JMP(){
    //JuMP unconditional
    PC++;
    MAR = fetch(PC);
    
    MDR = *(registerResolver(MAR));
    
    PC = MDR-1;
}

void core :: JIT(){
    //Jump If True
    PC++;
    
    if (!Tr)
        return;
    
    MAR = fetch(PC);

    MDR = *(registerResolver(MAR));
    
    PC = MDR-1;
}

void core :: JNT(){
    //Jump if Not True
    PC++;
    
    if (Tr)
        return;
    
    MAR = fetch(PC);

    MDR = *(registerResolver(MAR));
    
    PC = MDR-1;
}

void core :: CLL(){
    //CaLL unconditional
    PC++;
    MAR = fetch(PC);

    MDR = *(registerResolver(MAR));
    
    PC++;
    memory[SP] = PC;
    SP++;
    PC = MDR-1;
}

void core :: CIT(){
    //Call If True
    PC++;
    
    if(!Tr)
        return;
    
    MAR = fetch(PC);

    MDR = *(registerResolver(MAR));
    
    PC++;
    memory[SP] = PC;
    SP++;
    PC = MDR-1;
}

void core :: CNT(){
    //Call if Not True
    PC++;
    
    if(Tr)
        return;
    
    
    MAR = fetch(PC);

    MDR = *(registerResolver(MAR));
    
    PC++;
    memory[SP] = PC;
    SP++;
    PC = MDR-1;
}

void core :: RET(){
    //RETurn
    PC = memory[SP];
    SP--;
}

void core :: RIT(){
    //Return If True
    if(!Tr)
        return;
    
    PC = memory[SP];
    SP--;
}

void core :: RNT(){
    //Return if Not True
    if(Tr)
        return;
    
    PC = memory[SP];
    SP--;
}
//***************************************************************************************
void core :: PMT(){
    //ProMpT
    PC++;
    MAR = fetch(PC);

    //temp has nothing to do with KPU or processors in general
    std::string temp;
    std::cout << ">> ";
    std::cin >> temp;
    if (temp[0] == 'e') {
        RES = true;
        return;
    }else
        *(registerResolver(MAR)) = stoi(temp, nullptr);
}

void core :: OUT(){
    //OUTput
    PC++;
    MAR = fetch(PC);
    
    std::cout << ">> " << *(registerResolver(MAR)) << " ";
}
//***************************************************************************************
void core :: CLR(){
    //CLeaR
    PC++;
    MAR = fetch(PC);
    
    //Assumes direct adressing
    *(registerResolver(MAR)) = 0;
}

void core :: RST(){
    //RESet
    PC++;
    MAR = fetch(PC);
    *flagResolver(MAR) = false;
}

void core :: SET(){
    //SET
    PC++;
    MAR = fetch(PC);
    *flagResolver(MAR) = true;
}

void core :: TOG(){
    //TOGgle
    PC++;
    MAR = fetch(PC);
    *flagResolver(MAR) = !(*flagResolver(MAR));
}
//****************************************************************************************
void core :: HLT(){
    //HaLT
    RES = true;
}
//****************************************************************************************
core :: core(){
    RES = false;
    AC = 0;
    SP = 4001;
    MAR = MDR = 0;
    Tr = IndA = false;
    A = B = C = D = E = F = 0;
    PC = 26;
    
    //these values dont matter. these are just placeholders.
    //these exist so that invalid reg reference doesnt crash the simulator
    nullReg = 0;
    nullFlg = false;

    //init memory with RES
    memory[1] = 3;      //LRI
    memory[2] = 4001;   //val
    memory[3] = 74;     //SP
    memory[4] = 53;     //RST
    memory[5] = 0;      //Tr
    memory[6] = 53;    //RST
    memory[7] = -1;    //IndA
    memory[8] = 52;    //CLR
    memory[9] = 65;    //A
    memory[10] = 52;    //CLR
    memory[11] = 66;    //B
    memory[12] = 52;    //CLR
    memory[13] = 67;    //C
    memory[14] = 52;    //CLR
    memory[15] = 68;    //D
    memory[16] = 52;    //CLR
    memory[17] = 69;    //E
    memory[18] = 52;    //CLR
    memory[19] = 70;    //F
    memory[20] = 52;    //CLR
    memory[21] = 71;    //AC
    memory[22] = 52;    //CLR
    memory[23] = 76;    //MDR
    memory[24] = 52;    //CLR
    memory[25] = 75;    //MAR
    
    //init memory with OS
    memory[26] = 3;     //LRI
    memory[27] = 57;    //val - adr for execute mode
    memory[28] = 65;    //A
    memory[29] = 3;     //LAI
    memory[30] = 42;    //val - label for programming mode loop
    memory[31] = 66;    //B
    memory[32] = 5;     //LAI
    memory[33] = 0;     //val 0
    memory[34] = 50;    //PMT
    memory[35] = 67;    //C
    memory[36] = 31;    //IEQ
    memory[37] = 67;    //C
    memory[38] = 42;    //JIT
    memory[39] = 65;    //A
    memory[40] = 50;    //PMT
    memory[41] = 68;    //D
    memory[42] = 51;    //OUT
    memory[43] = 68;    //D
    memory[44] = 50;    //PMT
    memory[45] = 69;    //E
    memory[46] = 54;    //SET
    memory[47] = -1;    //IndA
    memory[48] = 1;     //CPY
    memory[49] = 69;    //E
    memory[50] = 68;    //D
    memory[51] = 53;    //RST
    memory[52] = -1;    //IndA
    memory[53] = 8;    //INC
    memory[54] = 68;    //D
    memory[55] = 41;    //JMP
    memory[56] = 66;    //B
    memory[57] = 50;    //PMT
    memory[58] = 68;    //D
    memory[59] = 44;    //CLL
    memory[60] = 68;    //D;

}

int core::fetch(int address){
    if (address >= 0)
        return memory[address];
    else{
        RES = true;
        return 0;
    }
}

void core :: store(int data, int address){
    if (address >= 60)
        memory[address] = data;
    else{
        RES = true;
        return ;
    }
}

void core :: start_instruction_cycle(){
    while (true) {
        IR = fetch(PC);
        decode(IR);
        intrService();
        PC++;
    }
}

void core :: decode(int instruct){
    switch (instruct) {
        case 1: CPY();
            break;
        case 2: LDR();
            break;
        case 3: LRI();
            break;
        case 4: LDA();
            break;
        case 5: LAI();
            break;
        case 6: STA();
            break;
        case 7: SAI();
            break;
        case 8: INC();
            break;
        case 9: DEC();
            break;
        case 10: ISP();
            break;
        case 11: NOT();
            break;
        case 12: NTI();
            break;
        case 13: MOD();
            break;
        case 14: MDI();
            break;
        case 15: DIV();
            break;
        case 16: DVI();
            break;
        case 17: MUL();
            break;
        case 18: MLI();
            break;
        case 19: ADD();
            break;
        case 20: ADI();
            break;
        case 21: SUB();
            break;
        case 22: SBI();
            break;
        case 23: ILT();
            break;
        case 24: LTI();
            break;
        case 25: ILE();
            break;
        case 26: LEI();
            break;
        case 27: IGT();
            break;
        case 28: GTI();
            break;
        case 29: IGE();
            break;
        case 30: GEI();
            break;
        case 31: IEQ();
            break;
        case 32: EQI();
            break;
        case 33: INQ();
            break;
        case 34: NQI();
            break;
        case 35: INT();
            break;
        case 36: ITI();
            break;
        case 37: XOR();
            break;
        case 38: XRI();
            break;
        case 39: UNN();
            break;
        case 40: UNI();
            break;
        case 41: JMP();
            break;
        case 42: JIT();
            break;
        case 43: JNT();
            break;
        case 44: CLL();
            break;
        case 45: CIT();
            break;
        case 46: CNT();
            break;
        case 47: RET();
            break;
        case 48: RIT();
            break;
        case 49: RNT();
            break;
        case 50: PMT();
            break;
        case 51: OUT();
            break;
        case 52: CLR();
            break;
        case 53: RST();
            break;
        case 54: SET();
            break;
        case 55: TOG();
            break;
        case 56: HLT();
            break;
            
        //default: RES = true;
           // return;
    }
    
}

void core::intrService(){
    if(RES){
        std::cout << "_trap_intr\n";
        PC = 0;
        RES = false;
    }
}


//example program to add two numbers (7, 22) and print it on screen.
//5 7 20 22 51 71 56

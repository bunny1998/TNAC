//
//  core.hpp
//  Processor
//
//  Created by Kabir  on 16/12/20.
//

#ifndef core_hpp
#define core_hpp

class core{
    int AC, IR, PC, SP, MAR, MDR; //accumulator, Instruct, ProgCount, StackPoint, Add, Data
    int A, B, C, D, E, F;         //registers
    bool RES;                     //Interrupts
    bool Tr, IndA;            //Truth, Overflow, IndirectAdressMode
    int memory[4096];
    
    //these are for checking invalid register and flag references due to language constraints.
    //this flag and register does not exist in a real processor
    bool nullFlg; int nullReg;

    void store(int data, int address);
    bool* flagResolver(int FLG);
    int* registerResolver(int MAR);
    void CPY();
    void LDR();
    void LRI();
    void LDA();
    void LAI();
    void STA();
    void SAI();
    void INC();
    void DEC();
    void ISP();
    void NOT();
    void NTI();
    void MOD();
    void MDI();
    void DIV();
    void DVI();
    void MUL();
    void MLI();
    void ADD();
    void ADI();
    void SUB();
    void SBI();
    void ILT();
    void LTI();
    void ILE();
    void LEI();
    void IGT();
    void GTI();
    void IGE();
    void GEI();
    void IEQ();
    void EQI();
    void INQ();
    void NQI();
    void INT();
    void ITI();
    void XOR();
    void XRI();
    void UNN();
    void UNI();
    void JMP();
    void JIT();
    void JNT();
    void CLL();
    void CIT();
    void CNT();
    void RET();
    void RIT();
    void RNT();
    void PMT();
    void OUT();
    void CLR();
    void RST();
    void SET();
    void TOG();
    void HLT();
    
    int fetch(int);
    void decode(int);
    void intrService();
public:
    core();
    void start_instruction_cycle();
};



#endif /* core_hpp */

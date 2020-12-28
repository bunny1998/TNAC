//
//  main.cpp
//  Processor
//
//  Created by Kabir  on 16/12/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include "core.hpp"
int main(int argc, const char * argv[]) {
    core processor;
    
    processor.start_instruction_cycle();
    return 0;
}

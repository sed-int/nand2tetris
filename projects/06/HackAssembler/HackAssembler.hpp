#pragma once

#include "Code.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"
#include <string>

class HackAssembler
{
    private:
        std::string     mFileName;
        Code*           mCode;
        Parser*         mParser;
        SymbolTable*    mSymbolTable;
    
        void preprocess();
        void getOutFileName();

    public:
        HackAssembler(std::string fileName);
        void run();
};
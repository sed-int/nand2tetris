#pragma once

#include "Code.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"
#include <string>

class HackAssembler
{
    private:
        std::string     mFileName;
        int             mAddress;
        Code*           mCode;
        Parser*         mParser;
        SymbolTable*    mSymbolTable;
    
        void            preprocess();
        std::string&    getOutFileName() const;

    public:
        HackAssembler(std::string fileName);
        void            run();
};
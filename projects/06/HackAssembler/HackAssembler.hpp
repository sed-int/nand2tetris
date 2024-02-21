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
        Parser*         mParser;
        Code*           mCode;
        SymbolTable*    mSymbolTable;

        void            preprocess();
        std::string    getOutFileName() const;

    public:
        HackAssembler(std::string fileName);
        void            run();
};

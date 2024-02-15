#pragma once

#include <map>

class SymbolTable
{
    private:
        std::unordered_map<std::string, int> mTable;
    
    public:
        SymbolTable();
        ~SymbolTable();
        void addEntry(std::string symbol, int address);
        bool contains(std::string symbol);
        int  getAddress(std::string symbol);
};

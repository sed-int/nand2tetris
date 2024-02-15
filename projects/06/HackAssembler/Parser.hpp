#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <exception>

enum instructionType
{
    A_INSTRUCTION,
    C_INSTRUCTION,
    L_INSTRUCTION
};

class Parser
{
    private:

        std::string mCurrentLine;
        std::ifstream mInfile;
        std::vector<std::string> mRawInstructions;
    
    public:

        Parser(std::string fileName);
        ~Parser();
        bool init();
        bool hasMoreLines();
        void advance();
        instructionType getInstructionType();
        std::string& symbol();
        std::string& dest();
        std::string& comp();
        std::string& jump();
};
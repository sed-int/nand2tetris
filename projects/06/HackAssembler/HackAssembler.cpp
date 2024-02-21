#include "HackAssembler.hpp"
#include <bitset>
#include <sstream>

namespace
{
    std::string decimalToBinaryString(int decimal) {
    // If the number is negative, handle that separately
    if(decimal < 0)
        return "Negative numbers not supported.";

    // If the number is 0, its binary representation is 0
    if (decimal == 0)
        return "0000000000000000";

    // Using std::bitset to convert decimal to binary
    std::bitset<16> binary(decimal);
    return binary.to_string();
}
}

HackAssembler::HackAssembler(std::string fileName)
: mFileName(fileName), mAddress(16), mParser(new Parser(mFileName)), mCode(new Code), mSymbolTable(new SymbolTable)
{
}

std::string HackAssembler::getOutFileName() const
{
    size_t      pos = 0;
    std::string outFileName(mFileName);

    if ((pos = outFileName.find(".asm")) != std::string::npos)
    {
        outFileName.replace(pos, 4, ".hack");
    }
    return outFileName;
}

void HackAssembler::preprocess()
{
    int             lineNumber = 0;
    std::string     symbol;
    InstructionType instructionType;

    while(mParser->hasMoreLines())
    {
        mParser->advance();
        if (!mParser->hasMoreLines())
            break;
        instructionType = mParser->getInstructionType();
        if (instructionType == InstructionType::L_INSTRUCTION)
        {
            symbol = mParser->symbol();
            mSymbolTable->addEntry(symbol, lineNumber + 1);
        }
        else
            lineNumber++;
    }
    delete mParser;
    mParser = nullptr;
    mParser = new Parser(mFileName);
}


void HackAssembler::run()
{

    int             lineNumber = 0;
    std::string     msg;
    std::string     symbol;
    std::string     dest;
    std::string     comp;
    std::string     jump;
    std::string     prefix = "111";
    InstructionType instructionType;

    preprocess();

    std::ofstream outFile(getOutFileName());
    if (outFile.fail())
    {
        exit(-1);
    }

    while(mParser->hasMoreLines())
    {
        mParser->advance();
        if (!mParser->hasMoreLines())
            break;
        instructionType = mParser->getInstructionType();
        if (instructionType == InstructionType::A_INSTRUCTION)
        {
            symbol = mParser->symbol();
            if (mSymbolTable->contains(symbol) == false)
            {
                mSymbolTable->addEntry(symbol, mAddress++);
            }
            outFile << decimalToBinaryString(mSymbolTable->getAddress(symbol)) << "\n";
        }
        else if (instructionType == InstructionType::C_INSTRUCTION)
        {
            comp = mParser->comp();
            comp = mCode->comp(comp);
            dest = mParser->dest();
            dest = mCode->dest(dest);
            jump = mParser->jump();
            jump = mCode->jump(jump);
            msg = prefix + comp + dest + jump;
            outFile << msg << "\n";
        }
        lineNumber++;
    }

    delete mParser;
    delete mCode;
    delete mSymbolTable;
}

#include "HackAssembler.hpp"

HackAssembler::HackAssembler(std::string fileName)
: mFileName(fileName), mAddress(16), mParser(new Parser(mFileName)), mCode(new Code), mSymbolTable(new SymbolTable)
{
}

void HackAssembler::preprocess()
{
    int lineNumber = 0;
    std::string symbol;
    instructionType instructionType;

    while(mParser->hasMoreLines())
    {
        mParser->advance();
        lineNumber++;
        instructionType = mParser->getInstructionType();
        if (instructionType == instructionType::L_INSTRUCTION)
        {
            symbol = mParser->symbol();
            mSymbolTable->addEntry(symbol, lineNumber + 1);
        }
    }
    delete mParser;
    mParser = new Parser(mFileName);
}

std::string& HackAssembler::getOutFileName() const
{
    size_t pos = 0;
    std::string outFileName(mFileName);

    if ((pos = outFileName.find(".asm")) != std::string::npos)
        outFileName.replace(pos, 4, ".hack");
    return outFileName;
}

void HackAssembler::run()
{

    int lineNumber = 0;
    std::string symbol;
    std::string dest;
    std::string comp;
    std::string jump;
    std::string prefix = "111";
    instructionType instructionType;

    preprocess();

    std::ofstream outFile(getOutFileName());
    if (outFile.fail())
    {
        exit(-1);
    }

    while(mParser->hasMoreLines())
    {
        mParser->advance();

        lineNumber++;
        instructionType = mParser->getInstructionType();
        if (instructionType == instructionType::A_INSTRUCTION)
        {
            symbol = mParser->symbol();
            if (mSymbolTable->contains(symbol) == false)
            {
                mSymbolTable->addEntry(symbol, mAddress++);
            }
            outFile << mSymbolTable->getAddress(symbol);
        }
        else if (instructionType == instructionType::C_INSTRUCTION)
        {
            comp = mParser->comp();
            dest = mParser->dest();
            jump = mParser->jump();
            outFile << prefix << comp << dest << jump;
        }
        else if (instructionType == instructionType::L_INSTRUCTION)
        {
            continue;
        }
        outFile << "\n";
    }
}

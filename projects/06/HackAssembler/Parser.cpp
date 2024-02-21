#include "Parser.hpp"

Parser::Parser(std::string fileName)
{
    try
    {
        mInfile.open(fileName);
    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "Exception opening/reading file";
        exit(EXIT_FAILURE);
    }
}

Parser::~Parser()
{
    mInfile.close();
}

bool Parser::hasMoreLines()
{
    if (mInfile.eof())
    {
        return false;
    }
    return true;
    // return !mInfile.eof();
}

void Parser::advance()
{
    size_t pos;
    while(1)
    {
        if (!std::getline(mInfile, mCurrentLine))
            return;
        while ((pos = mCurrentLine.find('\n')) != std::string::npos)
        {
            mCurrentLine.erase(pos, 1);
        }
        while ((pos = mCurrentLine.find(' ')) != std::string::npos)
        {
            mCurrentLine.erase(pos, 1);
        }
        if (!mCurrentLine.empty()
            && mCurrentLine.front() != '/')
            break;
    }
    pos = mCurrentLine.find('/');
    if (pos != std::string::npos)
        mCurrentLine = mCurrentLine.substr(0, pos);
}

InstructionType Parser::getInstructionType()
{
    if (mCurrentLine.find('@') != std::string::npos)
        return InstructionType::A_INSTRUCTION;
    if (mCurrentLine.find(';') != std::string::npos)
        return InstructionType::C_INSTRUCTION;
    if (mCurrentLine.find('=') != std::string::npos)
        return InstructionType::C_INSTRUCTION;
    else //if (mCurrentLine.find('('))
        return InstructionType::L_INSTRUCTION;
}

std::string Parser::symbol()
{
    size_t pos = mCurrentLine.find(')');
    if (pos != std::string::npos)
        return mCurrentLine.substr(1, pos - 1);
    return mCurrentLine.substr(1);
}

std::string Parser::dest()
{
    size_t pos = mCurrentLine.find('=');
    if (pos == std::string::npos)
        return "null";
    return mCurrentLine.substr(0, pos);
}

std::string Parser::comp()
{
    size_t startPos = mCurrentLine.find('=');
    if (startPos == std::string::npos)
        startPos = 0;
    else
        startPos += 1;
    size_t endPos = mCurrentLine.find(';');
    if (endPos == std::string::npos)
        return mCurrentLine.substr(startPos);
    return mCurrentLine.substr(startPos , endPos - startPos);
}

std::string Parser::jump()
{
    size_t pos = mCurrentLine.find(';');
    if (pos == std::string::npos)
        return "null";
    return mCurrentLine.substr(pos + 1);
}

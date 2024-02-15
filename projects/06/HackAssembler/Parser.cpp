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
}

void Parser::advance()
{
}

instructionType Parser::getInstructionType()
{

}

std::string& Parser::symbol() 
{

}

std::string& Parser::dest() 
{

}

std::string& Parser::comp() 
{

}

std::string& Parser::jump() 
{

}

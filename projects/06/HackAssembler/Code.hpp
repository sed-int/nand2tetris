#pragma once

#include<map>

class Code
{
    private:
        std::unordered_map<std::string, std::string> mDestTable;
        std::unordered_map<std::string, std::string> mCompTable;
        std::unordered_map<std::string, std::string> mJumpTable;
    
    public:
        Code();
        ~Code();
        std::string dest(std::string key);
        std::string comp(std::string key);
        std::string jump(std::string key);
};
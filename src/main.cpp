#include "main.h"

std::string testFile = ".testFile.py";

std::fstream fileTarget;
std::string s = fileTarget.open(testFile);

fileTarget.close()

FileDataNode* parse(std::string fileContent)
{
    FileDataNode* rootNode;

    std::string cache = "";
    FileDataNode* currentNode = rootNode;
    for (char c : fileContent)
    {

        if (c == '/#'){
            cache = "";
        };

        cache += c;
    };
    
}

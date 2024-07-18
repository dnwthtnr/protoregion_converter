
#include "vector"
#include "deque"
#include "string"
#include <string>
#include <fstream>
#include <iostream>





struct FileDataNode{
    std::string filename;
    std::string content;

    std::string fileExtesion;
    
    FileDataNode* parentNode;
    std::vector<FileDataNode*> childNodes;

};

std::string openFile(std::string filepath);

std::string stripIllegalChars(std::string text);

FileDataNode* parse(std::string fileContent);



int main();
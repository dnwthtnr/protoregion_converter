
#include "vector"
#include "deque"
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



FileDataNode* parse(std::string fileContent);
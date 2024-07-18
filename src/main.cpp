#include "main.h"

std::string testFile = "/workspaces/protoregion_converter/src/test.py";

std::string stripIllegalChars(std::string text){
    std::string illegalChars = "\\/:?\"<>|";
    for (int i = text.begin() ; i < s->end() ; ++i){
        bool found = illegalChars.find(*it) != std::string::npos;
        if(found){
            *it = ' ';
        }
}
};



std::string openFile(std::string filepath){
    std::ifstream fs;
    fs.open(filepath);

    char c;
    std::string text = "";

    while(fs.get(c)){
        text += c;
    };
    // while(!fs.eof()){
    //     fs.get(c);
    //     text.append(c)
    // };
    fs.close();
    return text;
};

FileDataNode* parse(std::string fileContent)
{
    FileDataNode* rootNode;

    std::string cachedLine = "";
    std::string spacelessCachedLine = "";
    FileDataNode* currentNode = rootNode;
    std::vector<FileDataNode*> nodeHistory;
    nodeHistory.push_back(rootNode);
    for (char c : fileContent){

        cachedLine += c;
        if (c == '\n'){

            // check if line is start or stop region 
            bool isComment = 0;
            if (spacelessCachedLine.rfind("#region", 0) != std::string::npos){
                // is beginning of region

                // make file name 
                spacelessCachedLine.erase(0, 6);
                spacelessCachedLine.replace(
                    spacelessCachedLine.begin(), 
                    spacelessCachedLine.end(), 
                    " ", 
                    "_"
                    );

                std::string illegalChars = "\\/:?\"<>|"
                for (it = s->begin() ; it < s->end() ; ++it){
                    bool found = illegalChars.find(*it) != string::npos;
                    if(found){
                        *it = ' ';
                    }
                }

                FileDataNode* newNode;
                newNode->filename = "";
            };

            cachedLine.empty();
            spacelessCachedLine.empty();

            currentNode->content += cachedLine;
        };
        if (isspace(c)){continue;};
        spacelessCachedLine += c;

    };
    
}


int main(){
    std::string folder = "/workspaces/protoregion_converter/test";
    std::string fileContent = openFile(testFile);
    FileDataNode* rootNode = parse(fileContent);
};


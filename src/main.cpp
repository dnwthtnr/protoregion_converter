#include "main.h"

std::string testFile = "/workspaces/protoregion_converter/src/test.py";

void stripIllegalChars(std::string* text){
    std::string illegalChars = "\\/:?\"<>|";
    for (int i = *text->begin() ; i < *text->end() ; ++i){
        bool found = illegalChars.find(i) != std::string::npos;
        if(found){
            i = ' ';
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
}


FileDataNode* parse(std::string fileContent)
{
    FileDataNode* rootNode;

    std::string cachedLine;
    std::string _cached_line_spaceless = "";
    std::string* spacelessCachedLine;
    spacelessCachedLine = &_cached_line_spaceless;

    std::cout << "SIZE OF:" << sizeof(spacelessCachedLine);

    FileDataNode* currentNode = rootNode;
    std::vector<FileDataNode*> nodeHistory;
    nodeHistory.push_back(rootNode);

    for (char c : fileContent){

        cachedLine += c;
        // End of line
        if (c == '\n'){

            // check if line is start or stop region
            bool isComment = 0;
            std::cout << "Spaceless Cached Line: " << *spacelessCachedLine << " LEN: " << sizeof(*spacelessCachedLine) << "\n"; 
            std::string region_start_substring = "#region";
            if( sizeof(spacelessCachedLine) < sizeof(region_start_substring)){
                // Skip searching for substring 
                // continue;
            } 
            int position = 0;
            if (sizeof(spacelessCachedLine) >= sizeof(region_start_substring)){
                position = sizeof(region_start_substring);
            };

            if (sizeof(spacelessCachedLine) == sizeof(std::string*)){
                cachedLine.clear();
                continue;
            }

            if (spacelessCachedLine->rfind(region_start_substring, position) != std::string::npos){
                // is beginning of region

                // make file name 
                spacelessCachedLine->erase(0, 6);
                spacelessCachedLine->replace(
                    spacelessCachedLine->begin(), 
                    spacelessCachedLine->end(), 
                    " ", 
                    "_"
                    );

                std::cout << spacelessCachedLine;

                stripIllegalChars(spacelessCachedLine);

                std::cout << spacelessCachedLine;

                FileDataNode* newNode;
                newNode->filename = "";
            };

            cachedLine.empty();
            // spacelessCachedLine->empty();

            currentNode->content += cachedLine;
        };

        if (isspace(c)){
            continue;
            };
            
        
        *spacelessCachedLine += c;

    };

    return rootNode;
    
};


int main(){
    std::string folder = "/workspaces/protoregion_converter/test";
    std::string fileContent = openFile(testFile);
    FileDataNode* rootNode = parse(fileContent);
};


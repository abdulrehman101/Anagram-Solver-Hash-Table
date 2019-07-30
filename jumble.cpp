
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

void ssort(std::string &s) {
    std::sort(s.begin(), s.end());
}

int main(int argc, char * argv[])
{
    
    std::unordered_map<std::string, std::vector<std::string>> anagram; // creating the object
    std::ifstream file;
    std::string word;
    
    if(argc != 2) {
        std::cout << "usage:  ./a.out <filename>\n";
        std::cout << "goodbye\n";
        return 1;
    }
    
    /*
     *  argv[1] is a C-string which is the filname specified
     *    by the user.  Let's try to open it.
     */
    
    file.open(argv[1], std::ios::in);
    
    if(!file.is_open()){
        std::cout << "Error: could not open file '" <<
        argv[1] << "'\n";
        std::cout << "goodbye\n";
        return 1;
    }
    
    std::cout << "reading input file...\n";
    
    while(file >> word) {
        std::string key = word;
        ssort(key);
        
        anagram[key].push_back(word);
    }
    
    printf("> ");
    std::cout << "Enter an anagram: ";
    while(std::cin >> word)
    {
        bool check = false;
        ssort(word);
        for(std::pair<std::string, std::vector<std::string>> entry : anagram) {
            //        printf("Key:   %10s    \n", entry.first.c_str());
            if(word == entry.first.c_str()){
                check = true;
                printf("English word found: \n\n");
                for(int i = 0; i < entry.second.size(); i++)
                {
                    std::cout << "\t" << entry.second.at(i) << std::endl;
                }
            }
            
        }
        if(!check)
        {
            std::cout << "sorry didnt find anything" << std::endl;
        }
        printf("> ");
         std::cout << "Enter an anagram: ";
    }
   
    
}

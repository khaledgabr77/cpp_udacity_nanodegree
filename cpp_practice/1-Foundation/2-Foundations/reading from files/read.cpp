#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::fstream my_file;
    my_file.open(path);
    if(my_file){
        std::cout << "the file stram has been created" << "\n";

        std::string line;
        while (getline(my_file, line))
        {
            cout << line << "\n";
        }
        
    }
}
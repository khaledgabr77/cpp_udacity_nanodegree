#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::ifstream;
using std::vector;
using std::string;



void ReadBoardFile(string path){
    ifstream my_file (path);
    if (my_file){
        string line;
        while (getline (myfile, line))
        {
            cout << line << "\n";
        }
        
    }
}

void PrintBoard(const vector<vector<int>> board){
    for(int i = 0; i <board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            cout << board[i][j];
        }
    cout << "\n";    
    }
}

int main (){

PrintBoard(board);

}
#include <iostream>
#include <vector>

using std::cout;
using std::vector;


int main(){

    vector<vector<int>> b = {{1, 1, 2, 3},
                             {2, 1, 2, 3},
                             {3, 1, 2, 3}};

    // print lenght of vector b 
    cout << b[2].size();
    cout << "\n";
}
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main(){

    vector<vector<int>> b = {{1, 1, 2, 3},
                             {2, 1, 2, 3},
                             {3, 1, 2, 3}};

    cout << b[0][1];
    cout << "\n";
    cout << b[1][2];
    cout << "\n";
}
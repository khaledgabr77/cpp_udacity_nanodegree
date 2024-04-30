#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main(){

    vector<int> a = {1,2,3,4};
    for (int i : a){
        cout << i << "\n";
    }
}
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main (){

    vector<int> v {1,2,3};
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    v.push_back(4);

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

}
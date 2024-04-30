#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main(){


    //three ways to declear and initializing vectors
    vector<int> v_1{1, 2, 3};
    vector<int> v_2 = {4, 5, 6};
    vector<int> v_3; 
    v_3 = {7};

    //print
    cout << "Everything worked" << "\n";
}
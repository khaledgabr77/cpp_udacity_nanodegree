#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
    // Add your code here.
    vector<vector<int>> b {{1, 2},
                           {3, 4},
                           {5, 6}};

    // Write your double loop here.
    for(auto v : b) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
#include <iostream>
#include <vector>
#include "increment_and_sum.h"
using std::vector;
using std::cout;

int main() 
{
    vector<int> v{1, 2, 3, 4,5};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}


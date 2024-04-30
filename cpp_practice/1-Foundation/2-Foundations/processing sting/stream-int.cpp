#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::istringstream;

int main(){

    string a("1, 2, 3");
    istringstream my_stream(a);

    int n;
    my_stream >> n
    cout << n << "\n";
}
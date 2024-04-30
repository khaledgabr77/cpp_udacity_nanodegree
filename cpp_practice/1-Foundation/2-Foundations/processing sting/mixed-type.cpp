#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::istringstream;


int main(){

    string b{1,2,3};
    istringstream my_stream(b);

    char c;
    int n;
    
    while (my_stream >> n >> c)
    {
        cout << "the stream was successful: " << n << " " << c << "\n";

    }
    cout << "the stream had faild. " << "\n";
    
}
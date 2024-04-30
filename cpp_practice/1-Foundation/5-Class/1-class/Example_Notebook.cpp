
#include <iostream>
// Write a simple function to add two integers
int Addition(int a, int b)
{
  return a + b;
}

// Define a main() function to test the Addition() function
int main()
{
  int a = 2;
  int b = 2;
  int z = Addition(a, b);
  std::cout << a << " + " << b << " = " << z << " Yay!\n";
}

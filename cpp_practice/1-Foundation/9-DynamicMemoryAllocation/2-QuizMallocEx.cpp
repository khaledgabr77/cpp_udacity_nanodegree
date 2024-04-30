/*Quiz
Modify the example in a way that memory for 3 integers is reserved.*/


#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
     // reserve memory for several integers
    int *p2 = (int*)malloc(3*sizeof(int));
    printf("address=%p, value=%d\n", p2, *p2);

    return 0; 
}

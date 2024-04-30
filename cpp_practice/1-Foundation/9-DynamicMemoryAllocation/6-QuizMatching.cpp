#include <stdio.h> 
#include <stdlib.h> 

int main()
{
    // (X)
    int *m = (int*)malloc(sizeof(int)); 
    m = NULL; 

    // (Y)
    int *n = (int*)malloc(sizeof(int)); 
    free(n);
    *n = 23;

    // (Z)
    char *o;
    *o = 'a'; 

    return 0;
}
/*
Comments:

3-uses a dangling pointer
1-uses an uninitialized pointer
2-generates a memory leak*/

#include <stdio.h> 
#include <stdlib.h> 
  

int main(){
	struct MyStruct {
	    int i; 
	    double d; 
	    char a[5];
	};

	MyStruct *p = (MyStruct*)calloc(4,sizeof(MyStruct));
	p[0].i = 1; p[0].d = 3.14159; p[0].a[0] = 'a';

	return 0;
}

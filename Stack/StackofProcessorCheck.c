//Checking Stack is top to down or down to top
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool functionB(int *y ){
	int *x = (int*)20;
	bool retv;
	printf("Y %p\n",&y );
	printf("X %p\n",&x );
	//retvalue
	if(y < x){
		retv = false;
	}
	else
	{
		retv = true;
	}
	return retv;
}

bool functionA(){
	int y = 10;
	bool retvalue=functionB(&y);
	return retvalue;
}

int main()
{
	int a = 10 ;
	//int * tempptr;
	//tempptr = (int *)a;
	printf("Basic C code to check Processor \n");
	
	printf("Address of A in main %p \n",&a);
	printf("Stack Low to Top  %d\n",functionA());
	return 0;
}


/*
MIPS - deal with Stack 
* 


*/
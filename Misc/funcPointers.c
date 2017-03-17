#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Add (int a ,int b ){
	return a+b;
}

void useAdd(){
	int a;
	int (*p) (int,int);
	p = &Add;
	// p = Add //also works 
	a = (*p)(2,5);// dereferencing and executing the function 

	//a = p (2,5) //this also works 
	printf("Result %d",a);
}

void PrintHello(char *str){
	printf("Hello %s \n",str );
}

void usePrintHello(){

	void (*ptr) (char*);
	ptr = &PrintHello;
	ptr("Chinmay");
}

//Fuction passed as arguments 
void funcPara(void (*ptr)(char *)){
	ptr("Suraj");
}



int comparegreater (int a , int b )
{
	if(a>b)
		return 1;
	return -1;
}

int comparesmaller (int a , int b )
{
	//printf("%d  %d\n",a,b );
	if(a<b)
		return 1;
	return -1;
}

int compareabs (int a , int b )
{
	if(abs(a)>abs(b))
		return 1;
	return -1;
}





void PrintArr(int Arr[],int n ){
	int i=0;
	for(i=0;i<n;i++)
		printf("%d  ", Arr[i]);
}



//Useful example 
//Simple Bubble Sort
void Sort(int Arr[],int n,int(*compare)(int,int) ){
	int i =0,j=0,temp=0;
	for (i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if ((compare(Arr[j],Arr[j+1]))>0){
				//printf("here\n");
				temp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = temp;
			}
		}
	}
	PrintArr(Arr,n);
}




int main (){
	int A[] = {2,6,-5,4,7,-9,8,-3};
	int size = (sizeof(A)/sizeof(A[0]));
	printf("Before Sort\n");
	PrintArr(A,size);
	
	Sort(A,size,compareabs);
	printf("After Sort\n");
	PrintArr(A,size);
	//funcPara(PrintHello);
}


//Write a code for finding duplicates in a string 
#include <stdio.h>
#include <math.h>

#define true 1
#define false 0










// Recursive Fibonacci
int fib(int n){
    
    int sum=0;
    
    if(n==0 || n==1){
        return 1;
    }
    else if (n<0){
        return -1;
    }
    else if(n>1)
    {
        sum=fib(n-1)+fib(n-2);
    }
    else
    {
        return -1;
    }
    return sum;

    
}

//iterative Fibonacci 
int iterativeFib(int n){
    int a=0,b=1, c=0;
    if(n==0 || n==1){
        return 1;
    }
    else if(n<0){
        return -1;
    }
    while(n--){
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
    
    return c;
} 

int powerSet(char Arr[],int size){
    
    int powerSetSize= pow(2,size);
    int counter=0,i=0;
    int setArr[size]={0};
    //main loop
    for (counter=0;counter<powerSetSize;counter++){
        printf("{");
        for(i=0;i<size;i++){
            if(counter & 0x01<<i){
                printf("%c",Arr[i]);
            }
        }
        printf("}\n");
    }
    
    
}





int main() {
	//code
	//printf("\n Fibonacci Series: %d \n",iterativeFib(2));
	//printf("\n Recuv Fibonacci Series: %d \n",fib(2));
	char Arr[]={'a','b','c','d'};
	int size = sizeof(Arr)/sizeof(Arr[0]);
	powerSet(Arr,size);
	
	return 0;
}
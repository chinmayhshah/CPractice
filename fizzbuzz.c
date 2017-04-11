#include <stdio.h>

// input from nummber 1-100 3- display Fizz
//                          5 -Buzz
//                          3 & 5 FizzBuzz        
void displayFizzBuzz(int n){
    int i=0;
    for (i=0;i<=n;i++){
        if (i%3==0)
            printf("Fizz");
        if (i%5==0)
            printf("Buzz");
        if (i%5!=0 && i%3!=0)
            printf("%d",i);    
        printf("\n");        
    }
}
//reCursive Way 

void displayRecvFizzBuzz(int n){
        if (n==0)
            return;
        displayRecvFizzBuzz(n-1);
        
        if (n%3==0)
            printf("Fizz");
        if (n%5==0)
            printf("Buzz");
        if (n%5!=0 && n%3!=0)
            printf("%d",n);    
        printf("\n");        
        return;    
}   

int main() {
	//code
	//displayFizzBuzz(100);
	displayRecvFizzBuzz(100);
	//printf("Hello World\n");
	return 0;
}
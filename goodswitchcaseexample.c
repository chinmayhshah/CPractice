#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#define r 3



void switchchar(char c){
    switch(c){
        
        default: printf("Not a Vowel\n");        
                break;
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
                printf("Vowel\n");
                break;
        
    }
}


void cantuse(int c){
    
    
    switch(c){
        
        case r:
                printf("asd");
        case 2:
                printf("ad");
    }
    
}


void siwtchfunc(int x){
    
    int i=0;
    switch(x){
        i++;// not executed 
        default : printf("\n Default %d",i);
                    i++;
                    break;
        case 1:
                printf("\n Case 1 %d",i);
                i=1;
            //break;    
        case 2:
                printf("\n Case 2 %d",i);
                i+=2;
                break;
                
        case 3:
                printf("\n Case 3 %d",i);
                i+=3;
                //break;
                //does not jump to Default
        i++;
        
    }
    printf("\n Outside case %d",i);
        
}


int Add(int *a,int *b,int *sum){
    *sum = *a + *b;
}

int main(int argc, char const *argv[])
{
	/*
	int x;
	printf("Choose case");
	scanf("%d",&x);
	siwtchfunc(x);
    */
    /*
    char x;
	//printf("Choose case");
	scanf("%c",&x);
	switchchar(x);
    cantuse(5);
	return 0;
	*/
	int sum =0;
	int a , b;
	scanf("%d",&a);
	scanf("%d",&b);
	Add(&a,&b,&sum);
	printf("%d",sum);
	
}
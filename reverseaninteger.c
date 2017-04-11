//Write a code for finding duplicates in a string 
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
//Algo - O(n*n)// Time -
// Space - nothing
 
void reverseStr(char *Str){
    int i=0;
    int size= strlen(Str);
    char temp;
    while (i<size/2){
        temp = *(Str+i);
        *(Str+i) = *(Str+(size-i-1));
        *(Str+(size-i-1)) =temp;
        i++;
    }
}

void reverseStrAlg2(char *Str){
    char *endPtr=Str;
    char temp;
    if(Str){
        while(*endPtr!='\0'){
            ++endPtr;
        }
        --endPtr;
    }else
    {
        printf("Null Input");
        return;   
    }
    while(Str<endPtr){//** **  ** Important to reach only half ** ** ** 
        temp = *Str;
        *Str++ =*endPtr;
        *endPtr-- = temp;
        
        
    }
    //printf("\n Reversed String %s",endPtr);
    
}

int main() {
	//code
	//printf("\n Unique String %d",checkUniqueAlgo2("abcd"));
	//printf("\n Unique String %d",checkUniqueAlgo2("abcdabscd"));
	char Str[]="Reverse";
	reverseStrAlg2(Str);
	//reverseStr(Str);
	printf("\n Reversed String %s",Str);
	
	return 0;
}
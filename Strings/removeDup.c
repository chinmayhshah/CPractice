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

//doesnot work
void removeDup(char Str1[]){
    int lenght = strlen(Str1);
    int i=0,j=0;
    if(lenght){
        return;
    }
    for (i=0;i<lenght;i++){
        for(j=i;j<lenght;j++){
            if(Str1[i]==Str1[j])//if the characer 
            {
                Str1[j]=Str1[j+1];//shift the character
            }
        }
        
    }
    
    
}

void removeDupAlgo2(char Str1[]){
    int i=0,j=0;
    int tail = 1,length=strlen(Str1);
    if(Str1==NULL)
        return;
    if(length<2)
        return;
    
    for (i=1;i<=length;i++){
        for(j=0;j<=tail;j++){
            if(Str1[i]==Str1[j]){
                break;
            }
            if(j==tail){
                Str1[tail]=Str1[i];
                ++tail;
            }
        }
    }
    //Str1[tail]='\0';
}


int main() {
	//code
	//printf("\n Unique String %d",checkUniqueAlgo2("abcd"));
	//printf("\n Unique String %d",checkUniqueAlgo2("abcdabscd"));
	//char Str[]="Reverse";
	//reverseStrAlg2(Str);
	//reverseStr(Str);
	//printf("\n Reversed String %s",Str);
	char Str1[]="chihnmnaya";
	removeDupAlgo2(Str1);
	printf("\n Reversed String %s",Str1);
	
	return 0;
}
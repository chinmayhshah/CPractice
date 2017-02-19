#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkPalin(char inStr[]){
    //int len = strlen(inStr);
    int i=0;
    int j=strlen(inStr)-1;
    if(j < 0 ){
        return false ;
    }
    while (j>1){
        if(inStr[i++]!=inStr[j--]){
            printf("It is not a palindrome ");
            return false;
        }
    }
    printf("It is a palindrome ");
    return true;
}

enum StateStr {State1 , State2};
//Sta 1 -b , a 
//Sta 2 -a found ,search c o/w back to 1  
void filterString(char *inStr){
    
    int state = State1;
    int i=0,j=0;
    while (inStr[i]!='\0'){
        printf("State %d Count %d Char %c => %c\n",state,i,inStr[i],inStr[j]);
        if(state == State1){
            if(inStr[i]=='b'){
               i++;        
            }
            else if (inStr[i]=='a')
            {
                state = State2;
                i++;
            }
            else{
                inStr[j++]=inStr[i++];
            }
            
        }else{
            if(inStr[i]=='c'){
               i++;        
               state = State1;
            }
            else if (inStr[i]=='a'){
                inStr[j++]='a';
                //inStr[j]=inStr[i];
                state = State2;
                i++;
            }
            else {
                
                inStr[j++]='a';
                printf("Extra State %d Count %d Char %c => %c\n",state,i,inStr[i],inStr[j]);
                inStr[j]=inStr[i];
                i++;
                state = State1;
            }
            
            
        }
        //i++;
        
    }
    if(state == State2){
        inStr[j++]='a';
    }
    inStr[j]='\0';
    printf("IN Function  String %s",inStr);
}


int main ()
{
    char checkStr[]="abbanaccan";
    //printf("Enter the String");
    //scanf("%s",&checkStr);
    //checkPalin("madam");   
    filterString(checkStr);
    printf("New String %s",checkStr);
    
    return 0;
}
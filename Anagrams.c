//Write a code to check if the strings are anagrams or not 
#include <stdio.h>
#include <stddef.h>

#define true 1 
#define false 0



//Not working 
int checkAnagram(char Str1[],char Str2[]){
    int i =0;
    char setVal[256];//taking max 256 location
    int ascii =0;int Flag=false;
    while (Str1[i] != '\0'){
        ascii = (int)Str1[i];
        setVal[ascii] = true;
        i++;
    }
    
    i=0;
    
    while (Str2[i] != '\0'){
        ascii = (int)Str2[i];
        if(setVal[ascii]==true){
            Flag = true;
        }
        else{
            Flag = false;
            break;
        }
        i++;
        
        
    }
     
     if(Flag == false){
         return false;
     }
}


int checkAnagramAlgo2(char Str1[],char Str2[]){
    int setStr1[256]={0},setStr2[256]={0};// keeping it for 256 characaters 
    int i=0,j=0,ascii=0;
    
    //store and check 
    while(Str1[i]!='\0'){
        ascii=(int)Str1[i]; 
        setStr1[ascii]++;
        //printf("%d",setStr1[ascii]);
        i++;
    }
    
    i=0;
    while(Str2[i]!='\0'){
        ascii=(int)Str2[i]; 
        setStr2[ascii]++;
        //printf("%d",setStr2[ascii]);
        i++;
    }
    
    for(i=0;i<256;i++){
        //printf("%d %d ",setStr1[i],setStr2[i]);
        if(setStr1[i]!=setStr2[i]){
            return false;
        }
    }

    return true;
    
}

int main() {
	//code
	printf("\n Anagram %d",checkAnagramAlgo2("SILENT","LISTEN"));
	printf("\n Anagram %d",checkAnagramAlgo2("shah","hah"));
	//printf("\n Unique String %d",checkUniqueAlgo2("abcdabscd"));
	return 0;
}
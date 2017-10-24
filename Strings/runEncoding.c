#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//Example wwwwaaadexxxxxx --> w4a3d1e1x6

char * runEncoding(char * Str){
    int l_count =1 , i=0,j=0;
    if(!Str){
        return NULL;
    }
    
    char *retStr = (char*)malloc(sizeof(char)*(strlen(Str)*2+1)); //* 2...as all words can be different 
                                                                // + 1 - for ending null character 
    while(*(Str+i)){
        while(*(Str+i) == *(Str+i+1)){
            l_count++;
            i++;
        }
        *(retStr+j) = *(Str +i);
        j++;
        *(retStr+j) = l_count + '0';//can use sprintf
        l_count =1;//important to reassign to 1
        j++;
        i++;
    }
    *(retStr+j) = '\0'; // Single quotes imp
    return retStr;
}


int main() {
	//code
	printf("After Encoding %s \n",runEncoding("wwwwaaadexxxxxx"));
	printf("After Encoding %s \n",runEncoding(""));
	printf("After Encoding %s \n",runEncoding(NULL));
	printf("After Encoding %s \n",runEncoding("watch"));
	return 0;
}
/*
Output
After Encoding w4a3d1e1x6 
After Encoding  
After Encoding (null) 
After Encoding w1a1t1c1h1 
*/

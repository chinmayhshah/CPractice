// write own atoi function 

#include <stdio.h>
int checknum(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    return -1;
}

int my_atoi(char str[]){
    int num=0,negFlag=1,res=0,i=0;
    if(str[i]=='-'){
        negFlag=-1;
        i++;
    }
    
    while(str[i]!='\0'){
        if(checknum(str[i])<0){
            printf("Not an integer\n");
            return -1;
        }
        num = num*10 + str[i] -'0';
        i++;
    }
    return negFlag*num;
}

int main() {
	//code
	//char str[]="1245";
	printf("NUmber %d",my_atoi("-45234"));
	return 0;
}
//convert floating number to string 
//convert the floating string to binary representation
//own implementation 
#include <stdio.h>
#include <math.h>

//reversal
void reverseString(char *Str,int length){
    int i=0;
    char temp;
    while(i<(length-i-1)){
        temp = *(Str+i);
        *(Str+i) = *(Str+length-i-1);
        *(Str+length-i-1) = temp;
        i++;
    }
}

//convertub
int my_itoa(int srcVal,char *destStr,int maxLength){
    int length=0;
    
    while (srcVal){
        *(destStr+length) = srcVal%10 + '0';//vvimp addition of '0'
        srcVal = srcVal/10;
        length++;
    }
    
    while(length<maxLength){
        *(destStr+length++)='0';
    }
    reverseString(destStr,length);
    *(destStr+length)='\0';
    return length;
}



int my_ftoa(float srcVal,char *destStr,int afterDecimal){
    
    //3.141
    int intVal = (int)srcVal;//intVal=3
    int i=0;//count of location 
    
    float floatVal= srcVal - (float)intVal; //3.141 -3=>.141
    
    i=my_itoa(intVal,destStr,0);//returns number of elements 
    
    if(afterDecimal!=0)
    {
        *(destStr+i)='.';
        floatVal *= pow (10,afterDecimal);
        printf("value in integer %d",(int)floatVal);
        i=my_itoa(floatVal,destStr+(char)i+1,afterDecimal);
        
    }
    
    return i;
}

//convert 

int main() {
	//code
	char floatArr[15];
	//float pi =3.141;
	double pi =233.007;
	if(my_ftoa(pi,floatArr,4)<=0){
	    printf("\n Couldnt convert");
	}
	else{
	  printf("\n Float %lf to string %s",pi,floatArr);  
	}
	
	return 0;
}
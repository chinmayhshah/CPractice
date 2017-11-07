#include <stdio.h>

unsigned int countleadingZeros(int n){
    unsigned int total_bits = sizeof(int)*8;
    unsigned int count =0 ;
    
    
    for (unsigned int i =0 ;i <total_bits ; i++ ){
        
        if(n<0){
            break;
        }
        count++;
        n <<= 1;
    }
    return count;
    
}

unsigned int uncountleadingZeros(unsigned int n){
    
    unsigned int count =0 ;
    
    
    if(n <= 0x0000FFFF) count += 16 ,n <<=16;
    if(n <= 0x00FFFFFF) count += 8 ,n <<=8;
    if(n <= 0x0FFFFFFF) count += 4 ,n <<=4;
    if(n <= 0x3FFFFFFF) count += 2 ,n <<=2;
    if(n <= 0x7FFFFFFF) count ++ ;
    return count;
    
}

int main() {
    printf("Total bits %d",(int)sizeof(int)*8);
    printf("leading 0 %d\n",uncountleadingZeros(0));
    printf("leading 2 %d\n",uncountleadingZeros(2));
    printf("leading 3 %d\n",uncountleadingZeros(0x3FFFFFFF));
	//code
	return 0;
}

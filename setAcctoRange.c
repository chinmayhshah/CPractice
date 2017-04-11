#include <stdio.h>



int setRangeBits(int num1,int num2,int i,int j){
    
    int k =0,maskP=0;
    printf("Org num1 -> %x num2-> %x \n",num1,num2);
    //calculate the mask
    for(k=i-1;k<j;k++){
        maskP |= 1<<k; 
    }
    printf("Mask %x and %x \n",maskP,~maskP);
    // mask the bits of number
    num1 = num1 & maskP;
    num2 = num2 & ~(maskP);// incorrect ??  
    printf("New num1 -> %x num2-> %x \n",num1,num2);
    
    return (num2 | num1) ;
}

int main() {
    
    int a =setRangeBits(0x59,0x46,3,6);

    printf("New Set number %x",a);
	return 0;
}
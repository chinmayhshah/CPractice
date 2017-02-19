#include <stdio.h>


//positive and negative numbers
int countSetBits(int num){
    
    int countBits=0;
    if(num < 0){
        num = num * (-1);
    }
    while(num){
        if(num & 0x01){
            countBits++;
        }
        num = num >>1;
    }
    return countBits;
}

//positive and negative numbers
int countBitAlgo(int num){
    
    int countBits=0;
    if(num < 0){
        num = num * (-1);
    }
    while(num){
        num &= (num-1);
        countBits ++;
    }
    return countBits;
}



//positive and negative numbers
int BitcountUtil(int num){
    int countBits=0;
    //converting num to +ve
    if(num < 0){
        num = num * (-1);
    }
    else if(num ==0)
    {
        return 0;
    }
    
    return (num % 2==0 ? 0:1) + BitcountUtil(num/2) ;
}

int caltotal(int n){
    int totalBitSet=0;
    int i=0;
    for (i=n;i>0;i--){
        totalBitSet+= BitcountUtil(i);
    }
    
    return totalBitSet;
}


int main ()
{
    int checkNum = 0x66;
    printf("Enter the number");
    scanf("%d",&checkNum);
    printf("\nNo(1) of bits in %d => %d ", checkNum, countSetBits(checkNum));
    printf("\nNo(2) of bits in %x => %d ", checkNum, countBitAlgo(checkNum));
    printf("\nNo(3) of bits in %x => %d ", checkNum, BitcountUtil(checkNum));
    printf("\nTotal bits %d ",caltotal(checkNum));
    printf("Size of interger %ld  ", sizeof(int));
    
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INT_SIZE 32


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


int divbythree(int num){

    int even=0,odd=0;


    /*
    //may take  less loop during best case
    int oddcal = num & 0x5555;
    int evencal = num & 0xAAAA;
    if(num<0){
            num = num * -1;
    }
    while(oddcal){
        oddcal &= (oddcal -1);
        odd++;
    }

    while(evencal){
        evencal &= (evencal -1);
        even++;
    }
    */

    while(num){
        if(num & 0x01){
            odd++;
        }
        num = num >> 1;

        if(num & 0x01){
            even++;
        }
        num = num >> 1;
    }
    if(abs(even - odd)%3 ==0)
        return 0;
    else
        return 1;

}

// IN even numbers repeating 
//detect single unique number 
int detectonce(int Arr[],int size){
    int retXoR=0;int i=0;
    while(i<size){
        retXoR ^= Arr[i];
        i++;
    }
    return retXoR;
}

// IN even numbers repeating 
//detect two unique number 
//Non Sorted 
void detectwounique(int Arr[],int size){
    int Xortotal= 0,i=0;
    int lbitSet =0;int result[]={0,0};

    //find Xor of all elements - O(N)
    for (i=0;i<size;i++){
        Xortotal ^= Arr[i];
    }

    //Find the last bit which is set in this number
    lbitSet = Xortotal & (-Xortotal);
    if(!lbitSet){
        printf("cant find the two numbers using this numbers\n");
        return ;
    }

    //find first number 
    for (i = 0; i < size; ++i)
    {
        if(lbitSet & Arr[i]){
            result[0] = Arr[i] ;
        }
    }

    
    result[1] = Xortotal ^ result[0];

    printf("Two missing numbers are %d & %d \n",result[0],result[1] );
    Arr[0] =5 ;

 }


// IN odd numbers repeating 
//detect single unique number 
 //nice algorithm 
/*
arr[]={'3','3','3','8','2','2'}
1000 
 011
 011
 011
 010
 010

1033
3 and 2  

1033



*/

int detectOddOneElement(int Arr[],int size){
    
}




void displayshift(int n,int i){
    printf("Original %x  New%x \n",n,n<<i);
}



int getSingle(int arr[], int n)
{
    // Initialize result
    int result = 0;
 
    int x, sum,i,j;
 
    // Iterate through every bit
    for (i = 0; i < INT_SIZE; i++)
    {
      // Find sum of set bits at ith position in all
      // array elements
      sum = 0;
      x = (1 << i);
      for (j=0; j< n; j++ )
      {
          if (arr[j] & x)
            sum++;
      }
 
      // The bits with sum not multiple of 3, are the
      // bits of element with single occurrence.
      if (sum % 3)
        result |= x;
    }
 
    return result;
}


//T - O(n) 
//S - O(1)
int reverse (int n){
    int result=0,i=0,size=sizeof(n)*8; //* 8 very imp
    for(i=0;i<size;i++){
        if(n & 1<<i){
            result |= (1<< ((size -1)-i));
        }
    }
    return result;
}


int *tworepeating(int arr[],int size){
    
    int TotalXOR=0,nXOR=0,lbitSet=0;
    int i=0,n=size-2;
    int *result=(int *)malloc(sizeof(int)*2);
    
    if(!result){
        return NULL;
    }
    //find total XOR
    for (i=0;i<size;i++){
        TotalXOR ^= arr[i];
        //nXOR ^=i;
    }
    //printf("%d num %d \n",TotalXOR,n);
    
    //*** imp to loop till <=n
    for (i=1;i<=n;i++){
        TotalXOR ^=i;
    }
    //two repeated elements 
    //TotalXOR= TotalXOR ^ nXOR;
    
    //printf("%d\n",TotalXOR);
    //printf("%x\n",TotalXOR);
    //printf("%x\n",~(TotalXOR-1));
    //
    lbitSet =TotalXOR & -(TotalXOR-1);
    //printf("%d\n",lbitSet);

    for (i=0;i<size;i++){
        if(arr[i]^lbitSet)
            result[0]=result[0]^arr[i];
        else
            result[1]=result[1]^arr[i];        
    }
    //*** imp to loop till <=n
    for (i=1;i<=n;i++){
        if(i^lbitSet)//i
            result[0]=result[0]^i;
        else
            result[1]=result[1]^i;        
    }


    return result;
}

//print duplicates 
///will modify the array and only positive elements are present 
void findduplicate (int arr[],int size){
    int i;
    for (i=0;i<size;i++){
        if(arr[abs(arr[i])]>=0){
            arr[abs(arr[i])] =-arr[abs(arr[i])];
        }
        else
        {
            printf("%d\t",abs(arr[i]) );
        }
    }
}
















int main ()
{
    int checkNum = 0x66,i=0;
    /*
    printf("Enter the number");
    scanf("%d",&checkNum);
    printf("\nNo(1) of bits in %d => %d ", checkNum, countSetBits(checkNum));
    printf("\nNo(2) of bits in %x => %d ", checkNum, countBitAlgo(checkNum));
    printf("\nNo(3) of bits in %x => %d ", checkNum, BitcountUtil(checkNum));
    printf("\nTotal bits till inout number 0-n is %d \n",caltotal(checkNum));
    printf("Size of interger %ld  ", sizeof(int));
    */
    int listnum[] ={1,2,4,4,1,3,3,5,6,2};
    int size = (sizeof(listnum)/sizeof(listnum[0]));
    //printf("%d\n",getSingle(listnum,size));
    //int num =detectonce(listnum,size); 
    //printf("%d\n",num);
    //detectwounique(listnum,size);
    //printf("number updated %d\n",listnum[0]);
    //displayshift(1,0);
    //int x=0;
    //scanf("%d",&x);
    //printf("div by three if zero => %d ",divbythree(x));

    //int *res= tworepeating(listnum,size);
    //if(res){
     //   printf("repeating elements %d,%d \n",res[0],res[1]);
    //}
    //free(res);
    //res=NULL;


    findduplicate(listnum,size);
    /*
    for (i = 0; i < size; ++i)
    {
        printf("Original %x  New %x \n",listnum[i],reverse(listnum[i]));
    }
    */
    
    

    
}
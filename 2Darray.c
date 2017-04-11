#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//single malloc using 


void singleMalloc(int r ,int c)
{
    //int r = 3, c = 4;
    int *arr = (int *)malloc(r * c * sizeof(int));
 
    int i, j, count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         *(arr + i*c + j) = ++count;
 
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", *(arr + i*c + j));
}


//using double pointer and one malloc call for all rows


void douleMalloc(int r ,int c)
{
    //int r = 3, c = 4;
    int i, j, count = 0;
    int **arr = (int *)malloc(r*sizeof(int));
    arr[0] = (int*)malloc(r*c*sizeof(int));
    
    for (i = 0; i < r; i++){
        arr[i] = *arr + i*c;
    }
    
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         *(arr + i*c + j) = ++count;
 
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", *(arr + i*c + j));
}

void pass2Darray(int (*A)[3]){
    
    //printf("%d",*(*(A+1)+1)));
    printf("%d\n",*A[0]);
    printf("%d\n",A[0][0]);
    printf("%d\n",A[1][0]);
    printf("%d\n",*(*(A+1)));
    printf("%d\n",*(*(A)+2));
}

void print2D(){
    int A[2][3]={{1,3,5},{2,4,6}};
    
    //printf("%d",*(*(A+1)+1)));
    printf("%d\n",*A[0]);
    printf("%d\n",A[0][0]);
    printf("%d\n",A[1][0]);
    printf("%d\n",*(*(A+1)));
    printf("%d\n",*(*(A)+2));
}

int main()
{
    int B[2][3]={{1,3,5},{2,4,6}};
    //pass2Darray(B);
    //print2D();
    singleMalloc(3,5);
}


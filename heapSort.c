#include <stdio.h>
#include <stdlib.h>
//design and code for Binary Heap(MAX Heapify)
//Sort elements in ascending order

void Swap(int *p,int *q)
{
    *p = *p ^ *q;
    *q = *p ^ *q;
    *p = *p ^ *q;
    
}


//Main Heap
//elements start from ARR index 0 
void MaxHeapify(int Arr[],int heapSize,int indexPos){
    
    
    int l = 2*indexPos +1;
    int r = 2*(indexPos +1);
    int largest =indexPos;
    if(l<=0 || r<=0)
        return;
    
    if(Arr[l]>Arr[largest] && l>0 && l<heapSize){
        largest=l;
    }

    if(Arr[r]>Arr[largest] && r>0 && r<heapSize)
    {
        largest=r;
    }
    
    //Swap if new largest found 
    if(largest != indexPos){
        Swap(&Arr[largest],&Arr[indexPos]);
        MaxHeapify(Arr,heapSize,largest);
    }
    
    
}




//Heapify
void mainHeap(int Arr[],int size){
    int i=0;
    
    for(i=size/2-1;i>=0;i--){//size/2 -1 important as it is used for non leaf elements
        MaxHeapify(Arr,size,i);
    }
}

//Heap Sort implementation(MAX)
// to sort the using MaxHeapify in descending order
void heapMaxSort(int Arr[],int size){
    int k=0;
    for(k=size-1;k>0;k--){
    
        Swap(&Arr[0],&Arr[k]);
        MaxHeapify(Arr,k,0);
        
    }
}

void printArray(int Arr[],int size){
    int i=0;
    printf("Array elements");
    
    for(i=0;i<size;i++){
        printf("%d =>  %d\n",i,Arr[i]);
        
    }
}

//find starting k largest elements
int *kHeapLargest(int Arr[],int size,int k){
    int i=0;
    int *largeArr = (int*)malloc(sizeof(int)*k);
    if(!largeArr){
        return NULL;
    }
    //Form the heap
    MaxHeapify(Arr,size,0);
    
    for (i=0;i<k;i++){
        largeArr[i]=Arr[0];
        Arr[0]=Arr[size-1];
        size--;
        MaxHeapify(Arr,size,0);
        
    }
    
    return largeArr;
}


//using Bubble sort find K largest elements


int main() {
	//code
	int A[]={2,1,4,9,8,7,6};
	int size = sizeof(A)/sizeof(A[0]);
	
	printArray(A,size);
	
	mainHeap(A,size);
	
	printArray(A,size);
	
	int *ptrArr=kHeapLargest(A,size,5);
	
	if(ptrArr){
	    printArray(ptrArr,5);
	    free(ptrArr);
	}
	//heapMaxSort(A,size);
	
	//printArray(A,size);
	
	//heapMinSort(A,size);
	//printArray(A,size);
	
	return 0;
}
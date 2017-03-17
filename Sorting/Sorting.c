//Implement different sorting techniques and compare the time complexity , space and adv of each 
//



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//typedef enum A { false, true } bool;


void printArray(int Arr[],int size){
	int i=0;
	for (i=0; i<size;i++){
		printf("%d : %d \n",i,Arr[i]);
	}
	printf("\n");
}


//Bubble Sort 
//Bubble up the largest element 
/*
Worst and Average Case Time Complexity: O(n*n).
Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes

*/
void swap(int *x,int*y){
	//int *temp = *x;
	//*x = *y;
	//*y = *temp;
	//Efficient  Way
	 *x = *x ^ *y ;
	
	 *y = *x ^ *y ;
	
	 *x = *x ^ *y ;

}

//Ascending order 
void BubbleSort(int Arr[],int size){
	
	//bool swapFlag=false ;//** for removing the rerun even if sorted 
	//Main Loop
	int i=0,j=0;
	bool swapFlag=false;
	for (i=0;i < size; i++){
		//Inside Loop 
		swapFlag =false;
		for (j=0;j<size-i-1;j++) //size -i , as last element after each run will be sorted 
		{
			if(Arr[j] >= Arr[j+1]){
				swap(&Arr[j],&Arr[j+1]);//bubble up if higher element
				swapFlag = true;			
			}
		}
		//To save a loop 
                if(!swapFlag){ // if there was no swap
                     break;
                }
	}
	
}


//Insertion Sort
/*
Time Complexity: O(n*n)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
Algorithmic Paradigm: Incremental Approach
Sorting In Place: Yes
Stable: Yes
Online: Yes
Uses: Insertion sort is used when number of elements is small


*/

void InsertSort(int Arr[],int size){
	
	int hole = 0,i=0;
	int value =0 ;
	for (i=1;i<size-1;i++){
        	hole = i ;
		value = Arr[hole];
		//To fill the value if less than hole 
		while (hole > 0 && value < Arr[hole-1]){
			Arr[hole] = Arr[hole-1];
			hole = hole -1;
		}
		Arr[hole]=value;
	}
}





//Merge Sort 

//Recursive method
/*
Time complexity of Merge Sort is \Theta(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.
Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation
Stable: Yes
*/
void Merge(int Arr[],int start,int mid,int end){


	int i=0,j=0,k=0;
		
	int l1 = mid - start +1;
	int l2 = end -mid;
	//temp Arrays 
	int LeftArr[l1];
	int RightArr[l2];
	
	//Compy data from Arr to Temp arrays	
	for (i=0;i<l1;i++)
	{
	  LeftArr[i]=Arr[start +i];
	}
	
	for (i=0;i<l2;i++)
	{
	  RightArr[i]=Arr[mid+1+i];
	}

	i=0;
	j=0;
	k=start;//*** IMportant for coding ** k @ start index as same array is used 
	while (i<l1 && j<l2){//Breaks if one or both arrays complete 
		if(LeftArr[i]<=RightArr[j]){
			Arr[k]=LeftArr[i];

			i++;
		}	
		else
		{
			Arr[k]=RightArr[j];
			j++;
		}
		//if(LeftArr[i]%7==0){
		//	printf("Found element @ %d\n",LeftArr[i]);
		//}
		k++;

	}
	
	//copy rest if left out 
	while (i<l1){
		Arr[k]=LeftArr[i];
		i++;
		k++;
	}
	
	while (j<l2){
		
		Arr[k]=RightArr[j];
		j++;
		k++;
	}

}

	


void MergeSort(int Arr[],int start,int end){
	
	if(start < end){
		int mid = start + (end -start)/2 ;
		if(mid < end/2)
			return;
		//	return A;
	
		MergeSort(Arr,start,mid);
		MergeSort(Arr,mid+1,end);
		
		//if(start==mid && Arr[start]%7==0){
			//printf("print %d",Arr[start]);
		//}
			
		Merge(Arr,start,mid,end);

	}	
}


// Heap Sorting 






















int main ()
 {

  int TestArr[]={1,7,3,5,14,10,21,6};
  int size = sizeof(TestArr)/sizeof(TestArr[0]);
  printf("Array Before Sorting");
  printArray(TestArr,size);
 // BubbleSort(TestArr,size); 		
 // InsertSort(TestArr,size);	
  MergeSort(TestArr,0,size-1);	
  printArray(TestArr,size);
 		


return 0;
}


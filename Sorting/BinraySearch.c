//Implement the Binray Search
#include<stdio.h>
#include<stdlib.h>


//Only works for sorted arrays  
int BinarySearch(int *A,int key,int end){
	int start =0;
	//int end = sizeof(A)/(sizeof(A[0]));
        //int end =7 ;
	int mid=-1; 
	//int newend = sizeof(A)/(sizeof(A[0]));
 
	//printf("%d",newend);
	//logic for binray search 
	while (start <= end){

	        mid = start + (end - start)/2;// to slove issues with large numbers 
		if (A[mid] == key)
			return mid;
		else if (A[mid] > key )//on left segment of array 
		{
	  	  end=mid-1;
		}
		else {
		  start=mid+1;	
		}

	}
	
	return -1;	

}


//Use Binary Search Reucrsively 

int BinarySearchRecursive(int *Arr,int Key,int start,int end){
	//int start = 0; 
	//int end = sizeof(&Arr)/sizeof(&Arr[0])
        int mid = start + (end - start)/2 	;

	if(start > end){
		return -1;
	}
	
	if(*(Arr+mid)==Key){
		return mid;// ***Very Important 2nd base condition *****		
	}
	else if(*(Arr+mid)<Key)
	{
	   return BinarySearchRecursive(Arr,Key,mid+1,end);
	}
	else
        {
           return BinarySearchRecursive(Arr,Key,start,mid-1);
        }

//	return -1;

}

//Find Pivot 
int findPivot(int A[],int start,int end){
	// to find the pivot 

	// Base cases 
	if(end < start )
		return -1;
	if(end == start)
		return start;	
	//Find the pivot 
	int mid = start + (end - start)/2;
	// mid > mid + 1 
        if(A[mid] > A[mid+1] && mid < end)
		return mid;	

	if(A[mid] < A[mid-1] && mid > start)
		return mid-1;

	if(A[start] >= A[mid]){
		return findPivot(A,start,mid-1);
	}
	return findPivot(A,mid+1,end);
	

}





// Search in sorted and Rotated array - O(logn)

int PivotSortedSearch(int A[],int end,int key){
	
	int pivot=-1;
	pivot=findPivot(A,0,end-1);
	if(pivot < 0){// No Pivot found 
		return BinarySearchRecursive(A,key,0,end-1);
	}
	if (A[pivot]==key){
		return pivot;
	}
	if(A[pivot]<key){//*** Very IMportant Logic ********//
		return BinarySearchRecursive(A,key,0,pivot-1);
        }
	else
	{
		return BinarySearchRecursive(A,key,pivot+1,end);
	}
}

int main()
{

 printf("Binary Search\n");
 int B[]={5,6,8,9,12,1,2};
/*
 Can only be done when the scope of array is visible 
*/
int end = sizeof(B)/(sizeof(B[0]));

int index = -1;

index=PivotSortedSearch(B,end,1);
printf("Pivoted Sorted Search index @%d",index);

} 
/*
printf("Total Length of Array %d",end);
	
if(index=BinarySearch(B,2,end))
{
 printf("element %d @loc= %d\n",2,BinarySearch(B,10,end));	
}
else
{
 printf("Element not found");
}
 
 printf("\n Recursive element %d @loc= %d\n",2,BinarySearchRecursive(B,10,0,end));	
*/
 //return 0;

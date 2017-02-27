// IMplement memcpy,memmove and strstr 
//own implementation 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//** Void pointer to char casting very important to understand 

void my_memcpy(void * dest,void *source,int size_n ){

	//Typecast it to char for easier operations 
	char *dest_temp = (char *)dest;
	char *source_temp = (char *)source;
	int i = 0;

	while(i<size_n){

		*(dest_temp+i)=*(source_temp +i);
		i++;
	}
}

//taking care of overlap of destination and source values 
// it does not corrupt the solution 

void my_memmove(void *dest,void *source,int size_n){
	//
	char *dest_temp = (char *)dest;
	char *source_temp = (char *)source;
	int i =0 ;
	char * temp = (char*)malloc(sizeof(char)*size_n);

	while(i<size_n){
		*(temp +i) = *(source_temp + i) ;
		i++;
	}

	i=0;
	while(i<size_n){
		*(dest_temp +i) = *(temp + i) ;
		i++;
	}
	free(temp);
	temp =NULL;

}

//**********************important
// Memmove without using temporary buffer .
//Best way to do it w/o optmization 
//*********************
void opt_my_memmove(void * dest,void * src,int size_n){
	
	//type cast
	char *dest_temp = (char *)dest;
	char *source_temp = (char *)src;
	//find the overlap
	source_temp = source_temp + size_n;
	while(source_temp!=src && --source_temp!=dest_temp);

	
	//check  overlap 
	if(source_temp != src)//if loop breaks before 
	//other condition also works 
	//if(!(dest_temp <= source_temp || dest_temp >= source_temp + size_n))
	{
		//overlap detected 
		source_temp = (char*)src;
		//reach end for each source 
		source_temp = source_temp + size_n;
		dest_temp = dest_temp + size_n;
		//copy as overlap 
		while(size_n-- !=0){
			*(--dest_temp)=*(--source_temp);
		}
	}
	else
	{
		
		//copy as memy copy 
		while (size_n--!=0){
			*(dest_temp++) = *(source_temp++);
		}

	}	
	//dest_temp should be result in any case


}

//Strcat and Strcpy in one line 
void my_strcat(char *dest,char *src){

	return;

}



void twoDArray(int *Arr,int r ,int c){

	int i=0,j=0;

	for(i=0;i<r;i++)
		for (j = 0; j < c; j++)
		{
			printf("%d\n", (*(Arr+i*c)+j));
		}

}



int main (){



	int A[][3]={{1,4,5},{7,6,8}};
	twoDArray((int *)A,2,3);
	//printf("implementation of memcpy\n");
	/*
	char Str[] ="Chinmay Shah";
	char destStr[100];



	//**** very important size of "+1"  -- to include '\n'
	
	my_memcpy(destStr,Str,strlen(Str)+1);		

	printf("dest Str => %s\n",destStr );

	//copy another type - int
	int i;

	int a[]={1,34,46,7,7,9,4,2};
	
	int size = sizeof(a)/sizeof(a[0]);
	int dest_a[size];

	for (i=0;i<size;i++){
		printf("%d\n",a[i] ); 
	}
	

	//**** very important sizeof a (as the code uses char conversion)
	
	my_memcpy(&dest_a,&a,sizeof(a));
	printf("After copy\n");
	for (i=0;i<size;i++){
		printf("%d\n",dest_a[i] ); 
	}
	*/
	//char Str[] ="Chinmay Shah";
	//char destStr[100];
	//my_memcpy(destStr,Str,strlen(Str)+1);	
	//opt_my_memmove(Str+5,Str,strlen(Str)+1);
	//my_memmove(Str+5,Str,strlen(Str)+1);
	//printf("dest Str => %s\n",Str);

	//Overlap condition 


}




/*
OPtimization 
optimisation suggested to use int and float 
may not work all time as the address need 
to be exact divisible of 4 or 8 depending 
on machine and memory alignment. 

The while loop can be optimised by using loop unrolling. 

Loop Unrolling 
*/


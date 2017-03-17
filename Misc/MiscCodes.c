#include <stdio.h>
#include <stdlib.h>

struct st{
	int i :1;
	int j :2;
	int k :3;
	int l :4;
};

struct stu{
	unsigned int i :1;
	unsigned int j :2;
	unsigned int k :3;
	unsigned int l :4;
};



void checkEndianess(){

	//int i = 0x8000;
	int i = 0x0001;
	char *ch = (char*)&i;
	// type casting and & is very important 

	if(*ch){
		printf("Little Endian\n");
	}else
	{
		printf("Big Endian\n");

	}
}

/*
// Alligned malloc
void** Alligned_malloc(size_t bytes_reqd,size_t alignment){

	void *p1;//store original block assigned 
	void **p2;//store the alligned block 
	size_t address;
	//calculate the offset 
	size_t offset = alignment-1 + sizeof(void*);
	p1==(void *)malloc(bytes_reqd + offset); 
	if(p1!=NULL)
	{
		printf("Address alloacted for P1 => %p\n",p1);
		///find the alligned memory address 
		p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
		printf("Address p2 => %p\n",*p2);
		p2[-1] = p1;
		printf("Store original location p1 => %p\n",p1);
		return p2;

	}
	else
	{
		printf("Returning NULL\n");
		return NULL;//coud not assign 
	}

	
}


void alligned_free(void *p){
	free(((void**)p)[-1]);
}
*/


void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void* p1; // original block
    void** p2; // aligned block
    int offset = alignment - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
    	printf("failed\n");
       return NULL;
    }
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p)
{
    free(((void**)p)[-1]);
}

//2d array allocation 



//Struture usage and assign small memory 
void functionStruct(){
	struct st s1;
	struct stu s2;

	s1.i =1;
	s1.j =2;
	s1.k =5;
	s1.l =10;

	s2.i =1;
	s2.j =2;
	s2.k =5;
	s2.l =10;

	printf("i :%d ,j :%d,  k: %d , l:%d \n",s1.i,s1.j,s1.k,s1.l );
	printf("i :%d ,j :%d,  k: %d , l:%d \n",s2.i,s2.j,s2.k,s2.l );
	//printf("size : value  %ld , %d \n",sizeof(s1.i) ,s1.i );
	//printf("size : value  %ld , %d \n",sizeof(s1.j) ,s1.j );
	//printf("size : value  %ld , %d \n",sizeof(s1.k) ,s1.k );
	//printf("size : value  %ld , %d \n",sizeof(s1.l) ,s1.l );

}


void CheckFork()
{
	pid_t pid;
	pid = fork();
	//printf("Process Created\n");
	if (pid == 0) { /* child process */
	fork();
	//printf("Process Created\n");
	//thread_create( . . .);
	printf("Thread print\n");
	}
	fork();

	printf("Process Created\n");
}

int fact(int n ){
	
	if(n==0 || n==1){
		return 1;
	}
	
	return n*fact(n-1);

}

void ternary_op(){
   int a , b;

   a = 10;
   printf( "Value of b is %d\n", (a == 1) ? 20: 30 );

   printf( "Value of b is %d\n", (a == 10) ? 20: 30 );
}

int large_3nums(int a , int b ,int c){


	return a>b ? (a>c ? a:c):(b>c ? b:c);  


}

//implementation of Quick Sort using function pointers 


int main (){

	
	//fork();
	//fork();
	//printf("\n hello %d\n",getpid());
	//functionStruct();
	int *f = (void*)aligned_malloc(10,250);
	*f= 19;
	printf("%d",*f);
	printf("%p",&f);
	aligned_free(f);
	//int a , b=10;
	//a = b--- ;
	//printf("a %d  b %d \n",a,b );
	//CheckFork();
	//printf("Fibonacci value for %d",fact(3));
	//ternary_op();
	//printf("large %d\n",large_3nums(8,12,4));

	return 0;
}


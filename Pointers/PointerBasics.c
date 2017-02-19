#include<stdio.h>





void PointerAddress(){	

int x =10;
int *p=&x;

printf("Pointer address: %p\n",p);
printf("Pointer value: %d\n",*p);
printf("Pointer value:  %d\n",x);
printf("Pointer address: %p\n",&x);


 float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
 float *ptr1 = &arr[0];
 float *ptr2 = ptr1 + 3;

 printf("\n%f  ", *ptr2);
 printf("\n%ld  ", ptr2 - ptr1);
 printf("\np2 => P1   %p => %p",ptr2, ptr1);

 printf("\np2 => P1 %ld",(char*)ptr2-(char*) ptr1);
/*

Array name gives the address of first element in array. So when we do '*ptr1 = arr;', ptr1 starts holding the address of element 10. 'arr + 5' gives the address of 6th element as arithmetic is done using pointers. So 'ptr2-ptr1' gives 5. When we do '(char *)ptr2', ptr2 is type-casted to char pointer and size of character is one byte, pointer arithmetic happens considering character pointers. So we get 5*sizeof(int)/sizeof(char) as a difference of two pointers
*/
}


void PointerSize(){

int x[] ={1,34,6,67};
int *p=x;

printf("Size of x %ld\n",sizeof(x));
printf("Size of p %ld\n",sizeof(p));
char c[] = {'h','e','l','l','o'};
char *ptr=c;
printf("Size of p %ld\n",sizeof(ptr));

}
/*
Size of x 16
Size of p 8
Size of c 5
Size of p 8

*/


void DoublePointers(){

int x =10;
int *p=&x;
int **ptr = &p;

printf("Pointer address: %p\n",p);
printf("Pointer address: %p\n",&p);
printf("Pointer value: %d\n",*p);
printf("Pointer value:  %d\n",x);
printf("Pointer address: %p\n",&x);
printf("Pointer value:  %d\n",**ptr);
printf("Double Pointer address: %p\n",&ptr);
printf("Double Pointer address: %p\n",ptr);
printf("Double Pointer address: %p\n",*ptr);
/*
Pointer address: 0x7ffd324e963c - p -address of x
Pointer address: 0x7ffd324e9640 - &p
Pointer value: 10 - *p               
Pointer value:  10 - x 
Pointer address: 0x7ffd324e963c -&x - its own address
Pointer value:  10 - **p 
Double Pointer address: 0x7ffd324e9648 - &ptr - its own address 
Double Pointer address: 0x7ffd324e9640 - ptr => &p
Double Pointer address: 0x7ffd324e963c - *ptr => p  	


*/


}





int main(){


int x = 10;
void *a = (int * )&x;


//Invaild Usage
//printf ("Value of x %d",*a);
//** Needs to be casted 
printf ("Value of x %d",*(int *)a);
//PointerSize();
//PointerAddress();
//DoublePointers();

return 0;

}

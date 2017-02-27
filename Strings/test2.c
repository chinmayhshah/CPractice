#include <stdio.h>
struct test2{
    unsigned int x;
    unsigned int z;
    unsigned int x1;
    unsigned int x2;
    unsigned int x3;
    unsigned int x4;
    unsigned int x5;
};

struct test
{
unsigned int x;
long int y: 33;
unsigned int z;
struct test2 obj;
};

int main()
{
struct test t;
unsigned int *ptr1 = &t.x;
unsigned int *ptr2 = &t.z;
//unsigned int *ptr3 = &t.y;
printf("total struct %ld \n ", sizeof(struct test));
printf("total struct test2 %ld \n ", sizeof(struct test2));
printf("struct %ld \n ", ptr2 - ptr1);
printf("long int %ld \n",sizeof(long  int));
return 0;
}

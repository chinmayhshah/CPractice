#include<stdio.h>
#include<stdlib.h>


struct test
{
int x: 3;
int y: 3;
int z;
};

struct temp{
  int x:4;
  int y;
  int z;
};


int *function(){
    struct temp *t= (struct temp*)malloc(sizeof(struct temp));
    
    t->x=1;
    t->y=2;
    t->z=5;
    
    return &t->y;
}


int main()
{
    int p;
    int * q=&p;
    q =function();
    printf("Print return value %d",*q);
 
}
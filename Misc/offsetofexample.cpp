#include<stdio.h>
#include<stddef.h>

struct temp{
    int i;
    float f;
    char c;
};

struct Point
{ 
int x, y;
};

typedef struct{
    long l;
    short s;
}SBAR;

typedef struct{
    int i;
    float f;
    SBAR b;
}SFOO;

int main()
{
// Create an array of structures
//struct Point arr[10];

// Access array members
//arr[0].x = 10;
//arr[0].y = 20;

//printf("%d %d", arr[0].x, arr[0].y);
printf("Offset of 'l' is %u",offsetof(SFOO, b.l)); 

printf("Offset of 'f' in temp is %u",offsetof(struct temp, f));
return 0;
}




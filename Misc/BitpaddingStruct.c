#include <stdio.h>

// Alignment requirements
// (typical 32 bit machine)

// char     1 byte
// short int  2 bytes
// int     4 bytes
// double    8 bytes

// structure A
typedef struct structa_tag
{
char    c;
short int  s;
} structa_t;
//4
// structure B
typedef struct structb_tag
{
short int  s;
char    c;
int     i;
} structb_t;
//8
// structure C
typedef struct structc_tag
{
char    c;
double   d;
int 	 s;
} structc_t;
//24
// structure D
typedef struct structd_tag
{
double   d;
int 	 s;
char    c;
} structd_t;
//16

union u {
        double   d;
        char    c;
        int 	 s;
        
    };    
    //8

typedef struct structd_tah
{
 
    char    c[10];
    union u u1;
    int 	 s;
    float f;
    //
    
} structe_t;
//32

int main()
{
printf("sizeof(structa_t) = %d\n", sizeof(structa_t));
printf("sizeof(structb_t) = %d\n", sizeof(structb_t));
printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
printf("sizeof(structd_t) = %d\n", sizeof(structd_t));
printf("sizeof(structd_t) = %d\n", sizeof(structe_t));

return 0;
}

/*
sizeof(structa_t) = 4
sizeof(structb_t) = 8
sizeof(structc_t) = 13
sizeof(structd_t) = 16
sizeof(structe_t) = 48
sizeof(structf_t) = 48
sizeof(structx_t) = 24
sizeof(u) = 2
ut.zy = 1020
ut.z = 20
*/

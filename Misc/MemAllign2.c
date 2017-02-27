#include <stdio.h>

// Alignment requirements
// (typical 32 bit machine)

// char     1 byte
// short int  2 bytes
// int     4 bytes
// double    8 bytes

//
typedef struct structa_txg
{
int    x;
int    y;
int    z;
long int  s;
} structx_t;

// structure A
typedef struct structa_tag
{
char    c;
short int  s;
} structa_t;

// structure B
typedef struct structb_tag
{
short int  s;
char    c;
int     i;
} structb_t;

// structure C
typedef struct structc_tag
{
char    c;
double   d;
int 	 s;
}//structc_t;
__attribute((packed)) structc_t;

// structure D
typedef struct structd_tag
{
double   d;
int 	 s;
char    c;
} structd_t;

// structure E
typedef struct structe_tag
{
structa_t a;//4
structb_t b;//8
			//=12
			//+4
			//=16
structc_t c;//24
structd_t d;//16
} structe_t;



// structure F
typedef struct structf_tag
{
structa_t a;//4
structc_t c;//24
structb_t b;//8		
structd_t d;//16
} structf_t;


typedef union u
{
	char z;
	short int zy;

}u_t;

enum week{ SUNDAY, MONDAY, TUESDAY, WEDNESDAY
                       THURSDAY, FRIDAY, SATURDAY };


int main()
{


printf("sizeof(structa_t) = %d\n", sizeof(structa_t));
printf("sizeof(structb_t) = %d\n", sizeof(structb_t));
printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
printf("sizeof(structd_t) = %d\n", sizeof(structd_t));
printf("sizeof(structe_t) = %d\n", sizeof(structe_t));
printf("sizeof(structf_t) = %d\n", sizeof(structf_t));
printf("sizeof(structx_t) = %d\n", sizeof(structx_t));
printf("sizeof(u) = %d\n", sizeof(u_t));

enum week wk;
printf("sizeof(my_weekday) = %d\n", sizeof(wk));


u_t ut;
ut.zy  = 0x1020;
printf("ut.zy = %x\n", ut.zy);
printf("ut.z = %x\n", ut.z);
return 0;
}

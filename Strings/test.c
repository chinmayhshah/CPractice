#include <stdio.h>


/*
int main()
{
	int x,y;
	printf("print %d",scanf("%d %d",&x,&y)); 
	// Suppose that input value given 	for above scanf is 20 
	return 1;
} 
*/

//Scanf returns the no(inputs) read 

int main(){
	int i=0;

	while(i<50){
		switch (i%10){
			

			case 0: 		
					printf("in case  0 %d\n",i );

			case 1:
					i=i+2;
					printf("in case  1 %d\n",i );

			case 2:
					i=i+1;
					printf("in case  2 %d\n",i );
			default:
					printf("in case default %d\n",i++ );		
					break;
			case 3:
					printf("in case  3 %d\n",i );

			case 4:
					i=i+4;
					printf("in case  4 %d\n",i );

		}
		printf("Normal %d\n",i );
	}	
}



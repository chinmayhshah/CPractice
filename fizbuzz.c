// C practice Question 
// Print Fizz if div by 3 and Buzz if div by 5 
// FizzBuzz if div by both and number if neihter
#include <stdio.h>
//#include <stdlib.h>

//Assumtion values are only positive and starts from 1 
void fizzBuzz(int n){
	unsigned int i=1 ;
	while(i<=n) {
		if (i%3==0){
			printf("Fizz");
		}
		if(i%5==0){
			printf("Buzz");
		}
		if(i%3!=0 && i%5!=0){
			printf("%d",i);
		}
		printf("\n");
		i++;

	}

}



int main ()
{

	fizzBuzz(100);
	return 0;
}






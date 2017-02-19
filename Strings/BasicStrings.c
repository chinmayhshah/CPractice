#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Does not swap as when popped from stack the value gets 
// as memory location pointing exchnaged not data 
void swapStrings(char *Str1,char *Str2){
	printf("Address(in Swap String) of Str1=>%p , Str2=>%p \n",Str1,Str2);
	printf("Within Swap(Before) Strings Str1 %s Str2 %s\n",Str1,Str2 );	
	char * temp = Str1;
	Str1 = Str2;
	Str2 = temp;
	printf("Within Swap(After) Strings Str1 %s Str2 %s\n",Str1,Str2 );	
	printf("Address(in Swap String - After) of Str1=>%p , Str2=>%p \n",Str1,Str2);
	
	//strncpy(Str1,"hello",5);	
}





void swapdoubleStrings(char **Str1,char **Str2){
	printf("Within Swap(Before) Strings Str1 %s Str2 %s\n",*Str1,*Str2 );	
	char *temp = *Str1;
	*Str1 = *Str2;
	*Str2 = temp;
	printf("Within Swap(After) Strings Str1 %s Str2 %s\n",*Str1,*Str2 );	
}

int j;
void CheckStack(){

	char *Str ="Stack Memory";
	static int i;
}



int main()
{
	
	printf("Playing with Strings\n");
	char *Str1 = "Chinmay";
	char *Str2 ="Shah";
	char Str3[]="Writeable Memory";
	char *Str4 = "Read Only Memory";
	

	//Does not give write results 
	//http://www.geeksforgeeks.org/swap-strings-in-c/
	printf("Before Swap Str1 %s Str2 %s\n",Str1,Str2 );
	printf("Address of Str1=>%p , Str2=>%p \n",Str1,Str2);
	//swapStrings(Str1,Str2);
	swapdoubleStrings(&Str1,&Str2);
	printf("After Swap Str1 %s Str2 %s\n",Str1,Str2 );

	//Cant do it as stored in 
	//strncpy(Str1,"hello",5);	

	//Need to use double pointers and 
	//change the value instead of memory address 



	//
	CheckStack();

	

}
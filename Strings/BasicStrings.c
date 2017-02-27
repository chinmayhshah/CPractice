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


// as stored in Data Section not in local stack memory 
char * localString(){
	
	char *localStr ="Local String";
	//char localStr[]="Local String";// does not work as local memory 
	// array variables are stored in Stack Section
	return localStr;
}

// as stored in Data Section not in local stack memory 
//char * localString(){
int * localint(){
	
	//char *localStr ="Local String";
	int i;
	int *x = &i;
	i=10;
	//char localStr[]="Local String";// does not work as local memory 
	// array variables are stored in Stack Section
	return x;
	//return localStr;
}

char* my_StrStr(const char *str, const char *target) {
  if (!*target) return str;
  char *p1 = (char*)str;
  while (*p1) {
    char *p1Begin = p1, *p2 = (char*)target;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    if (!*p2)
      return p1Begin;
    p1 = p1Begin + 1;
    printf("NOt found %s\n",p1);
  }
  return NULL;
}

int main()
{
	
	printf("Playing with Strings\n");
	char *Str1 = "Chinmay Shah HItesh";
	char *Str2 ="Shah";
	char Str3[]="Writeable Memory";
	char *Str4 = "Read Only Memory";
	char *retStr=NULL;

	int arr[] ={1,2,3,5};
	
	//Str3[1]='K';
	//printf("%d\n",arr[2] );
	//arr[2]=7;
	//printf("String from function %s\n", localString());

	//Does not give write results 
	//http://www.geeksforgeeks.org/swap-strings-in-c/
	//printf("Before Swap Str1 %s Str2 %s\n",Str1,Str2 );
	//printf("Address of Str1=>%p , Str2=>%p \n",Str1,Str2);
	//swapStrings(Str1,Str2);
	//swapdoubleStrings(&Str1,&Str2);
	//printf("After Swap Str1 %s Str2 %s\n",Str1,Str2 );
	//printf("%d\n",arr[2] );

	//Cant do it as stored in 
	//strncpy(Str1,"hello",5);	

	//Need to use double pointers and 
	//change the value instead of memory address 
	retStr=my_StrStr(Str1,Str2);
	printf("sub string found %s\n",retStr );



	//
	//CheckStack();

	

}
// IMplementation of prefix to postfiz using Stack (implemented using Stack)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Stack
{
	int top;
	unsigned int capacity ;
	char *array;
	
}Stack;



//Stack implementation 
//Create a new stack 
Stack * createStack(int capacity){

	//imp
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	if(!stack){
		return NULL;
	}

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (char*)malloc(sizeof(char)*capacity);

	//impr
	if(!stack->array){
		return NULL;
	}

	return stack;
}


//Check if Empty 
int isEmpty(Stack *stack){

	return (stack->top==-1);
}

//check if Full 
int isFull(Stack *stack){
	return (stack->top==stack->capacity);
}


char pop(Stack *stack){
	if(isEmpty(stack)){
		return ;
	}
	//printf("return %c \n",stack->array[stack->top]);
	return (stack->array[stack->top--]);
}

char push(Stack *stack,char new_item){
	if(isFull(stack)){
		return ;
	}
	//printf("int push  %c \n",new_item);
	stack->array[++stack->top]=new_item;
}

char peek(Stack *stack){
	if(isEmpty(stack)){
		return ;
	}
	return (stack->array[stack->top]);	
}
//Stack Implementation 

int isOperand(char check){
	if((check >= '0' && check <='9') || (check >= 'a' && check <='z') || (check >= 'A' && check <='Z'))
			return 1;
	else
			return 0;
		
}

//set the precedence 
//only supporting +,- ,*,/
int precedence(char check){
	switch (check){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;	
		default :
			return 0;	
	}
}

//print the next element 
void nextGreater(int arr[],int size){
	int i=0,next,temp;

	Stack *stack = createStack(size);

	//push the first element 
	push(stack,arr[i]);
	i++;
	while (i<size){
	
		next = arr[i];
		if(!isEmpty(stack)){
			temp = pop(stack);
			//printf("%d(temp) => %d (next)\n",temp,next);
			while(next > temp){
					printf("%d => %d (next)\n",temp,next);
					if(isEmpty(stack)){
						break;
					}
					temp = pop(stack);
			}
			if(next < temp)
			{
				push(stack,temp);
			}
		
		}	
		push(stack,next);
		i++;
	}

	//remainder elements not having any greater 
	while(!isEmpty(stack)){
		temp = pop(stack);
		printf("%d => %d (next)\n",temp,-1);
	}


}


//Implement prefix to post fix 

int preToPost(char * exp){

	int k,i;//counter for new postfix expr
	//create the stack 
	Stack *stack = createStack(strlen(exp));
	printf("old exp %s\n", exp);
	if(!stack){
		printf("NO stack\n");
		return;
	}
	//check if the element is operator or operand then 
	//while(exp[i]!='\0'){
	//for(i=0,k=-1;exp[i];++i){
	k=-1;
	for(i=0;i<strlen(exp);i++){
		printf(" i => j %d=>%d\n",i,k );
		if(isOperand(exp[i])){
			//k++;		
			exp[++k]=exp[i];	
		}
		else if (exp[i]=='('){
			push(stack,exp[i]);
		}
		else if (exp[i]==')')
		{
			//if you find the ')' to pop and store it in expr(till '(s')
			while( !isEmpty(stack) && peek(stack)!='(' ){
				exp[++k]=pop(stack);	
			}
			//*** imp
			//if end reached and '(' not found 
			//if end and no '(' then issue with expression , no balance in ()
			if(!isEmpty(stack) && peek(stack)!='('){
				printf("Invalid expression\n");
				return -1;
			}	
			else
				pop(stack);
			
		}
		else//operator encountered
		{
				//two conditions 
				//1) if no operator on stack 
				//2) 

				//check the stack for precedence 
				while(!isEmpty(stack) && precedence(exp[i])<= precedence(peek(stack))){
					exp[++k] = pop(stack);
				}
				push(stack,exp[i]);		
		}
	}
		//left out experession value 
	while (!isEmpty(stack)){
		exp[++k]=pop(stack);
	}
	exp[++k]='\0';

	//vvimp to \o

	//printf("Post %s\n",exp);

}



int main (){

	printf("IMplementation of prefix to postfix and eval postfix\n");
	char Str[]="a+b*(c^d-e)^(f+g*h)-i";
	int i=0;

	//*works fine
	//int array[] = {1,3,23,8,5,20};
	//nextGreater(array,sizeof(array)/sizeof(array[0]));


	/*
	Stack * stack = createStack(strlen(Str));

	for (i=0;i<strlen(Str);i++){
		//printf("push value %c\n",Str[i]);
		push(stack,Str[i]);	
	}
	
	for (i=0;i<strlen(Str);i++){
		printf("%c",pop(stack));
	}
	printf("\n");
	*/
	printf("Pre %s\n",Str);
	preToPost(Str);
	printf("Post %s\n",Str);
	

}

























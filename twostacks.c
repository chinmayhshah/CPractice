#include <stdio.h>
#include <stdlib.h>

struct twoStacks{
    int *array;
    int top1;
    int top2;
    int size;
};

struct twoStacks *createStacks(int n){
    
    struct twoStacks *stack = (struct twoStacks*)malloc(sizeof(struct twoStacks));
    if(!stack){
        return NULL;
    }
    stack->array = (int *)malloc(sizeof(int)*n);
    if(!stack->array){
        return NULL;
    }
    stack->top1 = -1;
    stack->top2 = n;
    stack->size = n;
    return stack;
}


void push1(struct twoStacks * stack,int data ){
    if(stack->top1 < stack->top2 -1){
        stack->array[++stack->top1] = data;    
    }
    else
    {
        printf("Stack Overflow \n");
    }
    
}


void push2(struct twoStacks * stack,int data ){
    
    if(stack->top1 < stack->top2 -1){
        stack->array[--stack->top2] = data;
    }else{
        printf("Stack Overflow \n");
    }
    
    
}

int pop1(struct twoStacks * stack){
    if (stack->top1 == -1){
        return -1;
    }
    return stack->array[stack->top1--];
}

int pop2(struct twoStacks * stack){
    if (stack->top2>stack->size){
        return -1;
    }
    return stack->array[stack->top2++];
}
int main() {
	struct twoStacks * ts = createStacks(5);
    
    push2(ts,10);
    
    
    push2(ts,15);
    push1(ts,5);
    push1(ts,11);
    push2(ts,7);
    printf("\n Popped element from stack1 is %d",pop1(ts));
    printf("\n Popped element from stack1 is %d",pop1(ts));
    push2(ts,40);
    printf("\n Popped element from stack2 is %d ",pop2(ts));
    printf("\n Popped element from stack2 is %d ",pop2(ts));
    printf("\n Popped element from stack2 is %d ",pop2(ts));
    printf("\n Popped element from stack2 is %d ",pop2(ts));
    printf("\n Popped element from stack2 is %d ",pop2(ts));
    printf("\n Popped element from stack2 is %d ",pop2(ts));
    push2(ts,10);
    push2(ts,20);
    push2(ts,30);
    push2(ts,40);
    push2(ts,50);
    push2(ts,60);
    push2(ts,100);
    
    
    
    return 0;
}

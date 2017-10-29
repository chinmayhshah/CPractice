//Circular Queue 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct  Node
{
	int data;
	struct Node * next;
};

struct Queue
{
	struct Node *rear, *front;
};

struct Queue * CreateQueue(){
	struct Queue * queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;

} 
//enqueue --> adds at rear 
int enQueue(struct Queue *q,int value){

	if(!q){
		return NULL;
	}
	//Create a temp node 
	//Add at end 
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if(!temp){
		return NULL;
	}
	temp->data = value;
	// add enqueue 
	if(q->front==NULL){
		q->front = temp;
	}else
	{
		q->rear->next = temp; 
	}
	q->rear = temp;
	//keep the circular link to front
	q->rear->next = q->front;
}

int deQueue(struct Queue *q){
    int value;
	if(q->front == NULL){
		printf("Queue is Empty\n");
		return NULL;
	}
	struct Node *temp = q->front;
	if(q->front == q->rear ){		
		q->front = q->rear = NULL;
		free(q->front);
	}else{	
		q->front = q->front->next;
		q->rear->next = q->front;
	}	
	value = temp->data;
	free(temp);
	return value;
}
void displayQueue(struct Queue * queue){
	struct Node * q = queue->front;
	printf("\n");
	while(q->next != queue->front){
		printf("%d ",q->data);
		q=q->next;
	}
	printf("%d ",q->data);

}

int main(){
    struct Queue * q = CreateQueue();
    // Inserting elements in Circular Queue
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);
 
    // Display elements present in Circular Queue

    displayQueue(q);
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));
 
    // Remaining elements in Circular Queue
    displayQueue(q);
 
    enQueue(q, 9);
    enQueue(q, 20);
    displayQueue(q);
 
    return 0;

}

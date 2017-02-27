//IMplement Queue using Link List 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct of LL 
struct Node{
	int data;
	struct  Node *next;
};

//Strcut of Queue 
struct Queue{
	struct Node * rear;
	struct Node * front;	
};

//Important 
// New Node 
struct Node* NodeCreate(int data){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data =data;
	temp->next = NULL;
	return temp;
}

// New Queue Creation 
struct Queue *QueueCreate(){
	struct Queue *Q_new = (struct Queue*)malloc(sizeof(struct Queue));
	Q_new->rear = Q_new ->front = NULL;
	return Q_new;
}

//Check if it is Empty 
int isEmpty(struct Queue *Q_test){
	//imp to check for rear 
	return (Q_test->rear==NULL);
}

//No concept of Full as capacity is not an issue

//Enqueue
void Enqueue(struct Queue *Q_n,int newdata){
	//struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	//new_node->data 
	struct Node* new_node= NodeCreate(newdata);

	//If empty 
	if(isEmpty(Q_n)){
		Q_n->front= Q_n->rear=new_node ;
		return;
	}
	Q_n->rear->next = new_node;
	Q_n->rear = new_node;
	//printf("adding the element %d\n",new_node->data);

}

//Dequeue and delete from the front 
struct Node* Dequeue(struct Queue *Q_n){
	int temp ;
	if(isEmpty(Q_n)){
		return NULL;
	}

	struct Node *temp_node= Q_n->front;
	Q_n->front=Q_n->front->next;

	if(Q_n->front==NULL){
		Q_n->rear=NULL;
	}
	//printf("deleting the element %d\n",temp_node->data);
	//free(temp);
	return temp_node;

}


int main(){

	printf("IMplement Queue using LL \n");
	struct Queue *Q_impl = QueueCreate();
	Enqueue(Q_impl,10);
	Enqueue(Q_impl,20);
	Enqueue(Q_impl,30);
	Enqueue(Q_impl,40);
	Dequeue(Q_impl);
	Dequeue(Q_impl);
	Enqueue(Q_impl,50);
	Enqueue(Q_impl,60);
	struct Node* n= Dequeue(Q_impl);
	if(n){
		printf("Key %d\n",n->data);
	}
	return 0;
}
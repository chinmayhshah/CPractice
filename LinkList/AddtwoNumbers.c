//Add two numbers present in LinkLIST
//Q1 - LSB - MSB stored implementation 
//Q2- MSB to LSB representation 
/*
Q2
First list : 5->6->3 //represents 563

second List : 8->4->2 //represents 842

Output 
	Resultant List: 1->4->0->5   //represents 1405
Ask interviewer , how it is stored ?

*** go through the code of max multiple timses ....many mistakes made 
*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
	int data;
	struct node *next;
}Node_tydef;

Node_tydef *newnode(int data){

	Node_tydef *n_node = (Node_tydef *)malloc(sizeof(Node_tydef));
	n_node->data=data;
	n_node->next=NULL;

	return n_node;
}

//Display the data of the Link List 
void displayList(Node_tydef *head){

	Node_tydef * curr=head; 
	while (curr!=NULL){
		printf("%d\t",curr->data );
		curr = curr ->next;
	}
	printf("\n");

}


//Push Data on Link List normally 
void push(Node_tydef **head_ref,int n_data){

	Node_tydef *n_node = newnode(n_data);
	n_node->next = *(head_ref);
	*(head_ref)=n_node;

}


void insertatEnd(Node_tydef **head,int data){

	Node_tydef *n_node = newnode(data);
	Node_tydef *curr=*(head);
	if(!(*head)){
		//n_node->next=head->next;
		*head=n_node;

	}else{
		
		while(curr->next!=NULL){
			curr=curr->next;			
		}
		curr->next = n_node;
	}

}



//**** Important to while insertion should as it is adding LSB last 
// dont use extra space 
//check if numbers are negative or positive 

Node_tydef * findHeadLSBSum(Node_tydef *num1,Node_tydef *num2){
	Node_tydef *head_sum =NULL;
	// (Node_tydef*)malloc(sizeof(Node_tydef*));
	int carry=0,sum=0,data1=0,data2=0;
	while(num1 || num2){// Till one of them is not null 
		//Find sum 
		//Transverse till last
		if (num1){
			data1 = num1->data;
			num1 = num1->next;
		}else{
			data1 =0;
		}

		if(num2){
			data2 = num2->data;
			num2 = num2->next;
		}else
		{
			data2 =0;
		}
		sum = data1 + data2 + carry;

		//carry calculation 
		if(sum>=10){
			carry =1;
			sum	= sum %10;
		}
		else{
			carry =0;
		}

		
		insertatEnd(&head_sum,sum);
	}

	//if last sum generates a carry 
	if(carry){
		insertatEnd(&head_sum,carry);
	}

	return head_sum;

}


typedef struct result{
	int sum;
	int carry;
}result_tydef;
//**** Important 

/*
Q2
First list : 5->6->3 //represents 563

second List : 8->4->2 //represents 842

Output 
	Resultant List: 1->4->0->5   //represents 1405
Ask interviewer , how it is stored ?
*/
Node_tydef *addSameLenght(Node_tydef *head1,Node_tydef *head2,int *carry){


	//reached the end () - base condition 
	if( head1 ==NULL)
		return NULL;

	int sum=0;	

	Node_tydef *result = newnode(0);
	// ** importatn to point to next node 
	result->next = addSameLenght(head1->next,head2->next,carry);

	sum= head1->data + head2->data + *carry;
	if(sum >= 10){
			*carry =1;
			sum %= 10; 
	}
	else{
		*carry =0 ;
	}

	result->data=sum;

	return result;
}



//Add for rest then same lenght
void addRemLength(Node_tydef *head,Node_tydef *curr,int *carry,Node_tydef ** result){

	int sum=0;
	if(head != curr){

	
		addRemLength(head->next,curr,carry,result);
		sum = head->data + *carry;	
		*carry =sum/10;
		sum = sum %10;

		push(result,sum);
	}	
	
}

int findSize (Node_tydef *temp){
	//Node_tydef * curr=head;
	int size=0;
	while(temp){
		size++;
		temp = temp->next;
	}
	return size;
}

void swapointer(Node_tydef **t1, Node_tydef **t2){
	Node_tydef *temp = *t1;
	*t1 = *t2;
	*t2 = temp;


}

void findHeadMSBSum(Node_tydef *head1,Node_tydef *head2,Node_tydef **result){

	//find size and diff 
	int size1 = findSize(head1);
	int size2 = findSize(head2);
	int i=0,carry=0,diff=0;
	Node_tydef * curr;
	//check if same 
	if(size1==size2){
		*result=addSameLenght(head1,head2,&carry);
	}
	else{//if not move it till diff in head 
		diff =abs(size1 - size2);

		if(size1<size2){//swap as need to work only with one node 
			//Node_tydef *temp = head1;
			//head1 = head2;
			//head2 = temp;	
			swapointer(&head1,&head2);
		}
		curr = head1;
		for (i=0;i<diff;i++){
			curr = curr->next;
		}
		//then add the same recursive way 
		*result=addSameLenght(curr,head2,&carry);

		//Add Remaning 
		//** be careful with calling functions**
		addRemLength(head1,curr,&carry,result);
	}
	if (carry){
		push(result,carry);
	}

}


int main (){
	


	Node_tydef *first=NULL;
	Node_tydef *second=NULL;
	Node_tydef *sum=NULL;

	//Q1 driver program 
	push(&first,3);
	push(&first,6);
	push(&first,5);
	//push(&first,5);

	displayList(first);

	push(&second,8);
	push(&second,4);
	push(&second,6);
	push(&second,1);


	displayList(second);

	//sum=findHeadLSBSum(first,second);
	//displayList(sum);
	/*
	365 + 248 =613
		5	6	3	
		8	4	2	
		3	1	6	
	*/

	//Q2 driver program 

	findHeadMSBSum(first,second,&sum);
	displayList(sum);

	return 0;
}


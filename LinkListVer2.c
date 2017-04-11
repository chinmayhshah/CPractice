//Write a code for finding duplicates in a string 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *next;
}Node;


void printList(Node *head){
    Node *curr = head;
    while (curr!=NULL){
        printf("\n %d => %p",curr->data,curr);
        curr=curr->next;
    }
}

Node * createNode(int newData){
    Node *newNode = (Node *)malloc(sizeof(Node*));
    newNode->next=NULL;
    newNode->data=newData;
    return newNode;
}


//push at head
void push(Node **head_ref,int data){
    
    Node *newNode = createNode(data);
    newNode->next = *(head_ref);
    *(head_ref) = newNode;
    
}

/*deletion conditions 
1.  At start of LL
2.  Mid of LL
3.  End of LL 

*/
int deleteNode(Node *delNode){
    
    Node *freeNode ;
    
    
    //if first Node
    //if last node 
    if(delNode->next== NULL){
        
    }
    
    
}

//remove Duplicate from Link List w/o sorting
//using a hash table /array /buffer
void removeDuplicate(Node *head_ref){
    
    Node *curr=head_ref,*prev=head_ref;
    int setArray[100]={0};//max 100 elements 
    while(curr!=NULL){
        if(setArray[curr->data]>0){
              prev->next=curr->next; 
        }
        else
        {
            setArray[curr->data]=1;
        }
        prev =curr;
        curr = curr ->next;
    }
}

//remove Duplicate from Link List w/o sorting
//without using a hash table /array /buffer
void removeDuplicateAlgo2(Node *head_ref){
  
  //two pointers , one pointing to current element 
  //second prev running from curr to prev
  Node *curr=head_ref,*prev=NULL,*track=head_ref;
  
  //corner cases 
  if(!curr || curr->next==NULL){
      return;
  }
  
  //printf("hi1");
  
  
  //main logic 
  while(curr->next!=NULL){//main loop
    track=head_ref;
    //printf("\n%d , %d ",track->data,curr->data);
        while(curr!=track && curr->data!=track->data){
            prev=track;
            track=track->next;//move fwd
            //printf("\n%d , %d ",track->data,curr->data);
        }
        if(curr!=track){//check if duplicate found 
            //printf("\nBreak %d , %d ",track->data,curr->data);
            prev->next=track->next; 
            //= curr->next;
        }
    curr=curr->next;//move on main loop
  }
  
  
}

int findNthElementFromLast(Node *head,int n){
    
    Node *curr=head,*prev=head;
    int i=0;
    
    //corner cases
    if(!head){
        printf("\n No elements");
        return -1;
    }
    
    //move the curr to n postion 
    while(i++<n && curr->next!=NULL){
        curr=curr->next;
    }
    if(curr->next==NULL){
        printf("\n Not enough elements");
        return -1;
    }
    //to move prev to nt position from last 
    while(curr->next!=NULL){
        curr=curr->next;
        prev=prev->next;
    }
    
    return prev->data;
    
}


//Delete a node using a node access 
//cant work if node is last (or dummy node can be added )
int deleteGivenNode(Node *delNode){
    
    //Invalid case 
    if(delNode->next == NULL || delNode==NULL){
        return -1;
    }
    Node *temp = delNode->next;
    //move to next node
    delNode->data=temp->data;
    //code from next node
    delNode->next= temp->next;
    
    
    free(temp);
    return 0;
}

//first detect the loop and implement the algorithm
/*
Logic
Detect Loop: fast and slow pointer

Find loop point : when slow enters the loopp, fast is k step head start and once they meet
the intersection point is k nodes away same from start point 

* to find the start of loop 
-slow form head 
-fast at meeting point 
-same transversal speed 
-meet at intersection point
*/
Node *detectLoop(Node *head){
    Node *fast=head,*slow=head;
    
    // no elements in Link List
    if(!head || !head->next){
        return NULL;
    }
    //detect if there is loop 
    //moving at different speeds 
    while(fast){
        fast = fast->next->next;
        slow = slow->next;   
        //vvimp to move the pointers and den check for fast and slow 
        if(fast ==slow){
            break;
        }
     
    }
    
    // didnt find loop
    if(fast != slow || !(fast)){
        return NULL;
    }
    printf("Detected loop %d ",fast->data);
    
    //reset to find the intersection point 
    //moving at same speed
    slow = head;
    //find loop point
    while (fast!=slow && fast){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    if(fast!=slow){
        return NULL;
    }
    
    return slow;
    
}

int main() {
	//driver function 
	Node *head=NULL;
	
	push(&head,1);
	
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);

    head->next->next->next->next->next->next->next = head->next->next;	
	
	//printList(head);
	

	
	//Test for removal of duplicates 
	//removeDuplicateAlgo2(head);
	//printf("\n After Removing Duplicates");
	//printList(head);
	
	//Delete a given Node
	/*
	if((deleteGivenNode(head))<0){
	    printf("Cant delete");
	}else{
    	printf("\n After deleting");
    	printList(head);
	}	
	*/
	//printf("\n Finding nth element from last %d",findNthElementFromLast(head,11));
	Node *detectNode=detectLoop(head);
	if(detectNode){
	    printf("\n Loop Point %d",detectNode->data);
	}else
	    printf("\n No Loop Foundyy");
	return 0;
}
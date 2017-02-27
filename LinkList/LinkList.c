#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;  
};


void push(struct node** head,int new_data)
{
    struct node * new_node = (struct node *)malloc(sizeof(struct node*));
    
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}


int countList(struct node * head){
    
    struct node* current = head;
    int count=0;//dont forget intialization
    while(current!=NULL){
        count ++;
        current = current->next;
    }
    return count;
    
}
//reverse iteratively
struct node * reverseList(struct node *head){
    struct node *curr=head;
    struct node *prev=NULL,*next=NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        //shift
        prev = curr;
        curr = next;
        
    }
    head = prev;///very important
}

//reverse recursively
struct node * reverseKList(struct node *head,int k){
    struct node *curr=head;
    struct node *prev=NULL,*next=NULL;
    int count =0;
    while(curr!=NULL && count <k){
        next = curr->next;
        curr->next = prev;
        //shift
        prev = curr;
        curr = next;
        count++;
        
    }
    //
    if(next!=NULL){
        head->next=reverseKList(next,k);
    }

    return prev;///very important
}







int compareList(struct node *one, struct node *two){
    
    //if any list is Empty
    if(one==NULL){
        return -1;
    }
    
    if(two==NULL){
        return -1;
    }
    
    //transverse and check all 
    while(two!=NULL){
        if(one->data != two->data){
            printf("one =>%d two=>%d ",one->data,two->data);
            return 0;
        }
        one= one->next;
        two= two->next;
    }
    return 1;
    
    
}



void printList(struct node *head_ref){
    struct node *curr=head_ref;
    printf("List of LL\n");
    if(curr==NULL){
        printf("Empty Link List");
    }
    while(curr!=NULL){
        printf("%d\n",curr->data);
        curr=curr->next;
    }
}



int CheckPlaindrome(struct node *head){
    
    struct node *mid=NULL,*prev_slow=head;
    struct node *fast=head,*slow=head ;
    int comp=0;
    
    
    //Find Mid point 
    while (fast!=NULL && fast->next != NULL){
        
        fast = fast->next->next;
        //for odd
        prev_slow=slow;
        slow = slow->next;
    }
 
    //if odd terms 
    if(fast!=NULL){
        mid = slow;
        slow= slow->next;
    }
    //end of Mid find 
    
    struct node * second_half=slow;
    //reverse Second half 
    second_half=reverseList(second_half);
    comp = compareList(head,second_half);
    if(comp==1){
        printf("It is a Plaindrome %d ",comp);
        second_half=reverseList(second_half);
    }
    else{
        printf("It is not a Plaindrome %d",comp);
    }
    printList(head);


    
    //found mid
    //return slow;
}







//recursively
void printListBack(struct node *head){
    
    if (head==NULL){
        return;
    }
    
    printListBack(head->next);
    printf("%d",head->data);
}



/*
//reverse using recursion 
struct node * recuvReverseList(struct node *head){
    //struct node *curr=head;
    //struct node *prev=NULL,*next=NULL;
        while(head!=NULL){
                
            
        }
    
}
*/


void findMid(struct node *head){

    struct node *mid=NULL;
    struct node *fast=head,*slow=head ;
    struct node *prev_slow=NULL;
    int comp=0;
    
    
    //Find Mid point 
    printf("%d %d", fast->data, slow->data);

    while (fast!=NULL && fast->next != NULL){
        
        fast = fast->next->next;
        //for odd
        prev_slow=slow;
        slow = slow->next;
    }
 
    //if odd terms 
    if(fast!=NULL){
        mid = slow;
        slow= slow->next;
    }
    //end of Mid find 


}

int main ()
{   
    
    struct node *List_head=NULL;
    struct node *mid_point=NULL;
    printf("Link List Count");
    
    //push(&List_head,1);
    
    //push(&List_head,1);
    
    push(&List_head,1);
    push(&List_head,2);
    push(&List_head,3);
    push(&List_head,4);
    push(&List_head,5);
    push(&List_head,6);
    push(&List_head,7);
    //push(&List_head,8);

    //printf("Link List Count => %d ",countList(List_head));
    
    printList(List_head);

    reverseKList(List_head,3);

    printList(List_head);
    //printListBack(List_head);
    //mid_point=FindMidNode(List_head);
    //printf("\n\n Data of mid node %d",mid_point->data);
    //CheckPlaindrome(List_head);
    
    
    
    //printf("\nLL reveresed\n");
    //List_head=reverseList(List_head);
    //printList(List_head);
    return 0;
    
}




#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//new node creation 
struct node * newNode(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right =NULL;
    return temp;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
    

}

void preorder(struct node *root){
    if(root != NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d \n",root->data);
    }
    

}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d \n",root->data);
    }
    

}
struct node * search(struct node * root,int key){
    if(root==NULL && root->data == key)
        return root;
        
    if(key< root->data){
        return search(root->left,key);
    }   
    
    return search(root->left,key);
}



struct node* insert(struct node* node,int newitem){
    if(node==NULL){
        return newNode(newitem);   
    }
    
    if(newitem < node->data){
        node->left = insert(node->left,newitem);
    }
    else{
        node->right = insert(node->right,newitem);
    }
    
    
    return node;
}



int main ()
{   
    
    struct node *root=NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    
    //printf inorder
    inorder(root);
    printf("Pre");
    preorder(root);
    printf("Post");
    postorder(root);
    
    return 0;
    
}




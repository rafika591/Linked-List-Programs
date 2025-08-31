// Merge two sorted list and reverse it
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
    struct Node*head=NULL;
    void insertEnd(int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return ;
    }
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return ;
} 
void display(){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void leftShift(int k){
    if(!head||k==0){
        return;
    }
    struct Node*temp=head;
    int len=1;
    while(temp->next){
        temp=temp->next;
        len++;
    }
    temp->next=head;
    k%=len;
    for(int i=0;i<k;i++){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;

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
void swapPairs(){
    struct Node*temp=head;
    while(temp && temp->next){
    int tmp=temp->data;
    temp->data=temp->next->data;
    temp->next->data=tmp;
    temp=temp->next->next;
}
}
int main(){
    int n,v;
    printf("Enter number of nodes: "); scanf("%d",&n);
    for(int i=0;i<n;i++){ printf("Enter value: "); scanf("%d",&v); insertEnd(v);}
    display();
    swapPairs();
    display();
    return 0;
}

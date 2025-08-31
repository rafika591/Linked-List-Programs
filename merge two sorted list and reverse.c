// Merge two sorted list and reverse it
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* insertEnd(struct Node*head,int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return newNode;
    }
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
} 
void display(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
struct Node*merge(struct Node*h1,struct Node*h2){
    if(h1==NULL)return h2;
    if(h2==NULL)return h1;
    struct Node*result=NULL;
    if(h1->data<h2->data){
        result=h1;
        result->next=merge(h1->next,h2);
    }
    else{
        result=h2;
        result->next=merge(h1,h2->next);
    }
    return result;
    }
    struct Node *reverse(struct Node*head){
        struct Node*next=NULL;
        struct Node*curr=head;
        struct Node*prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int main(){
        struct Node*h1=NULL,*h2=NULL,*result=NULL;
       int n1,n2,val;
        printf("n1:");
        scanf("%d",&n1);
        for(int i=0;i<n1;i++){
            printf("Enter value");
            scanf("%d",&val);
            h1=insertEnd(h1,val);
        }
         printf("n2:");
        scanf("%d",&n2);
        for(int i=0;i<n2;i++){
            printf("Enter value");
            scanf("%d",&val);
            h2=insertEnd(h2,val);
    }
    result=merge(h1,h2);
    printf("Merged:");
    display(result);
    result=reverse(result);
    printf("Result:");
    display(result);
    return 0;
    }

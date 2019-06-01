#include<stdio.h>
#include<stdlib.h>
struct ll{
    int data;
    struct ll *next;
};

int search(struct ll *head, int data, struct ll **prev){
    struct ll *temp=head;
    *prev=NULL;
    while(temp){
        if(data==temp->data)
            return 1;
        temp=temp->next;
    }
    return 0;
}
int insert(struct ll **head, int data){
    struct ll *prev=NULL, *newnode=NULL;
    if(search(*head, data, &prev))
        return 0;
    newnode=(struct ll *)malloc(sizeof(struct ll));
    if (!newnode)
        return 0;
    newnode->data=data;
    if (!prev){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        newnode->next=prev->next;
        prev->next=newnode;
    }
    return 1;
}
int del(struct ll **head, int data){
    struct ll *prev=NULL, *temp=*head;
    if(!search(*head, data, &prev))
        return 0;
    if(!prev){
        temp=*head;
        *head=(*head)->next;
    }
    else{
        temp=prev->next;
        prev->next=temp->next;
    }
    free(temp);
    return 1;
}
void traverse(struct ll *head){
    struct ll *temp=head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

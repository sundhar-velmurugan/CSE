#include <stdio.h>
#include<stdlib.h>
struct ll{
    int data;
    struct ll *next;
};

int search(struct ll *head, int data, struct ll **prev){
    struct ll *temp=head;
    *prev=NULL;
    while (temp&& temp->data<data){
        *prev=temp;
        temp=temp->next;
    }
    if (!temp)
        return 0;//we don't want the control to check something's data which is not defined
    else if (temp->data==data)
        return 1;
    else
        return 0;
}
int insert(struct ll **head, int data){
    struct ll *prev=NULL, *newnode=NULL;
    if (search(*head, data, &prev))
        return 0;
    newnode= (struct ll *)malloc(sizeof(struct ll));
    if (!newnode)
        return 0;
    newnode->data=data;
    if(!prev){
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
    struct ll *temp=NULL, *prev=NULL;
    if (!search(*head, data, &prev))
        return 0;
    if (!prev){
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
    struct ll *temp= head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

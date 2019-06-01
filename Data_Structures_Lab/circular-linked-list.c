#include <stdio.h>
#include<stdlib.h>
struct ll{
    int data;
    struct ll *next;
};

int search(struct ll *head, int data, struct ll **prev){
    struct ll *temp=head;
    *prev=NULL;
    if(!head)
        return 0;
    do{
        if(temp->data>data)//list in ascending order
            break;
        *prev=temp;
        temp=temp->next;
    }while(temp!=head);
    if(!temp)
        return 0;
    (temp->data==data)
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
    if(!(*head)){
        newnode->next=*head;
        *head=newnode;
    }
    if(!prev){//no prev after search, when inserting element is the smallest
        struct ll *last=*head;
        while(last->next!=*head){
            last=last->next;
        }
        newnode->next=last->next;
        last->next=newnode;
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
    if((*head)->next==(*head)){
        temp=*head;
        *head=NULL;
    }
    if(!prev){
        struct ll *last=*head;
        while(last->next!=*head){
            last=last->next;
        }
        temp=*head;
        *head=(*head)->next;
        last->next=*head;
    }
    else{
        temp=prev->next;
        prev->next=temp->next;
    }
    free(temp);
    return 1;
}
int traverse(struct ll *head){
    struct ll *temp= head;
    if(!head)
        return 0;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp->next!=head);
    return 1;
}

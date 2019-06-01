#include <stdio.h>
#include<stdlib.h>
struct ll{
    int data;
    struct ll *next;
    struct ll *prev;
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
int insert(struct ll **head, struct ll **tail, int data){
    struct ll *prev=NULL, *newnode=NULL;
    if(search(*head, data, &prev))
        return 0;
    newnode=(struct ll *)malloc(sizeof(struct ll));
    if(!newnode)
        return 0;
    newnode->data=data;
    if (!prev){
        newnode->prev=NULL;
        newnode->next=*head;
        if(*head)
            (*head)->prev=newnode;
        else
            *tail=newnode;
        *head=newnode;
    }
    else{
        newnode->prev=prev;
        newnode->next=prev->next;
        prev->next=newnode;
        if(newnode->next)
            newnode->next->prev=newnode;
        else
            *tail=newnode;
    }
    return 1;
}
int del(struct ll **head, struct ll **tail, int data){
    struct ll *temp=NULL, *prev=NULL;
    if(!search(*head, data, &prev))
        return 0;
    if(!prev){
        temp=*head;
        *head=(*head)->next;
        if(!(*head))
            *tail=NULL;
        else
            (*head)->prev=NULL;
    }
    else{
        temp=prev->next;
        prev->next=temp->next;
        if(temp->next)
            temp->next->prev=prev;
        else
            *tail=prev;
    }
    free(temp);
    return 1;
}
void traverse1(struct ll *head){ //from head
    struct ll *temp= head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
void traverse2(struct ll *tail){ //from tail
    struct ll *temp= tail;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->prev;
    }
}


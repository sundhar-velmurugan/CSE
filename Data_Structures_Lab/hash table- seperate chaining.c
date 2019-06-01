#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
int search(struct node *head, int data, struct node **prev){
    struct node *temp=head;
    *prev=NULL;
    while(temp && data!=temp->data){
        *prev=temp;
        temp=temp->next;
    }
    if(!temp)
        return 0;
    if(temp->data==data)
        return 1;
    else
        return 0;
}
int insert(struct node **head, int data){
    struct node *newnode=NULL, *prev=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(!newnode)
        return 0;
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
    return 1;
}
int deletenode(struct node **head, int data){
    struct node *temp=NULL, *prev=NULL;
    if(!search(*head, data, &prev))
        return 0;
    if(!prev){
        temp=*head;
        *head=(*head)->next;
    }else{
        temp=prev->next;
        prev->next=prev->next->next;
    }
    free(temp);
    return 1;
}
int main(){
    int item, h, flag;
    struct node *prev=NULL, *arr[11];
    scanf("%d", item);
    h=item%11;
    flag=insert(&arr[h], item);
    if(flag==1)
        printf("Success");
    getch();
    return 1;
}

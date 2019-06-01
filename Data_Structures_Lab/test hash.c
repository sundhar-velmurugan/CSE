#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define size 11
struct node
 {
  int data;
  struct node *next;
 };
struct hash{
struct node *arr[size];
};

//linkedlist
int searchnode(struct node *head,int data)
 {
  struct node *temp=head;
  while(temp&&data>temp->data)
   {
     temp=temp->next;
   }
  if(!temp)
  return 0;
  else if(data==temp->data)
  return 1;
  else
  return 0;
 }
int searchdel(struct node *head,int data,struct node **prev)
 {  struct node *temp=head;
  *prev=NULL;

  while(temp&&data>temp->data)
   {
    *prev=temp;
     temp=temp->next;
   }
  if(!temp)
  return 0;
  else if(data==temp->data)
  return 1;
  else
  return 0;
 }

int insertnode(struct node **head,int data)
 {
  struct node *newnode=NULL;
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL)
  return 0;

  newnode->data=data;
    newnode->next=*head;
    *head=newnode;
   return 1;
}

int traverse(struct node *head)
 {
  struct node *temp=head;
  while(temp)
   {
    printf("%d",temp->data);
    temp=temp->next;
   }
   return 1;
 }

 int deletenode(struct node **head,int data){
 struct node *prev=NULL;
 struct node *temp=NULL;
 if(!searchdel(*head,data,&prev)){
 return 0;
 }else{
 if(prev==NULL){
 temp=*head;
 *head=(*head)->next;
 }
 else{
 temp=prev->next;
 prev->next=temp->next;
 }free(temp);
 return 1;
 }
}
//hash table
int hashfn(int data,int ts)
{
return (data%ts);
}

int insert(int data,struct hash **h)
{
 return (insertnode(&((*h)->arr[hashfn(data,size)]),data));
 }

int search(int data,struct hash *h)
{
 return (searchnode((h->arr[hashfn(data,size)]),data));
 }

int deletehash(int data,struct hash **h)
 {
  return (deletenode(&((*h)->arr[hashfn(data,size)]),data));
 }


 int main()
 {
   struct hash *h=NULL;
   int i,ch,data,flag;

  //clrscr();

  do
    {
     i=0;
     printf("\nmenu:\n1)insertion\n2)deletion\n3)to search \npress any other key to exit :");
     scanf("%d",&ch);
     switch(ch)
      {
       case 1:
       printf("\nenter data to be inserted :");
       scanf("%d",&data);
       //clrscr();
       insert(data,&h);
       break;
       case 2:
       flag=0;
       printf("\nenter data to be deleted :");
       scanf("%d",&data);
       //clrscr();
       flag=deletehash(data,&h);
       if(flag==0)
       printf("\nthe data is not found");
       else
       printf("\nthe data is deleted");
       break;
       case 3:
       flag=0;
       printf("\nenter data to be searched :");
       scanf("%d",&data);
       //clrscr();
       flag=search(data,h);
       if(flag==1)
       printf("\nthe data is present");
       else
       printf("\nthe data is not found");
       break;

       default :
       i=1;
       }
      }while(i==0);
      getch();
      return 1;
}


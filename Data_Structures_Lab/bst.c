#include<stdlib.h>
struct tree{
    int data;
    struct tree *right, *left;
};

int small_i(struct tree *root, int *data){
    if(!root)
        return 0;
    struct tree *temp=root;
    while(temp->left){
        temp=temp->left;
    }
    *data=temp->data;
    return 1;
}
int small_r(struct tree *root, int *data){
    if(!root)
        return 0;
    if(root->left)
        return (small_r(root->left, data));
    else
        *data=root->data;
    return 1;
}
int large_i(struct tree *root, int *data){
    if (!root)
        return 0;
    struct tree *temp=root;
    while(temp->right)
        temp=temp->right;
    *data=temp->data;
    return 1;
}
int large_r(struct tree *root, int *data){
    if (!root)
        return 0;
    if(root->right)
        return (large_r(root->right, data));
    else
        *data=root->data;
    return 1;
}
int  search_i(struct tree *root, int data){
    if(!root)
        return 0;
    struct tree *temp=root;
    while(temp){
        if(temp->data>data)
            temp=temp->right;
        else if(temp->data<data)
            temp=temp->left;
        else
            return 1;
    }
    return 0;
}
int search_r(struct tree *root, int data){
    if(!root)
        return 0;
    if(root->data==data)
        return 1;
    else if(root->data>data)
        return (search_r(root->right, data));
    else
        return (search_r(root->left, data));
}
int insert(struct tree **root, int data){
    struct tree *newnode;
    if(!(*root)){
        newnode=(struct tree *)malloc(sizeof(struct tree));
        newnode->left=newnode->right=NULL;
        newnode->data=data;
        *root=newnode;
    }
    else if((*root)->data<data)
        return (insert(&((*root)->right),data));
    else if ((*root)->data>data)
        return (insert(&((*root)->left), data));
    else
        return 0;
}
int del(struct tree **root, int data){
    if(!(*root))
        return 0;
    else if((*root)->data>data)
        return (del(&((*root)->left), data));
    else if((*root)->data<data)
        return (del(&((*root)->right), data));
    else{
        struct tree *temp=*root;
        if(!((*root)->right)){
            *root=(*root)->left;
            free(temp);
            return 1;
        }
        else if (!((*root)->left)){
            *root=(*root)->right;
            free(temp);
            return 1;
        }
        else{
            righttree=(*root)->right;
            int small;
            small_i(rightree, &small);
            return (del((&righttree), small));
        }
    }
    return 1;
}

int preI(struct tree *root){
    struct tree *temp=NULL;
    struct stack s=NULL;
    if(!root)
        return 0;
    push(s, root);
    while(!empty(s)){
        pop(s,&temp);
        printf("%d ", temp->data);
        if(root->right)
            push(s, root->right);
        if(root->left)
            push(s, root->left);
    }
    return 1;
}
int pre(struct tree *root){
    if (!root)
        return 0;
    printf("%d ", root->data;)
    pre(root->left);
    pre(root->right);
    return 1;
}
int post(struct tree *root){
    if (!root)
        return 0;
    post(root->left);
    post(root->right);
    printf("%d ", root->data;)
    return 1;
}
int in(struct tree *root){
    if (!root)
        return 0;
    in(root->left);
    printf("%d ", root->data;)
    in(root->right);
    return 1;
}

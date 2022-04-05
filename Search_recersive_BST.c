#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};
 
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inOrder(struct Node *root)
{
    if(root!=NULL)
    {
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev =NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL&& root->data<=prev->data)
        {
            return 0;
        }
        prev=root;
        return(isBST(root->right));
    }
    else
    return 1;
}
struct Node *search(struct Node *root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    return search(root->right,key);
}

int main(){
    struct Node *p=createNode(5);
    struct Node *p1=createNode(3);
    struct Node *p2=createNode(6);
    struct Node *p3=createNode(1);
    struct Node *p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    printf("\n");
    if(isBST(p))
    {
        printf("This tree is BST\n");
    }
    else
    printf("This tree is not BST\n");
    struct Node *n=search(p,5);
    if(n!=NULL)
    {
    printf("%d found in the tree\n",n->data);
    }
    else
    printf("Element not Found\n");
    return 0;
}
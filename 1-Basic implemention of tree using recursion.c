//BASIC IMPLEMENTATION OF TREE 

#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *left,*right;
}node;

node *create()
{
    node *newnode;
    int x;
    newnode=(node*)malloc(sizeof(node));
    printf("ENTER VALUE (-1 FOR NO NODES) : ");
    scanf("%d",&x);
    if(x==-1)                                         //BASE CONDITION
    {
        return 0;
    }
    else
    {
        newnode->data=x;
        printf("Enter the left child %d :",x);
        newnode->left=create();                                 //RECURSION
        printf("Enter the right child of tree %d :",x);
        newnode->right=create();           //RECURSION
        return newnode;
    }
}
int main()
{
    node *root=0;
    root=create();
    return 0;
}

//IMPLEMENTATION OF BINARY SEARCH TREE 
#include<stdio.h>
#include<malloc.h>

typedef struct tree
{
    int data;
    struct tree *left,*right;
}tree;

tree *create(int val)       //for root (first element)
{
    tree *newtree;
    newtree=(tree*)malloc(sizeof(tree));
    if(newtree==NULL)
    {
        printf("MEMORY NOT ALLOCATED ...\n");
    }
    else
    {
        newtree->data=val;
        newtree->left=NULL;
        newtree->right=NULL;
    }
    return newtree;                      //for every child consider as root
}

void insert(tree *root,tree *newval)            //newval = new element insert by user
{
    if(newval->data < root->data)
    {
        if(root->left==NULL)
        {
            root->left=newval;
        }
        else
        {
            insert(root->left,newval);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=newval;
        }
        else
        {
            insert(root->right,newval);
        }
    }
}

void inorder(tree *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    tree *root=NULL,*newval;
    int ch,n;
    do
    {
        printf("1-Insert \n2-Inorder \n3-exit \n");
        printf("Enter the choice :: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the data : ");
            scanf("%d",&n);
            newval=create(n);            //for creating the first element in tree assign to NEWVAL
            if(root==NULL)
            {
                root=newval;
            }
            else
            insert(root,newval);
            break;
            case 2:
            if(root==NULL)
            {
                printf("TREE IS EMPTY...");
            }
            else
            {
                printf("TREE IS :: \n");
                inorder(root);
            }
            break;
            case 3:
            printf("EXITING.....!!!!");
            break;
            default:printf("INVALID CHOICE ....!!!");
            break;
        }
    }while(ch!=0);
    return 0;
}

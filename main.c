#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data);
struct Node *insertNode (struct Node *node, int data);
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);



int main()
{
    struct Node *root = NULL;
    struct Node *ptr;
    int n,i,node;

    printf("Enter number of nodes:");
    scanf("%d",&n);

    printf("Insert Node 1:");
    scanf("%d",&node);
    root=insertNode(root,node);

    for(i=1;i<n;i++)
    {
        printf("Insert Node %d:",i+1);
        scanf("%d",&node);
        insertNode(root,node);
    }

    printf("\nInorder Traversing:\n");
    inorder(root);

    printf("Preorder Traversing:\n");
    preorder(root);

    printf("Postorder Traversing:\n");
    postorder(root);




    return 0;
}
struct Node *createNode(int data)
{
    struct Node *ptr;

    ptr = (struct Node*)malloc(sizeof(struct Node));

    if(ptr)
    {
        ptr->Data=data;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    return ptr;
};
struct Node *insertNode (struct Node *node, int data)
{
    if (node == NULL)
        node = createNode(data);

    else
    {
        if (data < node->Data)
            node->left=insertNode(node->left,data);
        else
            node->right=insertNode(node->right,data);
    }
    return node;

};
void inorder(struct Node* root)
{

    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->Data);
        inorder(root->right);
    }
}
void preorder(struct Node* root)
{

    if (root != NULL) {
        printf("%d \n", root->Data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root)
{

    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->Data);
    }
}


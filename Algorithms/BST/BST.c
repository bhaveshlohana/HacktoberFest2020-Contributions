//implementation of Binary Search Tree in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b);

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} BST;

BST *createNode(int x)
{
    BST *temp = malloc(sizeof *temp);
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

BST *insertNode(BST *root, int x)
{
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insertNode(root->left, x);
    else if (x > root->data)
        root->right = insertNode(root->right, x);

    return root;
}

void inorder(BST *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

bool searchBST(BST *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    else if (x < root->data)
        return searchBST(root->left, x);
    else
        return searchBST(root->right, x);
}

int heightBST(BST *root)
{
    if (root == NULL)
        return 0;
    else
        return max(heightBST(root->left), heightBST(root->right)) + 1;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxElement(BST *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return -1;
    }
    else if (root->right == NULL)
        return root->data;
    return maxElement(root->right);
}

int main(int argc, char const *argv[])
{
    /* code */
    BST *root = NULL;
    root = insertNode(root, 8);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 10);
    insertNode(root, 14);
    insertNode(root, 4);
    inorder(root);
    int max = maxElement(root);
    printf("height of tree is %d\n", heightBST(root));
    printf("\nThe maximum element is %d\n", max);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct bin
{
    int data;
    struct bin *left;
    struct bin *right;
};
struct bin *root = NULL;
void insert();
void inorder(struct bin *root);
void perorder(struct bin *root);
void postorder(struct bin *root);
struct bin *delete (struct bin *root, int);
struct bin*findmin(struct bin *temp);
int main()
{
    int ch, c;
    do
    {
        printf("\n\n---- STACK----\n\tMenu ");
        printf(" \n1.insert\n2.inorder\n3.perorder\n4.postorder\n5.delete\n");
        printf("Enter your choice(1-5):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            perorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter the key value:");
            scanf("%d", &c);
            delete (root, c);
            break;
        default:
            printf("Wrong Choice!!");
        }

    } while (ch <= 5);
}
void insert()
{
    int ele;
    struct bin *binele, *curr, *parent;
    binele = (struct bin *)malloc(sizeof(struct bin));
    printf("Enter the element you want to enter :");
    scanf("%d", &ele);
    binele->left = NULL;
    binele->right = NULL;
    binele->data = ele;
    curr = root;
    parent = NULL;
    if (root == NULL)
    {
        root = binele;
    }
    else
    {
        while (curr != NULL)
        {
            parent = curr;
            if (binele->data < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (binele->data < parent->data)
        {
            parent->left = binele;
        }
        else
        {
            parent->right = binele;
        }
    }
}

void inorder(struct bin *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void perorder(struct bin *root)
{
    if (root)
    {
        printf("%d\t", root->data);
        perorder(root->left);
        perorder(root->right);
    }
}
struct bin *findmin(struct bin *root)

{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
void postorder(struct bin *root)
{
    if (root)
    {
        perorder(root->left);
        perorder(root->right);
        printf("%d\t", root->data);
    }
}

struct bin *delete (struct bin *root, int key)
{
    struct bin *p;
    if (root==NULL)
    {
        printf("Tree is empty");
        printf("%d",root->data);
        return 0;
    }
    else if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {

            if (root->left == NULL)
                p = root->right;
            else
                p = root->left;

            free(root);
            return NULL;
        }
        else
        {
            p = findmin(root->right);
            root->data = p->data;
            root->right = delete (root, p->data);
        }
    }
    return root;
}

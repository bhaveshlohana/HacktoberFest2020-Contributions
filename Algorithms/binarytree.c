#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \t", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
 if(root!=NULL)
 {
  printf(" %d \t",root->key);
  preorder(root->left);
  preorder(root->right);
 }
}

void postorder(struct node *root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf(" %d \t",root->key);
 }
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key > node->key)
        node->left  = insert(node->left, key);
    else if (key < node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    struct node *root = NULL;
    int ch,k;
    printf("1 Insertion \n");
    printf("2 Inorder \n");
    printf("3 Preorder \n");
    printf("4 Postorder \n");
    printf("5 - Exit\n");

    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            {
             printf("enter the element t\t\t");
             scanf("%d",&k);
             root = insert(root, k);
             break;
            }

        case 2:{printf("inorder traversed  \n");
            inorder(root);
            break;}
        case 3:{printf("preorder traversed  \n");
            preorder(root);
            break;}
        case 4:{printf("postorder  \n");
            postorder(root);
            break;}

        case 5:
            exit(0);

        default :printf("Wrong choice, Please enter correct choice  ");
        }
    }
    return 0;
}

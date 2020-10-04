#include<iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void load(Node *root, int arr[], int &i);

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
        if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
void tree(int arr[], int n);

int main()
{



    int n ;
    cout<<"Enter no of elements: \n";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: \n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }



    tree(arr, n);
       cout<<"Sorted array is:\n";

        for (int i=0; i<n; i++)
       cout << arr[i] << " ";

    return 0;
}

void load(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        load(root->left, arr, i);
        arr[i++] = root->key;
        load(root->right, arr, i);
    }
}
void tree(int arr[], int n)
{
    struct Node *root = NULL;
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        root = insert(root, arr[i]);
    int i = 0;
    load(root, arr, i);
}

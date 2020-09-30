//Implementation Of AVL TREE

#include<iostream>
using namespace std;

class AVLnode
{
    public:
    int key;
    AVLnode *lc, *rc;
    int bal;
    AVLnode(int data)
    {
        key = data;
        lc = rc = NULL;
        bal = 0;
    }
};

int height(AVLnode *node)
{
    if(node == NULL)
    return 0;
    int l = height(node->lc);
    int r = height(node->rc);
    if(l > r)
    return l + 1;
    else
    return r + 1;
}

int getBalance(AVLnode *node)
{
    int lh = height(node->lc);
    int rh = height(node->rc);
    return lh - rh;
}

struct stk
{
    AVLnode *nodetemp;
    struct stk *next;
};

struct stk* push_stk(AVLnode *node, struct stk *top)
{
    if(top == NULL)
    {
        struct stk *top = new struct stk;
        top->nodetemp = node;
        top->next = NULL;
        return top;
    }
    struct stk *temp = new struct stk;
    temp->nodetemp = node;
    temp->next = top;
    return temp;
}

void rightRotate(AVLnode *a)
{
    AVLnode *newroot = new AVLnode(a->key);
    newroot->lc = a->lc;
    newroot->rc = a->rc->lc;
    a->key = a->rc->key;
    a->rc = a->rc->rc;
    a->lc = newroot;
}

void leftRotate(AVLnode *a)
{
    AVLnode *newroot = new AVLnode(a->key);
    newroot->rc = a->rc;
    newroot->lc - a->lc->rc;
    a->key = a->lc->key;
    a->lc = a->lc->lc;
    a->rc = newroot;
}

void leftRightRotate(AVLnode *a)
{
  rightRotate(a->lc);
  leftRotate(a);
}

void rightLeftRotate(AVLnode *a) {
  leftRotate(a -> rc);
  rightRotate(a);
}

AVLnode *insertAVL(AVLnode *root, int data)
{
    if(root == NULL)
    {
        root = new AVLnode(data);
        return root;
    }
    else
    {
        struct stk *top = NULL;
        AVLnode *prt, *trav = root;
        while(trav != NULL)
        {
            prt = trav;
            top = push_stk(prt, top);
            if(trav->key > data)
            trav = trav -> lc;
            else
            trav = trav -> rc;
        }
        if(prt->key > data)
        {
            prt->lc = new AVLnode(data);
        }
        else
        {
            prt->rc = new AVLnode(data);
        }
        while(top != NULL)
        {
            AVLnode *temp = top->nodetemp;
            temp->bal = getBalance(temp);
            if(temp->bal == 2 || temp->bal == -2)
            {
                if(temp->key > data && temp->lc->key > data)
                leftRotate(temp);
                else if(temp->key < data && temp->rc->key < data)
                rightRotate(temp);
                else if(temp->key < data && temp->rc->key > data)
                {
                    rightLeftRotate(temp);
                }
                else
                {
                    leftRightRotate(temp);
                }
                break;
            }
            top = top->next;
        }
        while(top!=NULL)
        {
            top->nodetemp->bal = getBalance(top->nodetemp);
            top = top->next;
        }
        return root;
    }
}

void deleteAVL(AVLnode *root, int data) {
  AVLnode *parent = NULL, *trav = root;
  struct stk *top = NULL;
  while (trav != NULL && trav -> key != data) {
    parent = trav;
    top = push_stk(parent, top);
    if (trav -> key > data) {
      trav = trav -> lc;
    } else if (trav -> key < data) {
      trav = trav -> rc;
    }
  }
  if (trav == NULL) {
    cout << "No element present \n";
  } else {
    cout << "Element found \n";
    int isLeft = 0;
    if (parent != NULL) {
      cout << "Parent of element" << parent -> key << '\n';
      if (parent -> key > trav -> key) {
        isLeft = 1;
        cout << "Element present in Left" << '\n';
      } else {
        cout << "Element present in right" << '\n';
      }
    }
    if (trav -> lc != NULL && trav -> rc != NULL) {
      cout << "Element has both childs" << '\n';
      AVLnode *temp = trav -> lc;
      while(temp -> rc != NULL) {
        temp = temp -> rc;
      }
      cout << "Rightmost of left subtree: " << temp -> key << '\n';
      trav -> key = temp -> key;
      while(top != NULL) {
        top =  top -> next;
      }
      deleteAVL(trav -> lc, temp -> key);
    } else if (trav -> lc != NULL || trav -> rc != NULL) {
      AVLnode *temp = trav;
      if (isLeft) {
        if (trav -> lc == NULL) {
          cout << "Element has right child" << '\n';
          parent -> lc = trav -> rc;
        } else {
          cout << "Element has left child" << '\n';
          parent -> lc = trav -> lc;
        }
      } else {
        if (trav -> lc == NULL) {
          cout << "Element has right child" << '\n';
          parent -> rc = trav -> rc;
        } else {
          cout << "Element has left child" << '\n';
          parent -> rc = trav -> lc;
        }
      }
      delete(temp);
    }
    else {
      cout << "Element has no child" << '\n';
      AVLnode *temp = trav;
      if (isLeft) {
        parent -> lc = NULL;
      } else {
        parent -> rc = NULL;
      }
      delete(temp);
      cout << "Element deleted" << '\n';
    }
  }
  while (top != NULL) {
    cout << "Unbalnce check \n";
    AVLnode *temp = top -> nodetemp;
    temp -> bal = getBalance(temp);
    cout << temp -> key << " BAL = " << temp -> bal << '\n';
    if (temp -> bal == 2 || temp -> bal == -2) {
      AVLnode *temp2 = top -> next -> nodetemp;
      cout << "Parent of Parent: " << temp2 -> key << '\n';
      if (temp2 -> key > temp -> key) {
        cout << "parent present left of parent's parent \n";
        if (temp2 -> rc -> bal == 1 || temp2 -> rc -> bal == 0) {
          leftRotate(temp);
        } else {
          leftRightRotate(temp);
        }
      } else {
        cout << "parent present left of parent's parent \n";
        if (temp2 -> lc -> bal == 0 || temp2 -> lc -> bal == -1) {
          rightRotate(temp);
        } else {
          rightLeftRotate(temp);
        }
      }
      break ;
    }
    top = top -> next;
  }
  while(top!=NULL) {
      top->nodetemp->bal = getBalance(top->nodetemp);
      top = top->next;
  }
}

void preOrder(AVLnode *root)
{
    if(root == NULL)
    return;
    cout<<"\n"<<root->key<<" "<<root->bal;
    preOrder(root->lc);
    preOrder(root->rc);
}

void inOrder(AVLnode *root)
{
    if(root == NULL)
    return;
    inOrder(root->lc);
    cout<<"\n"<<root->key<<" "<<root->bal;
    inOrder(root->rc);
}

int main()
{
    AVLnode *root = NULL;
    int i = 0;
    int arr[] = {10, 20, 30, 25, 15, 5, 40, 50, 60, 55, 45, 35};
    while(i < 12)
    {
        root = insertAVL(root, arr[i]);
        i++;
    }
    cout<<"Preorder:\n";
    preOrder(root);
    cout<<"\nInorder:\n";
    inOrder(root);
    cout << "Delete 30 \n";
    deleteAVL(root, 30);
    cout<<"Preorder:\n";
    preOrder(root);
    cout<<"\nInorder:\n";
    inOrder(root);
    return 0;
}

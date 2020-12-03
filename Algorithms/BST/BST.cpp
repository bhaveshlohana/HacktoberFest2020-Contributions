#include <iostream>

using namespace std;

struct BinarySearchTree
{
    struct node
    {
        int data;
        node *p,*left,*right;
        void init(int d=0, node *parent=NULL, node *l =NULL, node *r=NULL)
        {
            data=d;
            p=parent;
            right=r;
            left=l;
            return;
        }
    };
    node *root=NULL;
    void Inorder_Tree_Walk(node *x)
    {
        if(x!=NULL)
        {
            Inorder_Tree_Walk(x->left);
            cout<<"Data: "<<x->data;
            if(x->left)
                cout<<"  Left Data: "<<x->left->data;
            if(x->right)
                cout<<"  Right Data: "<<x->right->data;
            if(x->p)
                cout<<"  p Data: "<<x->p->data;
            cout<<endl;
            Inorder_Tree_Walk(x->right);

        }
        return;
    }
    node* Tree_Search(node *x, int k)
    {
        if(x==NULL || k == x->data)
            return x;
        else
        {
            if(k<x->data)
                return(Tree_Search(x->left,k));
            else
            {
                return Tree_Search(x->right,k);
            }
            
        }
        
    }

    node* Tree_Minimum(node* x)
    {
        node* ptr=x;
        while(ptr->left) ptr=ptr->left;
        return ptr;
    }

    node* Tree_Maximum(node* x)
    {
        node* ptr=x;
        while(ptr->right) ptr=ptr->right;
        return ptr;
    }

    node* Tree_Successor(node *x)
    {
        if(x->right)
        {
            return Tree_Minimum(x->right);
        }
        node *y= x->p;
        while(y !=NULL && x==y->right)
        {
            x=y;
            y=y->p;
        }
        return y;
    }

    node* Tree_Predecessor(node *x)
    {
        if(x->left)
        {
            return Tree_Maximum(x->left);
        }
        node *y= x->p;
        while(y !=NULL && x==y->left)
        {
            x=y;
            y=y->p;
        }
        return y;
    }

    void Tree_Insert(int v)
    {
        node *z=new node,*x,*y;
        z->init(v);
        
        x=root;
        y=NULL;
        while(x!=NULL)
        {
            y=x;
            if(v<x->data)
                x=x->left;
            else
            {
                x=x->right;
            }
            
        }
        z->p=y;
        if(y == NULL)
        {
            root=z;
            return;
        }
        else
        {
            if(v<y->data)
            {
                y->left=z;
            }
            else
            {
                y->right=z;
            }
            
        }
        
        return;
    }
    void Transplant(node *x, node *y)
    {
        if(x->p==NULL)
        {
            root=y;
            root->p=NULL;
            return;
        }
        if(x->p->left==x)
        {
            x->p->left=y;
            //y->p=x->p;
        }
        else
        {
            x->p->right=y;
        }
        if(y)
        {
            y->p=x->p;
        }
        return;        
    }

    void Tree_Delete(node *z)
    {
        if(z==NULL)
            return;
        if(z->left==NULL)
        {
            Transplant(z,z->right);
            
            
            cout<<z->data<<" deleted successfully\n";
            delete(z);
            return;
        }
        else if(z->right==NULL)
        {
            Transplant(z,z->left);
            
            
            cout<<z->data<<" deleted successfully\n";
            delete(z);
            if(z==NULL)
            return;
        }
        else
        {
            node *y=Tree_Minimum(z->right);
            if(y->p!=z)
            {
                Transplant(y,y->right);
                y->right=z->right;
                y->right->p=y;
            }
            Transplant(z,y);
            y->left=z->left;
            y->left->p=y;
            cout<<z->data<<" deleted successfully\n";
            delete(z);
            return;
        }
        
    }
};

int main()
{
    int i=0;
    BinarySearchTree btree;
    while(i+1)
    {
        int x;
        cout<<"To Exit  press -1 ,to input press 1, to see tree root input 3\n";
        cin>>i;
        if(i==1){
        cout<<"input new element:";
        cin>>x;
        btree.Tree_Insert(x);
        }
        else if(i==2)
        {
            cout<<"which element you want to delete:";
            cin>>x;
            btree.Tree_Delete(btree.Tree_Search(btree.root,x));
        }
        else if(i==3)
        {
            cout<<"Tree root"<<btree.root->data<<endl;
        }
        cout<<"Inorder Tree Walk:\n";
        btree.Inorder_Tree_Walk(btree.root);
        cout<<endl;
    }
}
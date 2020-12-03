//BST to GST

class solution{

void revorder(node* root, int &sum){


if(root== NULL)
{
return ;}

revorder(root->right,sum);
sum+= root->val;

root->val= sum;

revorder(root->left,sum);

}

node* BSTtoGST(node* root){

int sum=0;

revorder(root,sum);
return root;
}
};
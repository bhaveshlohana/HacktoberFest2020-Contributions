/*
Note -The Height of binary tree with single node is taken as zero.
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

    int height(Node* root) {
        // Write your code here.
        int x,y;
        if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL)
            {
                return 0;
            }
            x=height(root->left);
            y=height(root->right);
            return (x>y?x+1:y+1);
        }
        return 0;
    }

}; 


int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    std::cout << height;

    return 0;
}

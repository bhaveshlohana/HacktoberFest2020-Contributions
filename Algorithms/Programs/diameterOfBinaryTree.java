public class Node {
        int val;
        Node left;
        Node right;
        Node() {}
        Node(int val) { this.val = val; }
        Node(int val, Node left, Node right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
  }

class Solution {
    public int diameterOfBinaryTree(Node root) {
        diameter(root);
        return dia;
    }

    int dia=0;
    public int diameter(Node root){
        if(root==null) 
            return -1;
        int lh=diameter(root.left);
        int rh=diameter(root.right);

        dia=Math.max(dia,lh+rh+2);
        return Math.max(lh,rh)+1;
    }
}

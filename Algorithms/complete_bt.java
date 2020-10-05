
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
 
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        int prev=root.val;
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        q.add(root);
        while(!q.isEmpty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode r=q.remove();
                if(r.left!=null)
                {
                    if(prev==-1)
                    {
                        return false;
                    }
                    q.add(r.left);
                }
                else
                {
                   prev=-1;
                }
                if(r.right!=null)
                {
                    if(prev==-1)
                    {
                        return false;
                    }
                    q.add(r.right);
                }
                else
                {
                   prev=-1;
                }
                
            }
        }
        return true;
    }
}

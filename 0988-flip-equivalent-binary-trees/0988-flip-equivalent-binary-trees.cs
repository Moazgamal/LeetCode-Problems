/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool FlipEquiv(TreeNode root1, TreeNode root2) {
        return fn(root1,root2);
        bool fn(TreeNode root1, TreeNode root2)
    {
        if(root1 ==null && root2  == null)
            return true;
        if((root1 ==null && root2!=null) || (root2==null && root1!=null) || (root1.val != root2.val))
            return false;
        
        bool x1 =(fn(root1.right, root2.right) && fn(root1.left, root2.left));
        if(x1 == true)
            return true;
        bool x2 = (fn(root1.left, root2.right) && fn(root1.right, root2.left));
        return x2;
    }
        
    }
}
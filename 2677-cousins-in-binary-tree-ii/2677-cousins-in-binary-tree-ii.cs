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
    public TreeNode ReplaceValueInTree(TreeNode root) {
        int sum1 = 0; 
        int sum2 =0;
        Queue<Tuple<TreeNode,int>> q = new Queue<Tuple<TreeNode,int>>();
        q.Enqueue(new Tuple<TreeNode,int>(root,0));
        for(int level = 1, sz = q.Count(); q.Count()>0; level++, sz = q.Count())
        {
            while(sz-- > 0)
            {
                Tuple<TreeNode,int>p = new Tuple<TreeNode,int>(q.Peek().Item1,q.Peek().Item2);
                q.Dequeue();
                if(level == 1)
                {
                    p.Item1.val = 0;
                    int x = p.Item1.right !=null ? p.Item1.right.val   :0;
                    int y = p.Item1.left!=null ? p.Item1.left.val  :0;
                    if(p.Item1.right != null)
                        {
                            q.Enqueue(new Tuple<TreeNode,int>(p.Item1.right,y));
                            sum2+=p.Item1.right.val;
                        }
                    if(p.Item1.left != null)
                        {
                            q.Enqueue(new Tuple<TreeNode,int>(p.Item1.left,x));
                            sum2+=p.Item1.left.val;
                        }
                }
                else
                {
                    p.Item1.val = sum1-p.Item1.val-p.Item2;
                    if(p.Item1.right != null)
                    {
                        int x = p.Item1.left != null ? p.Item1.left.val : 0;
                        q.Enqueue(new Tuple<TreeNode,int>(p.Item1.right,x));
                        sum2+=p.Item1.right.val;
                    }
                    if(p.Item1.left != null)
                        {
                            int x = p.Item1.right != null ? p.Item1.right.val : 0;
                            q.Enqueue(new Tuple<TreeNode,int>(p.Item1.left,x) );
                            sum2+=p.Item1.left.val;
                        }
                }
            }
            sum1= sum2;
            sum2=0;
        }return root;
        
    }
}
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
    public long KthLargestLevelSum(TreeNode root, int k) {
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        List<long>sums = new List<long>();
        long sum = 0;
        for(int sz= q.Count(); q.Count()>0; sz = q.Count())
        {
            while(sz-- > 0)
            {
                TreeNode cur = q.Peek();
                q.Dequeue();
                if(cur.left != null)
                    q.Enqueue(cur.left);
                if(cur.right != null)
                    q.Enqueue(cur.right);
                sum+=cur.val;
            }
            sums.Add(sum);
            sum=0;
        }
        if(sums.Count()<k)
            return -1;
        sums.Sort();
        int x = sums.Count();
        return sums[x-k];
        
    }
}
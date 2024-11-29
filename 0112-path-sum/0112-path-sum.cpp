/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool dfs(TreeNode* root, int target, int &sum)
    {
        if(!root->right && !root->left)
        {
            sum += root->val;
            if(sum == target)
                return true;
            sum -= root->val;
            return false;
        }
        sum += root->val;
        if(root->left && dfs(root->left, target, sum))
            return true;
        if(root->right && dfs(root->right, target, sum))
            return true;
        
        sum -= root->val;
        return false;
        
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        int sum = 0 ;
        return dfs(root, targetSum, sum);
        
    }
};
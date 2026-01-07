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
    int MOD = 1e9+7;
    long long ans = 1; 
    int totalSum=0;
    int dfs(TreeNode* &root)
    {
        if(!root)
            return 0; 
        if(!root->right && !root->left)
        {
            return  root->val;
        }
        int r = dfs(root->right);
        int l = dfs(root->left);
        root->val += r + l;
        return root->val;
    }
    void dfs2(TreeNode* &root)
    {
        if(!root)
            return ; 
        if(!root->right && !root->left)
        {
            ans = max(ans, (long long)root->val*(totalSum-root->val));
            return ;
        }
        dfs2(root->right);
        dfs2(root->left);
        ans = max(ans, (long long)root->val*(totalSum-root->val));
    }
public:
    int maxProduct(TreeNode* root) {
       
        totalSum = dfs(root);
        dfs2(root->right);
        dfs2(root->left);
        return ans%MOD; 

        
    }
};
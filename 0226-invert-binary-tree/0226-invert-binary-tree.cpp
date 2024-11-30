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
    void dfs(TreeNode* root)
    {
        if(!root)
            return ;
        TreeNode* lr  = root->left;
        TreeNode* rr = root->right;
        root->left = rr;
        root->right= lr;
        dfs(root->left);
        dfs(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
         dfs(root); return root;
        
    }
};
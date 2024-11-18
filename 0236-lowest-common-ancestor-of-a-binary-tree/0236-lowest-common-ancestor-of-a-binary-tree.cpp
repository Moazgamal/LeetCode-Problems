/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return nullptr;
        if(root== p || root==q)
            return root;
        TreeNode* righta = dfs(root->right, p, q);
        TreeNode* lefta = dfs(root->left, p, q);
        if(righta && lefta)
            return root;
        if(righta)
            return righta;
        return lefta;
        

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p,q);
    }
};
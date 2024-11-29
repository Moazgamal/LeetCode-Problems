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
    int dfs(TreeNode* root, TreeNode* parent)
    {
       if(!root)
            return 0; 
        if(!root->right && !root->left)
        {
            if(parent && parent->left == root)
                return root->val;
            return 0 ;
        }
        return dfs(root->right, root) + dfs(root->left, root);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* parent = nullptr;
        return dfs(root,parent);
        
        
    }
};
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
    TreeNode* LCA(TreeNode* root, TreeNode* &p, TreeNode* &q)
    {
        if(!root)
            return nullptr;
        if(root == p || root == q)
            return root;
        TreeNode* leftSearch = LCA(root->left, p,q);
        TreeNode* rightSearch = LCA(root->right, p, q);
        if(leftSearch && rightSearch)
            return root;
        if(leftSearch)
            return leftSearch;
        return rightSearch;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return LCA(root, p, q);
        
    }
};
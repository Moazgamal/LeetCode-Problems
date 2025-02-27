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
        if(root->val == p->val || root->val == q->val)
            return root;
        if(p->val > root->val && q->val < root->val || (q->val > root->val && p->val < root->val))
            return root;
        if(p->val < root->val && q->val < root->val )
            return LCA(root->left, p, q);
        return LCA(root->right, p, q);
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
        
    }
};
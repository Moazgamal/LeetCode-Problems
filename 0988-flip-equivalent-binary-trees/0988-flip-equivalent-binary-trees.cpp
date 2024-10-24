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
    bool fn(TreeNode* &root1, TreeNode* &root2)
    {
        if(!root1 && !root2)
            return true;
        if((!root1 && root2) || (!root2 && root1) || (root1->val != root2->val))
            return false;
        
        bool x1 =(fn(root1->right, root2->right) && fn(root1->left, root2->left));
        if(x1)
            return true;
        bool x2 = (fn(root1->left, root2->right) && fn(root1->right, root2->left));
        return x2;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        return fn(root1, root2);

        
    }
};
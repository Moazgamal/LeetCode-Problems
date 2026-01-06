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
    int dfs(TreeNode* &root, vector<int>&v, int x,  TreeNode* &parent, TreeNode* curParent, TreeNode* &node)
    {
        if(!root)
            return 0; 
        if(!root->right && !root->left)
        {
            if(root->val == x)
            {
                node = root;
                parent = curParent;
            }
            v[root->val]=1; 
        }
        int r = dfs(root->right, v, x, parent, root, node);
        int l = dfs(root->left, v, x, parent, root, node);
        if(root->val == x)
        {
            node = root;
            parent = curParent;
        }
        return v[root->val] = 1+r+l;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* parent = nullptr;
        TreeNode* node = nullptr;
        TreeNode* curParent = nullptr;
        vector<int>v(101,0);
        int totalNodes = dfs(root, v, x, parent, curParent, node);
        
        if(node->left)
        {
            if(v[node->left->val] > totalNodes - v[node->left->val])
                return true;
        }
        if(node->right)
        {
            if(v[node->right->val] > totalNodes - v[node->right->val])
                return true;
        }
        if(parent)
        {
            if(totalNodes-v[node->val] > v[node->val])
                return true;
        }
        return false;

        
    }
};
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
    void fn(TreeNode* &root, vector<int>&v)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            v.push_back(root->val);
            return; 
        }
        fn(root->left,v);
        v.push_back(root->val);
        fn(root->right,v);
    }
    TreeNode* fn2(int start, int end, vector<int>&v)
    {
        if(start>end)
            return nullptr;
        int mid = ((end-start+1)/2)+start;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = fn2(start, mid-1, v);
        root->right = fn2(mid+1, end, v);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        fn(root,v);
        return fn2(0, v.size()-1, v);
    }
};
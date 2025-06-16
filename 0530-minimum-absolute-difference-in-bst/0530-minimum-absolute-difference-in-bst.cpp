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
    void dfs(TreeNode* root, int &ans, TreeNode* &prev)
    {
        if(!root)
            return ;
        
        dfs(root->left, ans, prev);
        if(prev)
            ans = min(ans, abs(prev->val - root->val));
        prev=root;
        dfs(root->right, ans, prev);
        
        
        
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = nullptr;
        dfs(root, ans, prev);
        return ans;
        
    }
};
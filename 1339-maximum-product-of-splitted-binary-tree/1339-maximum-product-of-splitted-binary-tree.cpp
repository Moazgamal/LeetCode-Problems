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
    int dfs(TreeNode* &root, unordered_map<TreeNode*, long long>&mp)
    {
        if(!root)
            return 0; 
        if(!root->right && !root->left)
        {
            return  mp[root]= root->val;
        }
        int r = dfs(root->right, mp);
        int l = dfs(root->left, mp);
        return mp[root]= root->val + r + l;
    }
public:
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*,long long>mp;
        int totalSum = dfs(root, mp);
        long long ans = 1; 
        for(auto &x: mp)
        {
            if(x.first == root)
                continue;
            ans = max(ans, x.second*(totalSum-x.second));
        }return ans%MOD; 

        
    }
};
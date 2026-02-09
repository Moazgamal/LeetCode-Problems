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
    int dfs(TreeNode* &root, vector<int>&v)
    {
        if(!root)
            return 0; 
        if(!root->right && !root->left)
        {
            v.push_back(root->val);
            return root->val;
        }
        int sumLeft = dfs(root->left, v);
        int sumRight = dfs(root->right, v);
        v.push_back(root->val+sumLeft+sumRight);
        return sumLeft+root->val+sumRight;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>v;
        dfs(root,v);
        unordered_map<int,int>mp;
        for(int i = 0; i< v.size(); i++)
            mp[v[i]]++;
        int maxi = INT_MIN;
        for(auto &x:mp)
            maxi = max(x.second,maxi);
        vector<int>ans;
        for(auto &w: mp)
            if(w.second == maxi)
                ans.push_back(w.first);
        return ans; 
    }
};
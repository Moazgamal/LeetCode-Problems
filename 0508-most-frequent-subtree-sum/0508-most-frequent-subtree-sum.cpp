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
        vector<pair<int,int>>v2;
        for(auto &x:mp)
            v2.push_back({x.second, x.first});
        sort(v2.rbegin(), v2.rend());
        vector<int>ans;
        for(int i = 0; i< v2.size(); )
        {
            int freq = v2[i].first;
            int j = i; 
            while(j<v2.size() && v2[j].first == freq)
            {
                ans.push_back(v2[j].second);
                j++;
            }
            break;
        }
        return ans; 
    }
};
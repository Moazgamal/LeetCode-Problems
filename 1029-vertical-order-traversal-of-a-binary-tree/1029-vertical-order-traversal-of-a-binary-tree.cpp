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
    void dfs(TreeNode* root, map<int,vector<pair<int,int>>>&mp,  int r, int c)
    {
        if(!root)
            return ;
        mp[c].push_back({root->val,r});
        if(root->left)
             dfs(root->left, mp, r+1,c-1);
        
        if(root->right)
            dfs(root->right, mp, r+1,c+1);
    }
    struct CompareDescending {
    bool operator()(pair<int,int> a, pair<int,int> b) const {
        if(a.second == b.second)
            return a.first<b.first;
        return a.second<b.second;
    }
};
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,vector<pair<int,int>>>mp;
        int c= 0; 
        int r = 0; 
        dfs(root, mp,r,c);
        vector<vector<int>> res(mp.size());
        int i = 0; 
        for(auto it :mp)
        {
            sort(it.second.begin(), it.second.end(), CompareDescending());
            for(auto it2 : it.second)
            {   
                res[i].push_back(it2.first);
            }
            i++;
        }return res;


        
    }
};
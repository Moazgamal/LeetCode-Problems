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
    void dfs(TreeNode* &root, unordered_map<int,bool>&mp,vector<TreeNode*>&ans, bool parent)
    {
        if(!root)
            return ;
        
        if(mp.count(root->val)==0 && parent==false)
            ans.push_back(root);
        
        if(root->right)
        {
            TreeNode* temp = root->right;
            if(mp.count(root->right->val)>0)
            {
                root->right = nullptr;
                dfs(temp, mp, ans, false);
            }
            else
            {
                if(mp.count(root->val) >0)
                    dfs(temp, mp, ans, false);
                else
                    dfs(temp, mp, ans, true);
            }
        }
        if(root->left)
        {
            TreeNode* temp = root->left;
            if(mp.count(root->left->val)>0)
            {
                root->left = nullptr;
                dfs(temp, mp, ans, false);
            }
            else
            {
                if(mp.count(root->val) >0)
                    dfs(temp, mp, ans, false);
                else
                    dfs(temp, mp, ans, true);
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_map<int,bool>mp; for(auto &x: to_delete) mp[x]=true; bool parent = false;
        dfs(root,mp,ans,parent);return ans;
    }
};
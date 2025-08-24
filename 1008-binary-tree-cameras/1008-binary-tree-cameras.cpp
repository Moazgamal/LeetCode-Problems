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
    int fn(TreeNode* &root, bool prev, vector<vector<int>>&v)
    {
        if(!root)
            return 0; 
        auto &ret = v[root->val][prev];
        if(ret != -1)
            return ret; 
        if(!root->right && !root->left)
        {
            if(prev == 1)
                return ret = 0;
            return ret = 1;
        }
        int ans = INT_MAX;
        int x1 = fn(root->left, 1, v);
        int x2 = fn(root->right, 1, v);
        int x3 = fn(root->right, 0, v);
        int x4 = fn(root->left, 0, v);
        ans = min(ans, 1+ x1+x2);
        if(prev)
            ans = min(ans, x3+x4);
        else
        {
            if(root->left)
            {
                ans = min(ans, 1+fn(root->left->left, 1, v)+
                fn(root->left->right, 1, v)+ x3);
            }
            if(root->right)
            {
                ans = min(ans, 1+fn(root->right->left, 1, v)+
                fn(root->right->right, 1, v)+ x4);
            }
        }
        return ret = ans; 
    }
    void dfs(TreeNode* &root, int &cnt)
    {
        if(!root)
            return ; 
        dfs(root->left, cnt);
        dfs(root->right, cnt);
        root->val = cnt++;
    }
public:
    int minCameraCover(TreeNode* root) {
        int cnt = 0; 
        dfs(root, cnt);
        vector<vector<int>>v(cnt+1, vector<int>(2, -1));
        return fn(root, 0, v);
        
    }
};
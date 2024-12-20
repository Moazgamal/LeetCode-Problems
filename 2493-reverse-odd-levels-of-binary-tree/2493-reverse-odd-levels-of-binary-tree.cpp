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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*>v;
        for(int level = 0, sz = q.size(); !q.empty(); sz = q.size(), level++)
        {
            while(sz--)
            {
                TreeNode* cur = q.front(); q.pop();
                if(level%2!=0 )
                    v.push_back(cur);
                if(cur->left)
                    q.push(cur->left);
                
                if(cur->right)
                    q.push(cur->right);
            }
            for(int i = 0; i< v.size()/2; i++)
            {
                swap(v[i]->val, v[v.size()-i-1]->val);
            }
            v.clear();
           
        }return root;
        
    }
};
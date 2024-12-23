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
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        int ans  =0; 
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(v.size() == 1)
            {
                v.clear(); continue;
            }
            else
            {
                vector<int> x = v;
                unordered_map<int,int>mp;
                for(int i = 0; i< v.size(); i++)
                {
                    mp[v[i]]=i;
                }
                sort(x.begin(), x.end());
                for(int i = 0; i< v.size(); i++)
                {
                    if(x[i] != v[i])
                    {
                        ans++;
                        int idx = mp[x[i]];
                        int val = v[i];
                        swap(v[i], v[idx]);
                        mp[x[i]]= i;
                        mp[val] = idx;
                    }   
                }
            }
            v.clear();
        }return ans;
        
    }
};
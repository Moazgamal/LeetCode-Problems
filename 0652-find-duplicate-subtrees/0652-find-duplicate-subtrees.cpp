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
    string dfs(TreeNode* root, unordered_map<string, bool>&mp1, unordered_map<string,bool>&mp2, vector<TreeNode*>&ans)
    {
        if(!root->left && !root->right)
        {
            string s =(to_string(root->val));
            s.push_back(' ');
            if(mp1.count(s)!=0)
            {
                if(mp2.count(s) == 0)
                    ans.push_back(root);
                mp2[s] = true;
            }
            mp1[s] = true;
            return s; 
        }
        string s1 = ""; string s2 = "";
        if(root->left)
            s1 = dfs(root->left, mp1, mp2, ans);
        if(root->right)
            s2 = dfs(root->right, mp1, mp2, ans);
        string ss = (to_string(root->val) +" "+ s1 + " " + s2+" ");
        

        if(mp1.count(ss)!=0)
        {
            if(mp2.count(ss) == 0)
                ans.push_back(root);
            mp2[ss] = true;
        }
        mp1[ss] = true;
        return ss;        
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        unordered_map<string, bool>mp1;
        unordered_map<string, bool>mp2;
        vector<TreeNode*>ans;
        string acc = "";
        dfs(root, mp1, mp2, ans);
        return ans; 
        
    }
};
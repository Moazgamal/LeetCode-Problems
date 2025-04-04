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
    int h(TreeNode* root)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 0 ;
        int h1 = 0; 
        int h2 = 0; 
        if(root->right)
            h1 = 1+h(root->right);
        if(root->left)
            h2 = 1+h(root->left);
        return max(h1, h2);
    }
    TreeNode* lca(TreeNode* root, unordered_set<int>&st)
    {
        if(!root)
            return nullptr;
        if(st.find(root->val) != st.end())
            return root;
        TreeNode* t1 = lca(root->left, st);
        TreeNode* t2 = lca(root->right, st);
        if(t1 && t2)
            return root;
        if(t1)
            return t1;
       if(t2)
        return t2;
        return nullptr;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = h(root);
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<int>st;
        for(int level = 0,sz = q.size(); !q.empty(); level++,sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                if(level == height)
                {
                    st.insert(cur->val);
                    cout<<cur->val<<"\n";
                }
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return lca(root, st);

        
    }
};
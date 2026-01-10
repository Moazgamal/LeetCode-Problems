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
    // void dfs(TreeNode* &root, vector<int>&p, TreeNode* curParent)
    // {
    //     if(!root)
    //         return ; 
    //     p[root->val] = curParent;
    //     dfs(root->left, p, root);
    //     dfs(root->right, p, root);
    // }
    pair<int,TreeNode*> fn(TreeNode* &root)
    {
        if(!root)
            return {0, nullptr};

        if(!root->right && !root->left)
            return {1, root};

        auto c1 = fn(root->right);
        auto c2 = fn(root->left);

        if(c1.second == nullptr)
            return {1+c2.first, c2.second};

        if(c2.second == nullptr)
            return {1+c1.first, c1.second};

        if(c1.first > c2.first)
            return {1+c1.first, c1.second};
        else if(c1.first < c2.first)
            return {1+c2.first, c2.second};

        return {1+c1.first, root};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return fn(root).second;
    }
};
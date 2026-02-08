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
    pair<int,bool> fn(TreeNode* &root)
    {
        if(!root)
            return {0,true};
        if(!root->left && !root->right)
            return {1,true}; 
        auto heightLeft = fn(root->left);
        auto heightRight = fn(root->right);
        if(heightLeft.second == false || heightRight.second == false)
            return {1,false};
        if(abs(heightLeft.first-heightRight.first)>1)
            return {1, false};
        return {1+max(heightLeft.first, heightRight.first), true};
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return fn(root).second;
    }
};
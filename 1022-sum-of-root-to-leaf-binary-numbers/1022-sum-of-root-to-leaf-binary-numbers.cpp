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
    void fn(TreeNode* &root, int &totalSum, int &curNumber)
    {
        if(!root->left && !root->right)
        {
            if(root->val == 1)
                curNumber = (curNumber<<1)+1;
            else
                curNumber = (curNumber<<1);

            totalSum += curNumber;
            curNumber = (curNumber>>1);
            return;
        }
        if(root->val == 1)
            curNumber = (curNumber<<1)+1;
        else
            curNumber = (curNumber<<1);
        if(root->left)
            fn(root->left, totalSum, curNumber);
        if(root->right)
            fn(root->right, totalSum, curNumber);
        curNumber = (curNumber>>1);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int totalSum = 0; int curNumber = 0; 
        fn(root, totalSum, curNumber);
        return totalSum;
    }
};
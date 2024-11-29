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
    pair<int,int> Diameter(TreeNode* root)
    {
        if(!root)
            return {0,0};
        if(!root->right && !root->left)
            return {0,0};
        auto p1 = Diameter(root->left);
        auto p2 = Diameter(root->right);
        
       if(root->left)
            p1.first++;
        if(root->right)
            p2.first++;

        int height = max(p1.first, p2.first);
        return {max(p1.first,p2.first), max((p1.first+p2.first),max(p1.second,p2.second))};
    
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        return Diameter(root).second;
        
    }
};
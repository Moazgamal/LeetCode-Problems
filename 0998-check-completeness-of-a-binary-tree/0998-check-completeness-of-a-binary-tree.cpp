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
    int calcHeight(TreeNode* root)
    {
        if(!root)
            return 0; 
        int rightHeight = 1+calcHeight(root->right);
        int leftHeight = 1+calcHeight(root->left);
        return max(rightHeight, leftHeight);
    }
public:
    bool isCompleteTree(TreeNode* root) {

        int height = calcHeight(root);
        queue<TreeNode*> q; q.push(root);
        bool s = false;
        for(int level = 1, sz = q.size(); !q.empty(); sz = q.size(), level++)
        {
            while(sz--)
            {
                TreeNode* cur = q.front(); q.pop();
                if(level < height-1)
                {
                    if(!cur->left || !cur->right)
                        return false;
                    q.push(cur->left); q.push(cur->right);
                }
                else if(level == height-1)
                {
                    if(s == false)
                    {
                        if(!cur->right && !cur->left)
                            s =true;
                        else if(cur->right && !cur->left)
                            return false;
                        else if(cur->left && !cur->right)
                            s=true;
                        
                    }
                    else
                    {
                        if(cur->right || cur->left)
                            return false;
                    }
                }
            }
        }return true;
        
    }
};
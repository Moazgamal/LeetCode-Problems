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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<int> curLevelNodes;
        queue<TreeNode*> q; q.push(root);
        bool leftToRight = true;
        vector<vector<int>> result;
        result.push_back({root->val});
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                TreeNode* cur = q.front(); q.pop();
                if(cur->left)
                {
                    q.push(cur->left); curLevelNodes.push_back(cur->left->val);
                }
                if(cur->right)
                {
                    q.push(cur->right); curLevelNodes.push_back(cur->right->val);
                }
            }
            if(!q.empty())
            {   leftToRight = !leftToRight;
                if(!leftToRight)
                    reverse(curLevelNodes.begin(), curLevelNodes.end());
                result.push_back(curLevelNodes);
                curLevelNodes.clear();
            }
        }
        return result;
        
    }
};
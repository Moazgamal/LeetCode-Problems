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
    int maxLevelSum(TreeNode* root) {

        // BFS
        queue<TreeNode*>q;
        q.push(root);
        int ans = INT_MIN;
        int level = 1; 
        int ansLevel = 0; 
        while(!q.empty())
        {
            int sz = q.size();
            int sum = 0; 
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                sum += cur->val;
                if(cur->right)
                    q.push(cur->right);
                if(cur->left)
                    q.push(cur->left);
            }
            if(sum > ans)
            {
                ansLevel = level;
                ans = sum;
            }
            level++;
        }return ansLevel; 
    }
};
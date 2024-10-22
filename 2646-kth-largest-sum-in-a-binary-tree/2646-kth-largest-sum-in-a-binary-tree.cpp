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
    long long kthLargestLevelSum(TreeNode* root, int k) {


        queue<TreeNode*> q;
        q.push(root);
        vector<long long>sums;
        for(int level =1, sz= q.size(); !q.empty(); sz = q.size(), level++)
        {
            long long sum = 0;
            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                sum+=cur->val;
            }
            sums.push_back(sum);
        }
        if(sums.size()<k)
            return -1;
        sort(sums.rbegin(), sums.rend());
        return sums[k-1];
        
    }
};
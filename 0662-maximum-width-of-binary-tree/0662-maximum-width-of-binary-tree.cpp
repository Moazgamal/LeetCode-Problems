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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right)
            return 1;
        queue<TreeNode*>q;
        q.push(root);
        long long cnt = 0;
        int ans =1;
        root->val = cnt;
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            long long prev =-1;
            long long prev2 = -1;
           
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                    if(prev2!=-1)
                        {
                            cnt = cnt+ (cur->val - prev2-1)*2;
                        }
               if(cur->left)
                {
                    q.push(cur->left);
                    cur->left->val = ++cnt;
                }
                else
                    cnt++;
                if(cur->right)
                {
                    q.push(cur->right);
                    
                    cur->right->val = ++cnt;
                }
                else
                    cnt++;
                if(prev == -1)
                {
                    prev = cur->val;
                    prev2 = cur->val;
                }
                else
                {
                    prev2 = cur->val;
                    ans = max(ans, (int)(cur->val-prev+1));
                }
                
            }
             cnt=0;
        }
        return ans;
    }
};
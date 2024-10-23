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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int sum1 = 0; 
        int sum2 =0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        for(int level = 1, sz = q.size(); !q.empty(); level++, sz = q.size())
        {
            while(sz--)
            {
                pair<TreeNode*,int>p =  q.front();
                q.pop();
                if(level == 1)
                {
                    p.first->val = 0;
                    if(p.first->right)
                        q.push({p.first->right,0});
                    if(p.first->left)
                        q.push({p.first->left,0});
                    continue;
                }
                else if(level == 2)
                {
                    p.first->val = 0; 
                    if(p.first->right)
                    {
                        int x = p.first->left ? p.first->left->val : 0;
                        q.push({p.first->right,x});
                        sum2+=p.first->right->val;
                    }
                    if(p.first->left)
                        {
                            int x = p.first->right ? p.first->right->val : 0;
                            q.push({p.first->left,x} );
                            sum2+=p.first->left->val;
                        }
                }
                else
                {
                    p.first->val = abs(sum1-p.first->val-p.second);
                    if(p.first->right)
                    {
                        int x = p.first->left ? p.first->left->val : 0;
                        q.push({p.first->right,x});
                        sum2+=p.first->right->val;
                    }
                    if(p.first->left)
                        {
                            int x = p.first->right ? p.first->right->val : 0;
                            q.push({p.first->left,x} );
                            sum2+=p.first->left->val;
                        }
                }
            }
            sum1= sum2;
            sum2=0;
        }return root;
    }
};
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
    TreeNode* fn(vector<int>&pre, vector<int>&post, int idx1, int idx2, int end)
    {
        if(idx1 == end)
            return new TreeNode(pre[idx1]);
        if(idx1 > end)
            return nullptr;
        TreeNode* root = new TreeNode(pre[idx1]);
        int leftval = pre[idx1+1];
        int rightval = post[idx2-1];
        if(leftval == rightval)
        {
            root->left = new TreeNode(leftval);
        }
        int j = idx1+1;
        for(int i = idx1+1; i<=end; i++)
        {
            if(pre[i] == rightval)
            {
                j=i;break;
            }
        }
        int k = idx2-1;
        for(int i = idx2-1; i>= 0; i--)
        {
            if(post[i] == leftval)
            {
                k= i; break;
            }
        }
        root->left = fn(pre, post, idx1+1, k, j-1);
        root->right = fn(pre, post, j,idx2-1,end);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        return fn(preorder,postorder,0,postorder.size()-1,postorder.size()-1);
    }
};
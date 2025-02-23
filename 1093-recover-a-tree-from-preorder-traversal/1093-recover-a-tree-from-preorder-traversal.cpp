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
    void fn(TreeNode* &root, int start , int end, string &traversal,int d)
    {
        if(start >= end)
            return ;
        int idx1 = -1;
        int idx2 = -1;
        int cnt = 0 ; 
        for(int i = start; i <= end; i++)
        {
            if(traversal[i] == '-')
                cnt++;
            else
            {
                if(cnt == d+1)
                {
                    if(idx1 == -1)
                        idx1 = i;
                    else
                    {
                        idx2 = i;
                        break;
                    }
                }
                cnt = 0 ; 
            }
        }
        if(idx1 == -1)
            return ;
        if(idx2 == -1)
        {
            string s = "";
            int j = idx1;
            while(j<traversal.size() && traversal[j] != '-')
            {
                s.push_back(traversal[j]);
                j++;
            }
            int val = stoi(s);
            root->left = new TreeNode(val);
            fn(root->left, j,end,traversal, d+1);
        }
        else
        {
             string s = "";
            int j = idx1;
            while(j<traversal.size() && traversal[j] != '-')
            {
                s.push_back(traversal[j]);
                j++;
            }
            int val = stoi(s);
            root->left = new TreeNode(val);
            fn(root->left, j, idx2-d-1,traversal,d+1);

            s.clear();
            j = idx2;
            while(j<traversal.size() && traversal[j] != '-')
            {
                s.push_back(traversal[j]);
                j++;
            }
            val = stoi(s);
            root->right = new TreeNode(val);
            fn(root->right, j, end, traversal, d+1);
        }
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        string s = "";
            int j = 0;
            while(j<traversal.size() && traversal[j] != '-')
            {
                s.push_back(traversal[j]);
                j++;
            }
            int val = stoi(s);
        TreeNode* root = new TreeNode(val);
        fn(root,j,traversal.size()-1, traversal,0 );
        return root;
    }   
};
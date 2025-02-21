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
class FindElements {
public:
unordered_set<int> st;
    FindElements(TreeNode* root) {
        stack<TreeNode*> Stack;
        root->val = 0;
        Stack.push(root);
        st.insert(0);
        while(!Stack.empty())
        {
            TreeNode* cur = Stack.top();
            Stack.pop();
            if(cur->right)
            {
                cur->right->val = cur->val*2+2;
                st.insert(cur->right->val);
                Stack.push(cur->right);
            }
            if(cur->left)
            {
                cur->left->val = cur->val*2+1;
                st.insert(cur->left->val);
                Stack.push(cur->left);
            }
        }
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
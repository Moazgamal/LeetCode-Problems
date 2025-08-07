/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        stack<TreeNode*>st; string ans = "";
        st.push(root);
        while(!st.empty())
        {
            auto cur = st.top();
            ans+=(to_string(cur->val));
            ans.push_back(' ');
            st.pop();
            if(cur->right)
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
        }
        return ans; 
    }

    TreeNode* build(vector<int>&v, int start, int end)
    {
        if(start > end)
            return nullptr;
        if(start == end)
        {
            return new TreeNode(v[start]);
        }
        TreeNode* root = new TreeNode(v[start]);
        int i = start+1;
        for(; i<= end; i++)
        {
            if(v[i]> v[start])
            {
                break;
            }
        }
        root->left = build(v, start+1, i-1);
        root->right = build(v, i, end);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if((int)data.size() == 0)
            return nullptr;
        vector<int> v; 
        for(int i = 0; i< data.size(); )
        {
            int j = i;
            string s = "";
            while(j< data.size() && data[j] != ' ')
            {
                s.push_back(data[j]);
                j++;
            }
            v.push_back(stoi(s));
            i = j+1;
        }
        TreeNode* root = build(v, 0, v.size()-1);
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
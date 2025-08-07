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
        queue<TreeNode*>q;
        string ans = "";
        q.push(root); 
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            if(cur == nullptr)
            {
                ans.push_back('n'); 
                ans.push_back(' ');
                continue;
            }
            
            ans+=(to_string(cur->val)+"");
            ans.push_back(' ');
            if(cur->left)
                q.push(cur->left);
            else
                q.push(nullptr);
            if(cur->right)
                q.push(cur->right);
            else
                q.push(nullptr);
        }
        return ans; 
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        int cnt = 1;
        vector<int> v;
        TreeNode* root = nullptr;
        int k = 0; 
        while(k< (int)data.size())
        {
            string cur = ""; 
            if(data[k] == 'n')
            {
                v.push_back(-2000); k+=2; continue;
            }
            while(k< data.size() && data[k] != ' ')
            {
                cur.push_back(data[k]); k++;
            }
            v.push_back(stoi(cur));
            k++;
        }
        root = new TreeNode(v[0]);
        vector<TreeNode*>vv(v.size());
        int i = 0; 
        if(i+cnt< data.size() && v[cnt+i] != -2000)
        {
            root->left = new TreeNode(v[cnt+i]);
            vv[cnt+i] = root->left;
        }
        if(i+cnt+1 < data.size() && v[cnt+i+1] != -2000)
        {
            root->right = new TreeNode(v[cnt+i+1]);
            vv[cnt+i+1]= root->right;
        }
        cnt++; i++;
        while( i< (int)v.size() )
        {
            if(v[i] == -2000)
            {
                cnt--; 
                i++; continue;
            }
            else
            {
                if(i+cnt< v.size() && v[cnt+i] != -2000)
                {
                    vv[i]->left = new TreeNode(v[cnt+i]);
                    vv[cnt+i]= vv[i]->left;
                }
                if(i+cnt+1 < v.size() && v[cnt+i+1] != -2000)
                {
                    vv[i]->right = new TreeNode(v[cnt+i+1]);
                    vv[i+cnt+1] = vv[i]->right;
                }
                cnt++; i++;
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
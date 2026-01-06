/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        unordered_map<Node*,bool>vis;
        stack<Node*>q;
        q.push(root);
        vector<int>ans;

        while(!q.empty())
        {
            auto cur = q.top();
            q.pop();
            if(!cur)
                continue;
            if(vis[cur])
            {
                ans.push_back(cur->val);
                continue;
            }
            if(cur->children.size()==0)
            {
                ans.push_back(cur->val);
                continue;
            }
            if(!vis[cur])
            {
                q.push(cur);
                vis[cur]=true;
            }
            for(int i = cur->children.size()-1; i >= 0; i--)
            {
                if(!cur->children[i])
                    continue;
                q.push(cur->children[i]);
            }
        }
        return ans; 
        
    }
};
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
    vector<int> preorder(Node* root) {

        stack<Node*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty())
        {
            auto cur = q.top(); q.pop();
            if(!cur)
                continue;
            ans.push_back(cur->val);
            for(int i = cur->children.size()-1; i>=0 ; i--)
            {
                if(!cur->children[i])
                    continue;
                auto newNode = cur->children[i];
                q.push(newNode);
                cout<<newNode->val<<" ";
            }
            cout<<"\n";

        }return ans; 
        
    }
};
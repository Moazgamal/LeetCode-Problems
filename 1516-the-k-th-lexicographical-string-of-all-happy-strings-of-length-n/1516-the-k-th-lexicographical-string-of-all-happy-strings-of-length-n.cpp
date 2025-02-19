class Solution {
    void Backtracking(int idx, int &n ,string &acc, vector<string> &v)
    {
        if(idx == n)
        {
            v.push_back(acc); return ;
        }
        if(idx == 0)
        {
            acc.push_back('a'); Backtracking(idx+1, n, acc, v); acc.pop_back();
            acc.push_back('b'); Backtracking(idx+1, n, acc, v); acc.pop_back();
            acc.push_back('c'); Backtracking(idx+1, n, acc, v); acc.pop_back();
        }
        else
        {
            if(acc[idx-1] == 'a')
            {
                acc.push_back('b'); Backtracking(idx+1, n, acc, v); acc.pop_back();
                acc.push_back('c'); Backtracking(idx+1, n, acc, v); acc.pop_back();
            }
            else if(acc[idx-1] == 'b')
            {
                acc.push_back('a'); Backtracking(idx+1, n, acc, v); acc.pop_back();
                acc.push_back('c'); Backtracking(idx+1, n, acc, v); acc.pop_back();
            }
            else
            {
                acc.push_back('a'); Backtracking(idx+1, n, acc, v); acc.pop_back();
                acc.push_back('b'); Backtracking(idx+1, n, acc, v); acc.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> v;
        string acc ="";
        Backtracking(0, n,acc, v);
        if(v.size() < k )
            return "";
        return v[k-1];
        
    }
};
class Solution {
    void Backtracking(int idx, int &n ,string &acc, vector<string> &v, int &cnt,int&k )
    {
        if(idx == n)
        {
            if(++cnt == k)
                v.push_back(acc);
            return ;
        }
        if(v.size() ==1 )
            return ;
        if(idx == 0)
        {
            acc.push_back('a'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
            acc.push_back('b'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
            acc.push_back('c'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
        }
        else
        {
            if(acc[idx-1] == 'a')
            {
                acc.push_back('b'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
                acc.push_back('c'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
            }
            else if(acc[idx-1] == 'b')
            {
                acc.push_back('a'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
                acc.push_back('c'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
            }
            else
            {
                acc.push_back('a'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
                acc.push_back('b'); Backtracking(idx+1, n, acc, v,cnt,k); acc.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> v;
        string acc ="";
        int cnt = 0; 
        Backtracking(0, n,acc, v,cnt,k);
        if(v.size() ==0 )
            return "";
        return v[0];
        
    }
};
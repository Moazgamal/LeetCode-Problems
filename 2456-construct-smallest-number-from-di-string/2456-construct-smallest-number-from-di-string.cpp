class Solution {
    bool backtracking(int idx, int num, vector<bool>&v, string &res, string &pattern)
    {
        if(idx > pattern.size())
            return true;
        
        for(int i = 1; i<=9; i++)
        {
            if(v[i]==true || pattern[idx] == 'D' && i==1)
                continue;
            if(idx == 0)
            {
                res.push_back(i+'0'); v[i]=true;
                if(backtracking(idx+1, 1,v,res,pattern))
                    return true;
                res.pop_back(); v[i]=false;
            }
            else
            {
                if(pattern[idx-1] == 'I')
                {
                    if(i > res[res.size()-1]-'0')
                    {
                        res.push_back(i+'0'); v[i] = true;
                        if(backtracking(idx+1, 1,v,res,pattern))
                            return true;
                        res.pop_back(); v[i] = false;
                    }
                }
                else
                {
                    if(i< res[res.size()-1]-'0')
                    {
                        v[i] = true; res.push_back(i+'0');
                        if(backtracking(idx+1, 1,v,res,pattern))
                            return true;
                        res.pop_back(); v[i] = false;
                    }
                }
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        
        vector<bool> v(10,false);
        string res ="";
        backtracking(0, 1, v, res, pattern);
        return res;
        
    }
};
class Solution {
    bool backtracking(int idx, int num, vector<bool>&v, vector<int> &res, string &pattern)
    {
        if(idx > pattern.size())
        {
            return true;
        }
        for(int i = 1; i<=9; i++)
        {
            if(v[i]==true)
                continue;
            if(pattern[idx] == 'D' && i==1)
                continue;
            if(idx == 0)
            {
                res.push_back(i);
                v[i]=true;
                if(backtracking(idx+1, 1,v,res,pattern))
                    return true;
                res.pop_back();
                v[i]=false;
            }
            else
            {
                if(pattern[idx-1] == 'I')
                {
                    if(i > res[res.size()-1])
                    {
                        res.push_back(i);
                        v[i] = true;
                        if(backtracking(idx+1, 1,v,res,pattern))
                            return true;
                        res.pop_back();
                        v[i] = false;
                    }
                }
                else
                {
                    if(i< res[res.size()-1])
                    {
                        v[i] = true;
                        res.push_back(i);
                        if(backtracking(idx+1, 1,v,res,pattern))
                            return true;
                        res.pop_back();
                        v[i] = false;
                    }
                }
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        
        vector<bool> v(10,false);
        vector<int> res;
        backtracking(0, 1, v, res, pattern);
        string x = "";
        for(int i = 0; i< res.size(); i++)
        {
            x.push_back(res[i]+'0');
        }
        return x;
        
    }
};
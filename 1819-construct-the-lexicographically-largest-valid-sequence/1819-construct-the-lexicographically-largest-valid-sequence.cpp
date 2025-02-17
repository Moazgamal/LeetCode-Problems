class Solution {
    bool fn(int idx, int start, int n , vector<int> &v , vector<int> &res,unordered_map<int,int>&mp)
    {
        if(idx == v.size())
        {
            bool x = true;
            for(int i = 0; i< v.size(); i++)
            {
                if(v[i] == -1)
                {
                    x=false; break;
                }
            }
            if(x==true)
            {
                for(int i =0; i< v.size(); i++)
                {
                    if(res[i] > v[i])
                    {
                        break;
                    }
                    else
                    {
                        res = v; break;
                    }
                    
                }
            }
            return x;
        }
        if(v[idx] != -1)
                return fn(idx+1, start, n, v, res, mp);
        for(int i = n; i>=1; i--)
        {
            if(mp.count(i)==0)
            {

                if(idx+ i>=v.size() && i != 1)
                    continue ;
                if(v[idx] != -1)
                    return fn(idx+1, start, n, v, res, mp);
                if(i != 1 && v[idx+i] != -1)
                    continue;
                v[idx]= i;
                if(i!= 1)
                    v[idx+i] = i;
                mp[i]++;
                if(fn(idx+1, start, n, v, res, mp))
                    return true;
                v[idx]= -1;
                if(i!= 1)
                    v[idx+i]=-1;
                mp.erase(i);
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        int sz = (n-1)*2 +1;
        vector<int> result(sz, -1);
        vector<int> v(sz, -1);
        unordered_map<int,int>mp;
        fn(0,1,n ,v, result,mp);
        return result;
    }
};
class Solution {
    vector<int> fn(string &pat)
    {
        vector<int> longestk(pat.size(),0);
        for(int i =1,k=0; i<pat.size(); i++)
        {
            while(k>0 && pat[k] != pat[i])
            {
                k= longestk[k-1];
            }
            if(pat[k] == pat[i])
            {
                longestk[i]=++k;
            }
            else
                longestk[i]=k;
        }return longestk;
    }
    bool fn2(string &str, string &pat, vector<int>&longestk)
    {
        for(int i =0, k=0; i< str.size(); i++)
        {
            while(k>0 && pat[k] != str[i])
            {
                k = longestk[k-1];
            }
            if(pat[k] == str[i])
                k++;
            if(k==pat.size())
                return true;
        }return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int cnt = 1;
        string x = a;
        while(a.size()<b.size())
        {
            a+=x;
            cnt++;
        }
        vector<int>longestk = fn(b);
        if(fn2(a,b,longestk) == true)
            return cnt;
        else if(a.size() >= b.size())
        {
            a+=x;
            cout<<a<<" ";
            if(fn2(a,b,longestk) == true)
                return cnt+1;
            else
                return -1;
            
        }return -1;
        
        
        
    }
};
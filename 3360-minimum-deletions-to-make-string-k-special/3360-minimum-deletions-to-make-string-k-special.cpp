class Solution {
    int fn(int start, int end, vector<int>&f , vector<vector<int>>&dp, int &k)
    {
        if(start == end)
            return 0; 
        if(f[end]-f[start]<=k)
            return 0 ;
        auto &ret = dp[start][end] ;
        if(ret !=-1)
            return ret;
        int c1 = f[start] + fn(start+1, end, f, dp, k);
        int diff = f[end]-f[start];
        diff-=k;
        int c2 = diff + fn(start, end-1,f, dp, k);
        return ret = min(c1, c2);
    }
public:
    int minimumDeletions(string word, int k) {


        vector<int> freqs(26,0);
        for(int i = 0; i< word.size(); i++)
        {
            freqs[word[i]-'a']++;
        }
        vector<int> f;
        for(int i = 0; i< freqs.size(); i++)
        {
            if(freqs[i]>0)
            {
                f.push_back(freqs[i]);
            }
        }
        sort(f.begin(), f.end());
        vector<vector<int>>dp(f.size()+1, vector<int>(f.size()+1, -1));
        return fn(0, f.size()-1, f, dp, k); 
        
    }
};
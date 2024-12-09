class Solution {
    int ans = INT_MAX;
    void BackTracking(int idx, int k , vector<int> &s, int totaltime, int x)
    {
        if(idx== s.size())
        {
            ans = min(ans, totaltime);
            return ; 
        }
        int t = totaltime;
        for(int i = idx; i< s.size(); i++)
        {
            swap(s[i], s[idx]);
            int needtime = ceil(s[idx]/(double)x);
           
           
            BackTracking(idx+1, k, s, totaltime+needtime, x+k);
            swap(s[i], s[idx]);
            
        }
    }
public:
    int findMinimumTime(vector<int>& strength, int K) {
        BackTracking(0, K, strength, 1, 1);
        return ans-1;
        

    }
}; 
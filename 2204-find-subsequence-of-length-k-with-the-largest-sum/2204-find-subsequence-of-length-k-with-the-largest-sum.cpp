class Solution {
    static bool compare(pair<int,int>a, pair<int,int>b)
    {
        return a.second > b.second;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        for(int i = 0; i< nums.size(); i++)
        {
            v.push_back({nums[i],i});
        }
       
        sort(v.begin(), v.end());
        vector<pair<int,int>>ans;
        for(int i = (int)v.size()-1; i>= ((int)v.size()-k);i-- )
        {
            ans.push_back(v[i]);
        }
        vector<int>x;
        vector<int> res;
        for(int i = 0; i< ans.size(); i++)
        {
            x.push_back(ans[i].second);
        }
        sort(x.begin(), x.end());
        for(int i = 0; i< x.size(); i++)
        {
            res.push_back(nums[x[i]]);
        }
        return res;
        
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        unordered_map<int,unordered_set<int>>mp2;
        int i = 0;  int sz = nums.size(); 
        while(i < sz)
            mp[nums[i++]]++;
        i = 0; 
        while(i< sz)
            mp2[mp[nums[i]]].insert(nums[i++]);
        vector<int>x;
        for(auto &j: mp2)
            x.push_back(j.first);
        sort(x.rbegin(), x.rend());
        i= 0; 
        vector<int>ans;
        while(i<x.size() && k>0)
        {
            for(auto &u: mp2[x[i]])
            {
                ans.push_back(u);
                k--;
                if(k ==0)
                    break;
            }
            i++;
        }
        return ans;
        
        
    }
};
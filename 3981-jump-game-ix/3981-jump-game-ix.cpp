class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int maxi = -1;
        int maxidx = 0;
        vector<pair<int,int>>v;
        vector<int>ans(nums.size());
        vector<pair<int,int>>vv(nums.size());
        for(int i = 0; i< nums.size(); i++)
        {
            v.push_back({nums[i], i});
            if(maxi <= nums[i])
            {
                maxi = nums[i]; maxidx = i; 
            }
            vv[i] = {maxi, maxidx};
        }
        sort(v.rbegin(), v.rend());
        int j = 0; 
        vector<int>farLeast(nums.size(),-1);
        for(int i = nums.size()-1; i >= 0; i--)
        {
            int val = nums[i];
            while(j < v.size() && val < v[j].first)
            {
                farLeast[v[j].second]= i;
                j++;
            }
            if(j<v.size() && val == v[j].first)
            {
                j++;
            }
            if(j >= v.size())
                break;
        }
        for(int i = 0; i< nums.size(); i++)
        {
            ans[i] = max(ans[i], vv[i].first);
            
            int far = farLeast[i];
            if(far != -1)
                ans[i] = max(ans[i], vv[far].first);
            int idx = -1; int idx2 = -1; 
            if(far == -1)
            {
                idx = vv[i].second;
                idx2 = farLeast[idx];
            }
            else
            {
                idx = i;
                idx2 = farLeast[i];
            }
           
            while(idx2 != -1 && idx2 > idx)
            {
                ans[i] = max(ans[i], vv[idx2].first);
                idx = vv[idx2].second;
                if(idx != -1 && farLeast[idx] == idx2)
                    break;
                idx2 = farLeast[idx];
            }
            
        }
        return ans; 
        
        
    }
};
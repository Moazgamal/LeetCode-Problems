class Solution {
    void fn(int start, int end ,
    vector<int>&nums, vector<pair<long long,long long>>&g,
    vector<long long>&  prefixVector)
    {
        int s = start; int e = end;
        long long maxSum1 = LLONG_MIN;
        long long sum = nums[e]+nums[e-1]; 
        maxSum1 = max(maxSum1, sum);
        g[start].first = e-1;
        e-=2;
        while(e >= s)
        {
            sum += nums[e];
            if(sum > maxSum1)
                g[start].first = e;
            maxSum1 = max(maxSum1, sum);
            e--;
        }
        s = start; e = end;
        maxSum1 = LLONG_MIN;
        sum = nums[s]+nums[s+1]; 
        maxSum1 = max(maxSum1, sum); 
        g[start].second = s+1;
        s+=2;
        while(s <= e)
        {
            sum += nums[s];
            
            if(sum > maxSum1)
                g[start].second = s;
            maxSum1 = max(maxSum1, sum);
            s++;
        }
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans = LLONG_MIN;
        vector<long long>prefixVector(nums.size(), 0);
        prefixVector[0] = nums[0];

        for(int i = 1; i< nums.size(); i++)
            prefixVector[i] = nums[i]+prefixVector[i-1];

        vector<pair<int, int>>v;
        for(int i = 0; i< nums.size()-1;)
        {
            int j = i;
            if(nums[j+1] > nums[i])
            {
                while(j < nums.size()-1 && nums[j+1] > nums[j])
                    j++;
                v.push_back({i, 1});
                i = j; 
            }
            else if(nums[j+1] < nums[i])
            {
                while(j < nums.size()-1 && nums[j+1] < nums[j])
                    j++;
                v.push_back({i, -1});
                i = j; 
            }
            else
            {
                while(j < nums.size()-1 && nums[j+1] == nums[j])
                    j++;
                v.push_back({i, 0});
                i = j; 
            }
        }
        vector<pair<long long, long long>>g(nums.size());
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i].second == 1)
            {
                int start = v[i].first;
                int end = nums.size()-1;
                if(i == v.size()-1)
                    end = nums.size()-1;
                else
                    end = v[i+1].first;
                fn(start, end, nums, g, prefixVector);
            }
        }
        for(int i = 0; i< v.size(); i++)
        {
            if(i+2 < v.size())
            {
                if(v[i].second== 1 && v[i+1].second == -1 && 
                v[i+2].second == 1)
                {
                    int start1  = v[i].first;
                    int start2 = v[i+2].first;
                    int s = g[start1].first;
                    int e = g[start2].second;
                    if(s == 0)
                        ans = max(ans, prefixVector[e]);
                    else
                        ans = max(ans, prefixVector[e]-prefixVector[s-1]);
                }
            }
            else
                break;
        }
        return ans; 
    }
};
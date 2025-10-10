class Solution {
    
    void fn(int element, int &sz, unordered_map<int, unordered_set<int>>&mp,
    unordered_map<int,int>&mp2, int cnt, int &ans)
    {
        if(cnt == sz)
        {
            ans++;return ;
        }
        mp2[element]--;
        for(auto x: mp[element])
        {
            if(mp2[x]>0)
                fn(x, sz, mp, mp2, cnt+1, ans);
        }
        mp2[element]++;
    }
public:
    int numSquarefulPerms(vector<int>&  nums) {
        if(nums.size() == 1)
            return 0; 
        
        unordered_map<int,unordered_set<int>>mp;
        unordered_map<int,int>mp2;
        for(int i = 0; i< nums.size(); i++)
        {
            mp2[nums[i]]++;
            for(int j = i+1; j< nums.size(); j++)
            {
                int x = nums[i] + nums[j];
                double u = sqrt(x);
                int n = sqrt(x);
                if(u == n)
                {
                    mp[nums[i]].insert(nums[j]);
                    mp[nums[j]].insert(nums[i]);
                }
            }
        }

        int ans = 0; 
        int cnt = 1; 
        int sz = (int)nums.size();
        for(auto f: mp2)
            fn(f.first, sz, mp, mp2, cnt, ans);

        return ans; 
    }
};
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0; 
        for(int i = 0; i< nums.size(); i++)
            {
                mp[nums[i]] = i;
                sum+= nums[i];
            }
        int ans = INT_MIN;
        for(int i = 0; i< nums.size(); i++)
            {
                int x = sum -nums[i];
                cout<<x<<"\n";
                if(x%2==0)
                {
                    if(mp.count(x/2)>0 && mp[x/2] != i)
                        ans =max(ans, nums[i]);
                }
            }
        return ans;
        
    }
};
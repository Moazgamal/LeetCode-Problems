class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0; 
        unordered_map<int,int>mp;
        int mini = nums[0]-k;
        for(int i = 0; i< nums.size();i++)
            {
                if(mp.count(nums[i]-k) ==0)
                {
                    mp[nums[i]-k]++;
                    cnt++;
                    mini = max(mini, nums[i]-k);
                }
                else
                {
                    int x = max(mini, nums[i]-k);
                    int y = nums[i]+k;
                    if(mp.count(y) >0)
                        continue;
                    while(x <= y)
                        {
                            if(mp.count(x) ==0)
                            {
                                cnt++;
                                mp[x]++;
                                break;
                            }
                            x++;
                            mini = x;
                        }
                }
            }
        return cnt;
        
    }
};
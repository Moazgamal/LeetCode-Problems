class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int,int>mp;
        int evens = 0; int odds = 0; int ans = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==1)
                if(nums[i] %2 == 0)
                    evens++;
                else
                    odds++;
            
            if(evens == odds)
                ans = max(ans, i+1);
            else
            {
                int j = 0;
                while(j<i && odds != evens)
                {
                    mp[nums[j]]--;
                    if(mp[nums[j]]==0)
                        if(nums[j] %2 == 0)
                            evens--;
                        else
                            odds--;
                    j++;
                }
                if(odds == evens)
                    ans = max(ans, i-j+1);
                int k = j;
                j=0;
                while(j<k)
                {
                    mp[nums[j]]++;
                    if(mp[nums[j]] == 1)
                        if(nums[j]%2 == 0)
                            evens++;
                        else
                            odds++;
                    j++;
                }

            }
        }
        return ans; 

        
    }
};
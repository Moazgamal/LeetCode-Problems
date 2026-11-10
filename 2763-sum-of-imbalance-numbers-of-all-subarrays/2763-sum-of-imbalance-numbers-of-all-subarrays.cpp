class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {

        int ans = 0; 
        for(int i = 0; i< nums.size()-1; )
        {
            int len = 0; 
            int j = i;
            unordered_map<int,bool>mp;
            int mini = nums[i];
            int maxi = nums[i];
            int neeDeD = 0; 
            int collecteD = 0; 
            while(j< nums.size() && nums[j]==nums[i])
            {
                len++;
                mp[nums[j]]=true;
                j++;
            }
            while(j< nums.size() && ((nums[j] >=mini && nums[j]<=maxi) ||
            (nums[j] == mini-1) || (nums[j] == maxi+1)))
            {
                mp[nums[j]]=true;
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                j++;
            }
            
            if(j == nums.size())
            {
                i = i + len; continue;
            } 
            
            mp[nums[j]]=true;
            collecteD++;
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            neeDeD = maxi-mini-1;
            if(neeDeD > 0)
                ans += (collecteD*len); 

            j++;

            while(j < nums.size())
            {
                if(nums[j] >=mini && nums[j]<=maxi)
                {
                    if(mp.count(nums[j])>0)
                    {
                        if(neeDeD >0)
                            ans+=(collecteD*len);
                    }
                    else
                    {
                        neeDeD--;
                        mp[nums[j]]=true;
                        if(mp.count(nums[j]-1)>0 && mp.count(nums[j]+1)>0)
                            collecteD--;
                        else if(mp.count(nums[j]-1)==0 && mp.count(nums[j]+1)==0)
                            collecteD++;

                        if(neeDeD>0)
                            ans+=(collecteD*len);
                    }
                }
                else if(nums[j] >maxi)
                {
                    neeDeD += (nums[j]-maxi-1);
                    if(nums[j]>maxi+1)
                        collecteD++;
                    if(neeDeD >0)
                        ans += (collecteD*len);
                    maxi = nums[j];
                    mp[nums[j]]=true;
                }
                else if(nums[j] < mini)
                {
                    neeDeD += (mini-nums[j]-1);
                    if(nums[j]<mini-1)
                        collecteD++;
                    if(neeDeD >0)
                        ans += (collecteD*len);
                    mini = nums[j];
                    mp[nums[j]]=true;
                }
                j++;
            }
            i  = i+len;
        }
        return ans; 
    }
};
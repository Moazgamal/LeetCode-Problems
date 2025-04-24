class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {


        int j = 0; 
        int dis = 0; 
        int ans = 0; 
        
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        for(int i = 0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        dis = mp.size();
        int dis2 = 0; 
        for(int i =0; i< nums.size(); i++)
        {
            if(mp2[nums[i]] ==0)
            {
                dis2++;
                mp2[nums[i]]++;
            }
            else
            {
                mp2[nums[i]]++;
            }

            if(dis2 == dis)
            {
                ans += (nums.size() - i); 
                while(j<=i && dis2 == dis)
                {
                    if(--mp2[nums[j]] ==0)
                    {
                        dis2--;
                    }
                    else
                    {
                        ans += (nums.size() - i);
                    }
                    j++;
                }
            }
           
        }return ans;
        
    }
};
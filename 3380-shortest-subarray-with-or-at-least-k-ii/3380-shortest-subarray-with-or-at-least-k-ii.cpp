class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prefixsum=0;
        int ans = INT_MAX;
        int s = 0;
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[i] >=k)
                return 1;

            for(int j = 0; j<32; j++)
            {
                if( ((1<<j) & nums[i]) >0)
                {
                    if(mp.count(1<<j)==0 || mp[(1<<j)] ==0)
                    {
                        mp[(1<<j)]++;
                        prefixsum+=(1<<j);
                    }
                    else
                        mp[(1<<j)]++;
                }
            }
            if(prefixsum >=k)
            {
                
                if(ans==1) 
                    return 1;
                while(prefixsum>=k && s<=i)
                {
                    ans= min(ans, i-s+1);
                    for(int j = 0; j<32; j++)
                    {
                        if(((1<<j) & nums[s]) >0)
                        {
                            if(mp[(1<<j)]-1==0)
                            {
                                prefixsum-=(1<<j);
                                cout<<"iiiii"<<prefixsum;
                                mp[(1<<j)]--;
                            }
                            else
                                mp[(1<<j)]--;
                        }
                    }
                    s++;
                }
            }
        }
        return ans == INT_MAX ?-1:ans;
        
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int PrefixSum = 0 ;
        int ans = INT_MIN; 
        int posidx=0;
        int negidx=0;
        unordered_map<int,int>mp;
        for(int i =0; i< nums.size();i++)
        {
            PrefixSum+=nums[i];
            ans = max(ans, abs(PrefixSum));
            if(PrefixSum >= 0)
            {
                if(negidx !=0)
                    ans = max(ans, PrefixSum-negidx);
            }
            else
            {
                if(posidx !=0)
                    ans = max(ans, abs(PrefixSum-posidx));
            }
            if( PrefixSum>0 )
            {
                if(posidx != 0)
                {
                    if(posidx<PrefixSum)
                        posidx = PrefixSum;
                }
                else
                    posidx = PrefixSum;
            }
            else
            {
                if(negidx != 0)
                {
                    if(negidx>PrefixSum)
                        negidx = PrefixSum;
                }
                else
                    negidx = PrefixSum;
            }
            
        }
        return ans;
        
    }
};
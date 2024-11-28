class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        vector<int> v (10000*2+1,0);
        for(int i = 0; i< nums.size(); i++)
        {
            v[nums[i]+10000]++;
        }
        for(int i = v.size()-1; i>=0; i--)
        {
            k-= v[i];
            if(k<=0)
            {
                return i - 10000;

            }
        }
        return 0; 

        
    }
};
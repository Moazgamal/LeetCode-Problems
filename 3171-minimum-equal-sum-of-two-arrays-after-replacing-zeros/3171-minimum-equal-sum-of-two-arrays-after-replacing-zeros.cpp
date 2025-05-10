class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        long long ans = 0; 
        long long mini1 = 0; 
        long long maxi1 = mini1;
        long long mini2 = 0; 
        long long maxi2 = mini2;
        for(int i = 0; i< nums1.size(); i++)
        {
            if(nums1[i] == 0)
            {
                mini1 += 1;
                maxi1 = LLONG_MAX;
            }
            else
            {
                mini1 += nums1[i];
            }
        }
        for(int i = 0; i< nums2.size(); i++)
        {
            if(nums2[i] == 0)
            {
                mini2 += 1;
                maxi2 = LLONG_MAX;
            }
            else
            {
                mini2 += nums2[i];
            }
        }
        if(maxi1 != LLONG_MAX)
            maxi1 = mini1;
        if(maxi2 != LLONG_MAX)
            maxi2 = mini2;
        if(mini1 > maxi2 || mini2 > maxi1)
            return -1;
        return max(mini1, mini2);

        
    }
};
class Solution {
   
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int curr = 0;
        for(int i = 0; i< nums2.size(); i++)
        {
            curr ^= nums2[i];
        }
        int ans =0;
        for(int i = 0; i< nums1.size(); i++)
        {
            if(nums2.size()%2==0)
                nums1[i]=0;
            ans ^= (nums1[i]^curr);
           
        }
        return ans;
    }
           
};
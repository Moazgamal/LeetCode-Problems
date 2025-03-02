class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        for(int i = 0,j=0; j<nums2.size() || i< nums1.size(); )
        {
            if(i == nums1.size())
            {
                result.push_back(nums2[j++]);
            }
            else if(j == nums2.size())
            {
                result.push_back(nums1[i++]);
            }
            else if(nums1[i][0] == nums2[j][0])
            {
                result.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++; j++;
            }
            else if(nums1[i][0]<nums2[j][0])
            {
                result.push_back({nums1[i][0],nums1[i][1]});
                i++;
            }
            else
            {
                result.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
        }
        return result;
        
    }
};
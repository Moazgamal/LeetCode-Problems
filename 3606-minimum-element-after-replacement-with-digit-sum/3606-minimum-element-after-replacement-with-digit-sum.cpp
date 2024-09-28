class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for(int i =0; i< nums.size(); i++)
        {
            string s  = to_string(nums[i]);
            int acc=0;
            for(int j=0; j< s.size(); j++)
            {
                acc+= (s[j]-'0');
            }
            ans=min(ans,acc);
        }return ans;
        
    }
};
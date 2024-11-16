class Solution {
    
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> mp1;
        unordered_map<int,int>freq;
        set<int>st;
        for(int i = 0; i< nums.size(); i++)
        {
            mp1[nums[i]-k]++;
            mp1[nums[i]+k+1]--;
            freq[nums[i]]++;
            st.insert(nums[i]-k); st.insert(nums[i]+k+1); st.insert(nums[i]);
        }
        int acc = 0; 
        int ans = 0; 
        for(auto num: st)
        {
            acc += (mp1[num]);
            ans = max(ans, min(acc, freq[num]+numOperations));
        }return ans;
        
    }
};
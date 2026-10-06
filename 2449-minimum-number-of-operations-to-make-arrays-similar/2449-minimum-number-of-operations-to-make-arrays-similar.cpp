class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0; 
        vector<int> EVENS1;
        vector<int> ODDS1;
        vector<int> EVENS2;
        vector<int> ODDS2;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] %2 == 0)
                EVENS1.push_back(nums[i]);
            else
                ODDS1.push_back(nums[i]);
            
            if(target[i] %2 == 0)
                EVENS2.push_back(target[i]);
            else
                ODDS2.push_back(target[i]);
        }

        sort(EVENS1.begin(), EVENS1.end());
        sort(EVENS2.begin(), EVENS2.end());
        sort(ODDS1.begin(), ODDS1.end());
        sort(ODDS2.begin(), ODDS2.end());
        priority_queue<int>v;
        long long sum1 = 0; long long sum2 = 0; 
        for(int i = 0; i < EVENS1.size(); i++)
        {
            int Diff = abs(EVENS1[i] - EVENS2[i]);
            sum1 += (Diff/2);
        }
        for(int i = 0; i< ODDS1.size(); i++)
        {
            int Diff = abs(ODDS1[i] - ODDS2[i]);
            sum2 += (Diff/2);
        }
        ans += min(sum1,sum2);
        int Diff = abs(sum1-sum2);
        ans += (Diff/2);
        return ans; 
    }
};
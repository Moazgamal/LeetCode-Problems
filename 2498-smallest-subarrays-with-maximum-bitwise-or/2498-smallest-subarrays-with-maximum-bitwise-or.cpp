class Solution {
    void BS(int num, vector<vector<int>>&v, int idx)
    {
        int cnt = 0; 
        while(num >0)
        {
            int rem = num % 2;
            if(rem ==1)
            {
                v[cnt].push_back(idx);
            }
            num /= 2;
            cnt++;
        }
    }
    void BS2(int num, vector<bool>&v2)
    {
        int cnt = 0; 
        while(num >0)
        {
            int rem = num % 2;
            if(rem ==1)
            {
                v2[cnt]=true;
            }
            num /= 2;
            cnt++;
        }
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        vector<vector<int>> v(32);

        for(int i = (int)nums.size()-1; i>=0; i--)
        {
            BS(nums[i], v, i);
        }
        vector<int>ans(nums.size());
        for(int i = 0; i< nums.size(); i++)
        {
            vector<bool>v2(32); BS2(nums[i], v2);
            int u = INT_MIN;
            for(int j =0; j< 32; j++)
            {
                if(v2[j])
                    continue;
                if(v[j].size()<1)
                    continue;

                int sz = v[j].size()-1;
                while(sz>=0 && v[j][sz]<= i)
                {
                    v[j].pop_back(); sz--;
                }
                if(sz>=0)
                {
                    u = max(u, v[j][sz]);
                }
            }
            if(u == INT_MIN)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = u-i+1;
            }

        }
        return ans; 
        
    }
};
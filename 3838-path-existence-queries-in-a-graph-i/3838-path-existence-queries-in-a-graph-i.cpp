class Solution {
    
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        
    vector<int> vis(n, 0);
        int cnt = 1; 
        for(int i = 0; i< nums.size(); )
            {
                vis[i] = cnt;
                int j = i+1;
                while(j<nums.size())
                    {
                        if(abs(nums[j-1] - nums[j]) <= maxDiff)
                        {
                            vis[j] = cnt;
                        }
                        else
                        {
                            break;
                        }
                        j++;
                    }
                i= j;
                cnt++;
            }
        
        
        
        vector<bool> result(queries.size(), false);
        for(int i = 0; i< queries.size(); i++)
            {
                if(queries[i][0] == queries[i][1])
                {
                    result[i] = true;
                    continue;
                }
               
                if(vis[queries[i][0]] == vis[queries[i][1]])
                {
                    result[i] = true;
                }
            }
        return result;
        
        
        
    }
};
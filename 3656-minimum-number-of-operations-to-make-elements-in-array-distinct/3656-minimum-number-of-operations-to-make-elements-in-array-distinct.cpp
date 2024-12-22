class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_map<int,int>mp;
        int cnt = 0; 
        for(int i =0; i< nums.size(); i++)
            {
                mp[nums[i]]++;
            }
        int j = 0; 
        for(int i = 0; i< nums.size(); i++)
            {
                while(j< nums.size() && mp[nums[i]]>1)
                {
                    cnt++;
                    int s = j+2;
                    int d = 3;
                    while(j< nums.size() && d-- > 0)
                        {
                            mp[nums[j]]--;
                            j++;
                        }
                    
                    i=max(i,j-1);
                }
            }
        return cnt;
        
        
    }
};
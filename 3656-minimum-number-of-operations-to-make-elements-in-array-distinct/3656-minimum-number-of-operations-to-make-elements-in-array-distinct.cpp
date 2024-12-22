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
                if(mp[nums[i]]>1)
                {
                    cnt++;
                    int s = j+2;
                    while(j< nums.size() && j<=s)
                        {
                            mp[nums[j]]--;
                            j++;
                        }
                    
                    i=j-1;
                }
            }
        return cnt;
        
        
    }
};
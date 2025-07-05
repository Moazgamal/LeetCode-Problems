class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int,int>mp;
        for(int i = 0; i< arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for(auto x: mp)
        {
            if(x.second == x.first)
            {
                ans = max(ans, x.first); 
            }
        }return ans; 
        
    }
};
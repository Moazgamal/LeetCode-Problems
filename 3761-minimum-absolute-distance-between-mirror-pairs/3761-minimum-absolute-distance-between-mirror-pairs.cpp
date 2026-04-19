class Solution {
    string reverseString(string &str)
    {
        string newStr = "";
        for(int i = str.size()-1; i>=0; i--)
            newStr.push_back(str[i]);
        int j = 0; 
        while(j<newStr.size() && newStr[j] == '0')
            j++;
        
        return newStr.substr(j, newStr.size()-j);
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {

        int ans = INT_MAX;
        unordered_map<string, int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            string str  = to_string(nums[i]);
            string rev = reverseString(str);
            if(mp.count(str) != 0)
                ans = min(ans, i-mp[str]);
            mp[rev]= i ; 

        }
        
        if(ans == INT_MAX)
            return -1;
        return ans; 
    }
};
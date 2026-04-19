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
        unordered_map<string, vector<int>>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            string str  = to_string(nums[i]);
            mp[str].push_back(i);
        }
        for(int i = 0; i< nums.size(); i++)
        {
            string str  = to_string(nums[i]);
            string rev = reverseString(str);
            int newInt = stoi(rev);
            string newrev = to_string(newInt);
            if(mp.count(newrev) != 0)
            {
                auto firstG= upper_bound(mp[newrev].begin(), mp[newrev].end(), i);
                if(firstG != mp[newrev].end())
                    ans = min(ans, abs(*firstG-i));
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans; 
    }
};
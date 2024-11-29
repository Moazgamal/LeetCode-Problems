class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i =0; i< arr.size(); i++)
        {
            freq[arr[i]]++;
        }
        unordered_map<int,int> mp;
        for(auto it : freq)
        {
           if(++mp[it.second] >1)
            return false;
        }return true;
    }
};
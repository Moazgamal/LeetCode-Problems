class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {

        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0; i< friends.size(); i++)
        {
            mp[friends[i]]++;
        }
        for(int i = 0; i< order.size(); i++)
        {
            if(mp.count(order[i]) != 0)
                ans.push_back(order[i]);
        }
        return ans; 
        
    }
};
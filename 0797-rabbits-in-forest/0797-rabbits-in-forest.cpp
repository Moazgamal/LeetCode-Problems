class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int ans = 0; 
        for(int i = 0; i< answers.size(); i++)
        {
            mp[answers[i]]++;
        }
        for(auto x: mp)
        {
           float q = ceil((float)x.second/(x.first+1));
           ans+= (x.first+1)*q;
        }
        return ans; 

    }
};
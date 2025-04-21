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
            if(x.first == 0)
            {
                ans+= x.second; continue;
            }
            if(x.second<x.first+1)
            {
                ans+= (x.first+1);
                continue;
            }
           int q = ceil((float)x.second/(x.first+1));
           ans+= (q*(x.first+1));
        
        }
        return ans; 

    }
};
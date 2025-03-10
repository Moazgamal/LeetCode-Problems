class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
       multiset<pair<int,int>> ums;
        for(int i = 0; i< baskets.size(); i++)
        {
            ums.insert({i,baskets[i]});
        }
        int ans = 0; 
        int limit = INT_MAX;
        for(int i = 0; i< fruits.size(); i++)
        {
            
            if(fruits[i]>limit)
            {
                ans++; continue;
            }
            bool s = false;
            for(auto x: ums)
            {
                // cout<<x<<" \n";
                if(x.second >= fruits[i])
                {
                    ums.erase(ums.find(x));
                    s = true;
                    break;
                }
            }
            if(s==false)
            {
                ans++;
                limit = min(limit, fruits[i]);
            }
            

        }return ans;
    }
};
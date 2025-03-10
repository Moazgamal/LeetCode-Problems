class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
       multiset<pair<int,int>> ms;
        for(int i = 0; i< baskets.size(); i++)
        {
            ms.insert({i,baskets[i]});
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
            for(auto x: ms)
            {
                if(x.second >= fruits[i])
                {
                    ms.erase(ms.find(x));
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
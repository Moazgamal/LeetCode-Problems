class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0; 
        for(int i = 0; i< fruits.size(); i++)
            {
                bool s = false;
                for(int j = 0; j< baskets.size(); j++)
                    {
                        if(baskets[j] == -1)
                            continue;
                        if(baskets[j] >= fruits[i])
                        {
                            baskets[j] = -1;
                            s = true;
                            break;
                        }
                    }
                if(s == false)
                    ans++;
            }
        return ans;
    }
};
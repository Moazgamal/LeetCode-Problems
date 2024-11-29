class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        unordered_map<int,int> mp;
        for(int i = 0; i< hand.size(); i++)
        {
            mp[hand[i]]++;
        }

        for(int i = 0; i< hand.size(); i++)
        {
            int g = groupSize;
            if(mp[hand[i]]==0)
                continue;
            mp[hand[i]]--;
            int val = hand[i];
            while(--g)
            {
                if(mp[val+1]==0)
                    return false;
                
                mp[val+1]--;
                val++;
            }
        }return true;
        
    }
};
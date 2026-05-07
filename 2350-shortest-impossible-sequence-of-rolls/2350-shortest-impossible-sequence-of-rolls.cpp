class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {

        vector<int>dp(rolls.size());
        unordered_map<int,int>freq;
        unordered_map<int,int>count;
        unordered_map<int,int>ans;
        count[0]=k;
        int last = 0; 
        int res  = 0;
        for(int i = rolls.size()-1; i >=0; i--)
        {
            freq[rolls[i]]++;
            int newfreq = freq[rolls[i]];
            count[newfreq]++;
            if(newfreq == last+1)
            {
                ans[newfreq]++;
                if(ans[newfreq]==k)
                {
                    last = newfreq;
                    res = newfreq+1;
                }
            }
            else if(newfreq>last+1)
                freq[rolls[i]]--;
        }
        if(res == 0)
            return 1; 
        return res;
    }
};
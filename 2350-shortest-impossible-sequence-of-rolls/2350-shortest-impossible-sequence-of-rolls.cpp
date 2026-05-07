class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int,int>freq;
        unordered_map<int,int>ans;
        int last = 0; 
        int res  = 0;
        for(int i = rolls.size()-1; i >=0; i--)
        {
            freq[rolls[i]]++;
            int newfreq = freq[rolls[i]];
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
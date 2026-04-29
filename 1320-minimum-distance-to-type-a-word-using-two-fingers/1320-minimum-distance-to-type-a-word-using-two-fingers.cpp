class Solution {
    int fn(int idx, int pos1, int pos2, string &word, vector<vector<vector<int>>> &dp)
    {
        if(idx >= word.size())
            return 0; 
        auto &ret = dp[idx][pos1][pos2];
        if(ret != INT_MAX/2)
            return ret; 
        int xFinger1 = pos1/6;
        int yFinger1 = pos1%6;
        int xFinger2 = pos2/6;
        int yFinger2 = pos2%6;

        // choice1 finger1
        int pos = word[idx]-'A';
        int x2 = pos/6;
        int y2 = pos%6;
        int dis1 = abs(xFinger1-x2)+abs(yFinger1-y2);
        ret = dis1 + fn(idx+1, pos, pos2, word, dp);
        int dis2 = abs(xFinger2-x2)+abs(yFinger2-y2);

        ret = min(ret, dis2+ fn(idx+1, pos1, pos, word, dp));
        return ret; 
    }
public:
    int minimumDistance(string word) {

        int ans = INT_MAX;

        vector<vector<vector<int>>>dp(word.size()+1, vector<vector<int>>(31, vector<int>(31,INT_MAX/2)));
        for(int r = 0; r<= 25; r++)
        {
            for(int c = 0; c<= 25; c++)
                ans = min(ans, fn(0, r, c, word,dp));
        }
        return ans; 
    }
};
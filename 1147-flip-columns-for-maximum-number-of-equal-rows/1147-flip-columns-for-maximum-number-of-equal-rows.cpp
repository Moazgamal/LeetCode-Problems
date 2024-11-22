class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        int ans = 0; 
        string s1 = "";
        string s2 = "";
        for(int r = 0; r< matrix.size(); r++)
        {
            for(int c = 0; c< matrix[0].size(); c++)
            {
                if(matrix[r][c] == 0)
                    {
                        s1+= '0';
                        s2+= '1';
                    }
                else
                {
                    s1+='1'; s2+='0';
                }
                    
            }
            ans = max(ans, ++mp[s1]);
            ans = max(ans, ++mp[s2]);
            s1.clear(); s2.clear();
        }return ans;
        
    }
};
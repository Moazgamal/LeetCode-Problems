class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int>v (n,0);
        for(int i = 0; i< edges.size(); i++)
        {
            v[edges[i][1]]++;
        }
        int ans  = -1;
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i] ==0)
            {
                if(ans == -1)
                    ans = i;
                else
                    return -1;
            }
        }return ans;
        
    }
};
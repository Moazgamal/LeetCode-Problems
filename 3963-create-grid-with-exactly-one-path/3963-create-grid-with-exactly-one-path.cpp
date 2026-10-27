class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string>ans(m);
        for(int i = 0; i< n; i++)
            ans[0].push_back('.');
        
        for(int j = 1; j< m; j++)
        {
            for(int k = 0; k< n-1; k++)
                ans[j].push_back('#');
            ans[j].push_back('.');
        }
        return ans; 
    }
};
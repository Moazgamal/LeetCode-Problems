class Solution {
void dfs(string currency , unordered_map<string,vector<pair<string,double>>>&mp1,
        unordered_map<string,double>&mp, unordered_set<string> &st, double c)
{
    st.insert(currency);
    for(int j = 0; j< mp1[currency].size(); j++)
        {
            string s = mp1[currency][j].first;
            double cost = mp1[currency][j].second;
            if(st.find(s) == st.end())
            {
                mp[s] = c*cost;
                dfs(s, mp1, mp, st, c*cost);
            }
        }
}
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {

        unordered_map< string, vector<pair<string, double>> > mp1;
        
        unordered_map<string ,vector<pair<string, double>> > mp2;
        
        unordered_map<string, double> Day1;
        
        unordered_map<string,double> Day2;
        
        double initialCost = 1; 
        
        unordered_set<string>st;
        
        for(int i = 0; i< pairs1.size(); i++)
            {
                mp1[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
                mp1[pairs1[i][1]].push_back({pairs1[i][0], 1/rates1[i]});
            }
        
        dfs(initialCurrency, mp1, Day1, st, initialCost);
        
        st.clear();
        
        for(int i = 0; i< pairs2.size(); i++)
            {
                mp2[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
                mp2[pairs2[i][1]].push_back({pairs2[i][0], 1/rates2[i]});
            }
        dfs(initialCurrency, mp2, Day2, st, initialCost);
        
        double ans = 0; 
        
        for(auto x : Day2)
            {
                if(x.second>0)
                    ans = max(ans, Day1[x.first]/x.second);
            }
        return max(1.0,ans);
    }
};
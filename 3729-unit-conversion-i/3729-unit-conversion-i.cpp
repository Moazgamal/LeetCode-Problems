const int MOD = 1e9+7;
class Solution {
    
long long dfs( int node, unordered_map<int,long long> &mp, vector<pair<int,int>> &v)
{
	if(mp.count(node) != 0)
		return mp[node]%MOD;
	return mp[node] = (v[node].first*(dfs(v[node].second, mp, v)%MOD))%MOD;
}
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        vector<int> ans(conversions.size()+1,0);
        vector<pair<int,int>> v(conversions.size()+1);
        ans[0] = 1;
	for(int i = 0; i< (int)conversions.size(); i++)
	{
		int target = conversions[i][1];
		int source = conversions[i][0];
		int q = conversions[i][2];
		v[target] = make_pair(q,source);

	}
	unordered_map<int,long long>mp;
	mp[0] = 1;
        for(int i = 0; i< (int)ans.size(); i++)
		{

			ans[i] = dfs(i, mp, v)%MOD;
        }
        return ans;
        
    }
};
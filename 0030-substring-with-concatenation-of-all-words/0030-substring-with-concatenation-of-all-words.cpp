class Solution {
    void dfs(int idx , unordered_map<string, int> &mp, vector<bool> &v, int sz, int ws, string &s, unordered_set<int> &st)
{
	unordered_map<string, int> trav;
	int i = idx;
	trav[s.substr(idx, sz)]++;
	int j = idx;
	while(j<=s.size()+sz)
	{
		if(j-i+sz == ws)
		{
			st.insert(i);
			trav[s.substr(i,sz)]--; 
            i+=sz;
			if(j+sz >= s.size())
				return ;
		}
		else
		{
			j += sz;
			if(v[j] == true)

			{
				trav[s.substr(j,sz)]++;
				if(mp[s.substr(j,sz)] >= trav[s.substr(j,sz)])
					continue;
				else
				{
					string str = s.substr(j,sz);
					while(mp[str] < trav[str])
					{
						string str2 = s.substr(i,sz);
						trav[str2]--;
						v[i]=false;
						i+=sz;
					}
                   
				}
			}
			else
			{
				j-=sz;
				for(int m = i; m<=j; )
				{
					v[m]=false;
					m+=sz;
				}
				return ;
			}
		}
	}return ;

}
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string,int>mp;
		for(int i =0; i< words.size(); i++)
		{
			mp[words[i]]++;
		}
		int i = words[0].size();
		int sz = words[0].size();
		string cur = s.substr(0,sz);
		vector<bool> v (s.size(), false);
		if(mp.count(cur)>0)
			v[0]=true;
		int j = 0;
		while(i<s.size())
		{
			cur.erase(cur.begin());
			cur.push_back(s[i]);
			if(mp.count(cur)>0)
				v[j+1]=true;
			i++;
			j++;
		}
		int ws = sz*words.size();
        unordered_set<int> st;
		for(int i = 0; i< v.size(); i++)
		{
			if(v[i] == true && st.find(i) == st.end() )
			{
				dfs(i, mp,v,sz,ws  ,s, st);
			}
		}
        vector<int> ans;
		for(int i = 0; i< v.size(); i++)
				{
					if(v[i]==false)
						continue;
                    ans.push_back(i);
					
				}
        return ans;
    }
};
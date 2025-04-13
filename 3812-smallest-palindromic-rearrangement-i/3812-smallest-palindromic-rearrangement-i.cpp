class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
	for(int i = 0; i< (int)s.size() ;i ++)
	{
		mp[s[i]]++;
	}
	char oddChar ='$';
	if(s.size()%2 != 0)
	{
			for(auto x: mp)
			{
				if(x.second%2 != 0)
					oddChar = x.first;
			}
	}
	string acc = "";
	for(auto x: mp)
	{
		if(oddChar!= '$'&&x.first == oddChar && x.second==1)
			continue;
		int freq = x.second;
		acc.append(freq/2,x.first);
	}
	string acc2 = acc;
	reverse(acc2.begin(), acc2.end());
	if(oddChar != '$')
	{
		acc.append(1, oddChar);
	}
	return acc+acc2;
    }
};
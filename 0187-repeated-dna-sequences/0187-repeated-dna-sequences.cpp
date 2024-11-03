#define ll long long
#define MOD 2000000011ll
#define BASE 31ll
ll fastpow(ll num, ll p)
{
	if(p==0)
		return 1;
	if(p%2)
		return (num%MOD*fastpow(num, p-1))%MOD;
	ll a = fastpow(num, p/2);
	return (a*a)%MOD;
}
    ll removeAt(ll code, int indx, int val)
{
	return (code -(val*fastpow(BASE,indx)) % MOD +MOD)%MOD;
}
ll addAt(ll code, int indx, int val)
{
	return (code + (val*fastpow(BASE,indx)) %MOD)%MOD;
}
ll shiftLeft(ll code)
{
	return (code*BASE)%MOD;
}
class Solution {

public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<=10)
            return {};
    unordered_map<ll, int> mp;
    int n  =10;
    ll subCode = 0;
    vector<string>result;
	for(int i = 0; i< (int)s.size(); i++)
	{
		if(i-n >=0)
		{
			subCode = removeAt(subCode, n-1, s[i-n]);
		}
		subCode = shiftLeft(subCode);
		subCode = addAt(subCode, 0, s[i]);
		
            if(mp.count(subCode)>0)
        {
            if(mp[subCode]!=-1)
            {
                result.push_back(s.substr(i-9,10));
                mp[subCode]=-1;
            }
        }
        else
            mp[subCode]++;
        
    }
    return result;
    }
};
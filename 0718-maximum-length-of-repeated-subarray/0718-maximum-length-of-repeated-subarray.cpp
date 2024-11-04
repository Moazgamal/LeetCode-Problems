#define ll long long
#define MOD 1000000007ll
#define BASE1 13ll
#define BASE2 31ll

ll fastpow(ll num, ll p)
{
	if(p==0)
		return 1;
	if(p%2)
		return (num%MOD*fastpow(num, p-1))%MOD;
	ll a = fastpow(num, p/2);
	return (a*a)%MOD;
}
    ll removeAt(ll code, int indx, int val, ll BASE)
{
	return (code -(val*fastpow(BASE,indx)) % MOD +MOD)%MOD;
}
ll addAt(ll code, int indx, int val, ll BASE)
{
	return (code + (val*fastpow(BASE,indx)) %MOD)%MOD;
}
ll shiftLeft(ll code, ll BASE)
{
	return (code*BASE)%MOD;
}

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<ll, int> mp;
        ll subCode = 0;
        ll subCode2 =0;
    for(int i = 0; i< (int)nums1.size(); i++)
	{
        for(int j = i; j< nums1.size(); j++)
        {
            subCode = shiftLeft(subCode, BASE1);
            subCode2 = shiftLeft(subCode2, BASE2);
            if(nums1[j]==0)
		        {
                    subCode = addAt(subCode, 0, 1, BASE1);
                    subCode2 = addAt(subCode2, 0, 1, BASE2);
                }
            else
                {
                    subCode= addAt(subCode, 0, nums1[j]+1, BASE1);
                    subCode2= addAt(subCode2, 0, nums1[j]+1, BASE2);
                }
		
            
                mp[subCode*subCode2] =j-i+1;
           
                
            
        }
        subCode=0;
        subCode2=0;
    }
    subCode=0; int ans = 0; 
    subCode2=0;
    for(int i = 0; i< (int)nums2.size(); i++)
	{
        for(int j = i ; j< nums2.size(); j++)
        {
            subCode = shiftLeft(subCode, BASE1);
            subCode2 = shiftLeft(subCode2, BASE2);
            if(nums2[j]==0)
		        {
                    subCode = addAt(subCode, 0, 1, BASE1);
                    subCode2 = addAt(subCode2, 0, 1, BASE2);
                }
            else
                {
                    subCode= addAt(subCode, 0, nums2[j]+1, BASE1);
                    subCode2= addAt(subCode2, 0, nums2[j]+1, BASE2);
                }
		
            if(mp.count(subCode*subCode2)>0)
            {
                ans=max(ans, mp[subCode*subCode2]);
            }
        }

        subCode=0;
        subCode2=0;
    }return ans;



        
    }
};
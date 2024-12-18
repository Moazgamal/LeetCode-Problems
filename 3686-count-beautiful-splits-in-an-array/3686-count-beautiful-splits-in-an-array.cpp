class Solution {
    long long MOD = 1e9+7;
    long long BASE= 31;
    bool isPrefix(int start1, int end1, int start2, int end2, vector<long long> &p, vector<long long> &pow)
    {
        int len1 = end1 - start1;
        int len2 = end2 - start2;

        if (len1 > len2)
        {
            return false;
        }
        
         
        
        long long hash1 = (p[end1] - (p[start1]*pow[len1])%MOD + MOD)%MOD;
        
        
        long long hash2 = (p[start2+len1] - (p[start2]*pow[len1])%MOD + MOD) %MOD;
        return hash1 == hash2;
    }
public:
    int beautifulSplits(vector<int>& nums) {
         vector<long long> prefixHash(nums.size()+1,0);
         int patCode= 0; 
         vector<long long> pow(nums.size() + 1, 1); // Store powers of base
         for(int i = 0; i< nums.size(); i++)
         {
             pow[i + 1] = (pow[i] * BASE) % MOD;
            prefixHash[i+1] = (prefixHash[i]*BASE)%MOD;
            prefixHash[i+1] += nums[i];
            prefixHash[i]%=MOD;
             
         }
        int ans = 0; 
         for(int i = 1; i< nums.size()-1; i++)
         {
            for(int j = i+1; j< nums.size(); j++)
            {
                bool ispre1 = isPrefix(0,i, i, j, prefixHash, pow);
                bool ispre2= isPrefix(i,j,j, nums.size(), prefixHash, pow);
                if(ispre1 || ispre2)
                    ans++;
            }
         }return ans;

        
    }
};
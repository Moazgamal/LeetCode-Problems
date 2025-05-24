class Solution {
    bool isPrime(long long n)
    {
        if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
    }
public:
    long long sumOfLargestPrimes(string s) {

        long long ans = 0; 
        unordered_map<string,bool>mp;
        set<long long, greater<long long>> st;
        for(int i = 0; i< s.size(); i++)
            {
        string str = "";
                for(int j = i; j< s.size(); j++)
                    {
                        str.push_back(s[j]);
                        if(mp.count(str)==0)
                        {
                            long long num = stoll(str);
                            if(isPrime(num))
                            {
                                st.insert(num);
                            }
                            mp[str]= true;
                        }
                    }
            }
        int cnt   =0; 
        for(auto x: st)
            {
                ans+= x;
                cnt++;
                if(cnt ==3)
                    return ans;
            }
        return ans; 
        
    }
};
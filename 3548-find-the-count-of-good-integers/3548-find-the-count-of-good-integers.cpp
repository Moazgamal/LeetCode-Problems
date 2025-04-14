class Solution {
    long long factorial(int n)
    {
        long long ans = 1; 
        for(int i = 1; i<= n; i++)
        {
            ans*=i;
        }return ans;
    }
    
     void backtracking(int n,int k, string &acc, vector<string>& pals)
    {
        if((int)acc.size() == n/2)
        {
            string x1 ="";
            for(int q = 0; q<(int)acc.size(); q++ )
                x1.push_back(acc[q]);
           
            string x2 ="";
            if(n %2 ==0)
            {
                x2 = x1;
                 reverse(x2.begin(), x2.end());
                x1 = x1+x2;
                if(stoll(x1) %k != 0)
                    return ;
                pals.push_back(x1);
            }
            else
            {
                int u = 0; 
                if((int)acc.size() == 0)
                    u=1;
                for(;u<10; u++)
                {
                    x2 = x1;
                    reverse(x2.begin(), x2.end());
                    x1.push_back(char(u+'0'));
                    if(stoll(x1+x2)%k != 0)
                    {
                        x1.pop_back(); continue;

                    }
                    pals.push_back(x1+x2);
                    x1.pop_back();
                } 
            }

            return ;
        }
        int j = 0; 
        if((int)acc.size() == 0)
            j++;
        
        for(; j<10; j++)
        {
           acc.push_back(char(j+'0'));
            backtracking(n,k,acc,pals);
            acc.pop_back();
        }
    }
public:
    long long countGoodIntegers(int n, int k) {
    
        long long ans = 0; 

        string acc ="";
        vector<string> pals;
        backtracking(n,k, acc, pals);
        // unique pals
        set<string>st;
        for(int i = 0; i< pals.size(); i++)
        {
            vector<int>freq(10,0);
            for(int j = 0; j< pals[i].size(); j++)
            {
                freq[pals[i][j]-'0']++;
            }
            string pattern ="";
            for(int k = 0; k< freq.size(); k++)
            {
                pattern.push_back(freq[k]+'a');
            }
            st.insert(pattern);
        }
        long long perms = factorial(n);
        for(auto x: st)
        {
            long long cperms = perms;
            for(int i = 0; i<x.size(); i++)
            {
                cperms/= factorial(x[i]-'a');
            }
            if(x[0] != 'a')
            {
                long long u = factorial(n-1);
                int freqzeros = (x[0]-'a')-1;
                for(int i = 1; i<x.size(); i++)
                {
                    u/= factorial(x[i]-'a');
                }
                u/= factorial(freqzeros);
                cperms-=u;
            }
            ans += cperms;

        }
        return ans; 
        
    }
};
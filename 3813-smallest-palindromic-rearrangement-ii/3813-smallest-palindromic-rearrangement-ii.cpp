using ll = long long;
static ll maxK = 1000001; 
class Solution {

    ll fn(int len , int freq)
    {
        if(freq> len)
            return 0;
        if(freq > len-freq)
            freq = len-freq;
        ll ans = 1; 
        for(int i = 1; i<= freq; i++)
        {
           ans = ans* (len-i+1)/i;
           if(ans >= maxK)
            return ans;
        }
        return ans;
    }
    
    ll multinomial(vector<int> &freq)
    {
        int len = 0; 
        for(int i = 0; i< freq.size(); i++)
        {
            len += freq[i];
        }
        ll ans = 1; 
        for(int i = 0; i< freq.size(); i++)
        {
            if(freq[i] ==0)
                continue;
            ans *= fn(len, freq[i]);
            if(ans >= maxK)
                return ans;
            len -= freq[i];
        }
        return ans;
    }
public:
    string smallestPalindrome(string s, int k) {

        vector<int> freq(26,0);
        for(int i = 0; i< s.size(); i++)
        {
            freq[s[i]-'a']++;
        }
        char oddChar = '$';
        int len = 0; 
        for(int i = 0; i< freq.size(); i++)
        {
            if(freq[i]%2 !=0)
            {
                oddChar = i+'a';
            }
            freq[i] /= 2;
            len += freq[i];
        }
        ll totalPerms = multinomial(freq);
        if(totalPerms < k)
            return "";
        string answer = "";
        for(int i = 0; i< len; i++)
        {
            for(int c = 0; c< 26; c++)
            {
                if(freq[c]==0)
                    continue;
                freq[c]--;
                ll perms = multinomial(freq);
                if(perms>=k)
                {
                    answer.push_back((char)(c+'a'));
                    break;
                }
                else
                {
                    k-=perms; freq[c]++;
                }
            }
        }
        string ans = answer;
        reverse(ans.begin(), ans.end());
        if(oddChar!= '$')
            answer.push_back(oddChar);
        return answer+ans;
        

        
        

        
    }
};
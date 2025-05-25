class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>mp;
        for(int i = 0; i< words.size(); i++)
        {
            mp[words[i]]++;
        }
        int evens = 0; 
        bool w = false;
        for(auto x: mp)
        {
            string str = x.first;
            reverse(str.begin(), str.end());
            if(mp.count(str) !=0 && str[0] != str[1])
            {
                int f = mp[str];
                f = min(f, x.second);
                
                evens += (4*f);
                mp[str]=0;
            }
            else if(str[0] == str[1])
            {
                int f = mp[str];
                if(f%2 ==0)
                    evens += 2*f;
                else
                {
                    evens += (2*(f-1));
                    w = true;
                }
            }
        }
        return evens+ 2*w;

    }
};
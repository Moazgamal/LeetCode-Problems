class Solution {
    bool fn2(char c , string &s, int ops)
    {
        for(int i = 0; i< s.size();i++)
        {
            if(s[i] != c)
                ops--;
            c = c^1;
        }return ops>=0;
    }
    bool fn(int targetSize, string &s, int ops)
    {
        if(targetSize == 1)
            return fn2('0', s, ops) || fn2('1', s, ops);
        int neededOps = 0; 
        for(int i = 0; i< s.size(); )
        {
            char c = s[i];
            int len=0;
            while(i< s.size() && s[i] == c)
            {
                len++;
                i++;
            }
           
            neededOps += floor(len/(targetSize+1));
            if(neededOps > ops)
                return false;
            
        }
        return neededOps <= ops;
    }
public:
    int minLength(string s, int numOps) {
        int maxi = 1;
        for(int i = 0; i< s.size(); )
        {
            char c = s[i];
            int len=0;
            while(i< s.size() && s[i] == c)
            {
                len++;
                i++;
            }
            maxi = max(maxi, len);
        }
        if(numOps ==0 || maxi == 1)
            return maxi;
        int start = 1;
        int end = s.size();
        int mid = -1; int pos = -1;

        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(fn(mid, s, numOps))
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        
        return pos;
        
    }
};
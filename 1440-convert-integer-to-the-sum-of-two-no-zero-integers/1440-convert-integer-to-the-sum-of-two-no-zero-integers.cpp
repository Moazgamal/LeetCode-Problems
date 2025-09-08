class Solution {
    bool check(int num)
    {
        while(num >= 10)
        {
            if(num %10 == 0)
                return false;
            num /= 10; 
        }
        return true; 

    }
    pair<int,int>fn(int idx, string &str, int prev, int maxi, string &acc, int &n)
    {
        if(idx == str.size()-1)
        {
            for(int i = 1; i<= maxi; i++)
            {
                acc.push_back(i+'0');
                int num = stoi(acc);
                int num2 = n-num;
                if(check(num2))
                {
                    return {num, num2};
                }
                acc.pop_back();
            }
            return {-1,-1};
        }
        pair<int,int>p  = {-1,-1};
        for(int i = 0; i<= maxi; i++)
        {
            if(i == 0)
            {
                if(prev == 0)
                {
                    
                    pair<int,int> v = fn(idx+1, str, 0, 9,acc, n);
                    if(v != p)
                        return v;
                }
            }
            else
            {
                acc.push_back(i+'0');
                if(i != maxi)
                {
                    pair<int,int>v = fn(idx+1, str, i, 9, acc, n);
                    if(v != p)
                        return v; 
                }
                else
                {
                    pair<int,int>v = fn(idx+1, str, i, str[idx+1]-'0', acc, n);
                    if(v != p)
                        return v; 
                }
                acc.pop_back();
            }
        }
        return {-1, -1};
    }
public:
    vector<int> getNoZeroIntegers(int n) {

        unordered_map<int,bool>mp;
        if(n<=10)
        {
            return {1, n-1};
        }
        
        string str = to_string(n);
        string acc = "";
        pair<int,int> p = fn(0, str, 0, str[0]-'0', acc,n);
        return {p.first, p.second};
        
    }
};
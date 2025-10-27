class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sz = bank.size();
        vector<int>rows(bank.size(), 0);
        int i = 0; 
        while(i< sz)
        {
            int j = 0; int sz2 = bank[i].size();
            while(j< sz2)
            {
                if(bank[i][j] == '1')
                    rows[i]++;
                j++;
            }
            i++;
        }
        
        int ans = 0;  i = 0; 
        while(i< sz-1)
        {
            int j = i+1; 
            while(j<sz && rows[j] == 0)
            {
                j++;
            }
            if(j == sz)
                return ans; 
            ans += (rows[i]*rows[j]);
            i=j;
        }return ans; 
        
    }
};
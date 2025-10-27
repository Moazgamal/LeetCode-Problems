class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sz = bank.size();
        vector<int>rows(bank.size(), 0);
        for(int i =0; i< sz; i++)
            for(int j = 0; j< bank[i].size(); j++)
                if(bank[i][j] == '1')
                    rows[i]++;
        
        
        int ans = 0; int i = 0; 
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
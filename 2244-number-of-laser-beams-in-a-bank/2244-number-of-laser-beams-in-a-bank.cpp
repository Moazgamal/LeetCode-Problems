class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>rows(bank.size(), 0);
        for(int i =0; i< bank.size(); i++)
            for(int j = 0; j< bank[i].size(); j++)
                if(bank[i][j] == '1')
                    rows[i]++;
        
        
        int ans = 0; 
        for(int i =0; i< rows.size()-1; )
        {
            int j = i+1; 
            while(j<rows.size() && rows[j] == 0)
            {
                j++;
            }
            if(j == rows.size())
                return ans; 
            ans += (rows[i]*rows[j]);
            i=j;
        }return ans; 
        
    }
};
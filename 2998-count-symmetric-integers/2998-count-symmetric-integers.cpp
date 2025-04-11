class Solution {
    void backtracking(int i, int &low, int &high, int &ans, string &acc)
    {
        if((int)acc.size() == i)
        {
            int z= stoi(acc);

            if(z<low || z>high)
                return ;
            
            int sum1 = 0; int sum2 = 0; 

            for(int q = 0; q<(int)acc.size()/2; q++ )
                sum1 += (acc[q]+'0');

            for(int q = acc.size()/2 ; q<(int)acc.size(); q++)
                sum2 += (acc[q]+'0');

            if(sum1 == sum2 &&  sum1+sum2 !=0)
                ans++;

            return ;
        }
        int j = 0; 
        if((int)acc.size() ==0)
            j++;
        
        for(; j<10; j++)
        {
           acc.push_back(char(j+'0'));
            backtracking(i, low, high,ans, acc);
            int z= stoi(acc);

            if(z>high)
            {
                acc.pop_back();
                return ;
            }
            acc.pop_back();
        }
    }
public:
    int countSymmetricIntegers(int low, int high) {
        string s1 = to_string(low);
        string s2 = to_string(high);
        
        int ans = 0; 
        string acc ="";
        for(int i = s1.size(); i<= s2.size(); i++)
        {
            if(i%2!=0)
                continue;
            backtracking(i, low, high, ans, acc);
        }
       
        return ans; 
        
    }
};
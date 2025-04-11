class Solution {
    void backtracking(int i, int &low, int &high, int &ans, string &acc, int cnt)
    {
        if(cnt == i)
        {
            // cout<<cnt<<" "<<i<<" cnt\n";
            int z= stoi(acc);
            if(z<low || z>high || z ==0 || (int)acc.size()%2 !=0)
                return ;
            
            int sum1 = 0; int sum2 = 0; 
            for(int q = 0; q<(int)acc.size()/2; q++ )
            {
                sum1 += (acc[q]+'0');
            }
            for(int q = acc.size()/2 ; q<(int)acc.size(); q++)
            {
                sum2 += (acc[q]+'0');
            }
            if(sum1 == sum2 &&  sum1+sum2 !=0)
            {
            // cout<<sum1<<" "<<sum2<<" "<<z<<"\n";
                ans++;

            }
            return ;
        }
        int j = 0; 
        if(cnt ==0)
        {
            j++;
        }
        for(; j<10; j++)
        {
            
           acc.push_back(char(j+'0'));
           cnt++;
            backtracking(i, low, high,ans, acc, cnt);
            cnt--;
            acc.pop_back();
        }
    }
public:
    int countSymmetricIntegers(int low, int high) {
        string s1 = to_string(low);
        string s2 = to_string(high);
        
        int ans = 0; 
        string acc ="";
        int cnt = 0; 
        for(int i = s1.size(); i<= s2.size(); i++)
        {
            if(i%2!=0)
                continue;
            // cout<<i<<"\n";
            backtracking(i, low, high, ans, acc, cnt);
        }
       
        return ans; 
        
    }
};
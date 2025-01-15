class Solution {
    pair<int,string> countBits(int num)
    {
        int cnt =0; string ans ="";
        while(num > 0)
        {
            int x = num%2;
            num = num/2;
            ans.push_back(x+'0');
            if(x==1)
                cnt++;
        }
        reverse(ans.begin(), ans.end());
        return {cnt,ans};
    }
public:
    int minimizeXor(int num1, int num2) {

        pair<int,string> setBits1 = countBits(num1);
        pair<int,string> setBits2 = countBits(num2);
        if(setBits1.first == setBits2.first)
            return num1;
        string str1 = setBits1.second;
        string str2 = setBits2.second;
        int x = 0;
        cout<<setBits1.first<<" "<<setBits2.first<<"\n";
        if(setBits1.first > setBits2.first)
        {
            int sz = str1.size();
            for(int i = 0; i< str1.size() && setBits2.first; i++)
            {
                if(str1[i] == '1')
                {
                    x += (1<<(sz-i-1));
                    setBits2.first--;
                }
            }
            return x;
        }
         if(setBits1.first < setBits2.first)
        {
            int rest = setBits2.first-setBits1.first;
            int sz = str1.size();
            for(int i = str1.size()-1; i>=0; i--)
            {
                if(str1[i] == '1')
                {
                    x += (1<<(sz-i-1));
                }
                
            }
            for(int i = str1.size()-1; i>=0 && rest; i--)
            {
                if(str1[i] == '0')
                {
                    x += (1<<(sz-i-1));
                    rest--;
                }
                
            }
            sz++;
            while(rest-- >0)
            {
                x += (1<<(sz-1));
                sz++;
            }
            return x;
        }
        return 0; 
        
    }
};
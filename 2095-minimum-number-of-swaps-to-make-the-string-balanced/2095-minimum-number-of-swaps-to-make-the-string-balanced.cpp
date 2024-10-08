class Solution {
public:
    int minSwaps(string s) {
        int  j = s.size()-1;
        int swaps= 0;
        int prevno=0;
        for(int i = 0; i< s.size(); i++)
        {
            if(i>j)
            {
                break;
            }
            if(s[i]==']')
            {
                if(prevno==0)
                {
                    while(s[j]!='[')
                    {
                        j--;
                    }
                    j--;
                    prevno++;
                    swaps++;
                }
                else
                    prevno--;
            }
            else
            {
                if(i<=j)
                    prevno++;
                else
                    break;
            }
        }
        return swaps;
        
    }
};
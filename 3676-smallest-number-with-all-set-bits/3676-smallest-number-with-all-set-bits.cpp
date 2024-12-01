class Solution {
public:
    int smallestNumber(int n) {
        // int ans = 0;
        // int i = 0; 
        // while(true)
        //     {
        //         ans += (1<<i);
        //         i++;
        //         if(ans>=n)
        //                 return ans;
        //     }
        // return ans; 
        int leftMostBit = 0;
        for(int i = 0; i<10; i++)
        {
           if( ((1<<i) & n) == (1<<i))
           {
                leftMostBit = i; 
           }
        }
        cout<<leftMostBit<<"\n";
        int no = (1<<leftMostBit);
        no = no+ (no-1);
        if(no >= n)
            return no;
        leftMostBit++;
        no = (1<<leftMostBit); no = no+(no-1);
        return no ;
        
    }
};
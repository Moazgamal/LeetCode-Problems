class Solution {
public:
    char findKthBit(int n, int k) {

        int inversions = 0;
        while(n>0)
        {
            int m = pow(2,n)-1;
            if(k> m/2+1)
            {
                inversions++;
                k = m-k+1;
            }
            n--;
        }
        if(inversions%2==0)
            return '0';
        return '1';

        
    }
};
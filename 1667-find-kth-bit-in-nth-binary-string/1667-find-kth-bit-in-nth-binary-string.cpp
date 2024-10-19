class Solution {
public:
    char findKthBit(int n, int k) {

        int inversions = 0;
        while(n--)
        {
            int m = pow(2,n+1)-1;
            if(k> m/2+1)
            {
                inversions++;
                k = m-k+1;
            }
        }
        if(inversions%2==0)
            return '0';
        return '1';

        
    }
};
class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int sumOdd = 0; 
        int sumEven = 0; int n1 = 0; int n2 = 0; 
        for(int i =1; true ; i++)
        {
            if(i%2 == 0)
            {
                sumEven+=i; n1++;
            }
            if(n1 == n)
                break;
        }
        for(int i =1; true ; i++)
        {
            if(i%2 != 0)
            {
                sumOdd+=i; n2++;
            }
            if(n2 == n)
                break;
        }
        return __gcd(sumOdd, sumEven);
        
    }
};
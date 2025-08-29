class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int sumOdd = 0; 
        int sumEven = 0;
        int sum = (n*(n+1))/2;
        n--;
        int sum2 = (n*(n+1))/2;
        return __gcd(sum+sum2, sum*2);
        
    }
};
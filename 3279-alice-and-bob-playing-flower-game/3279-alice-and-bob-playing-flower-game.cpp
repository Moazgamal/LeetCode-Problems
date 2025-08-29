class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long ans = 0; 
        long long evensN = 0; 
        int oddsN = 0; 
        evensN = n/2;
        oddsN = n/2;
        if(n%2 != 0)
            oddsN++;
        long long evensM = 0; 
        int oddsM = 0; 
        evensM = m/2;
        oddsM = m/2;
        if(m%2 != 0)
            oddsM++;
        return (oddsN*evensM)+(evensN*oddsM);
        
    }
};
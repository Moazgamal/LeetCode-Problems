class Solution {
public:
    int minSensors(int n, int m, int k) {

        int val1 = n/(2*k+1);
        if(n%(2*k+1) !=0)
            val1++;
        int val2 = m/(2*k+1);
        if(m%(2*k+1)!=0)
            val2++;
        return val1*val2;
        
    }
};
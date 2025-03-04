class Solution {
    bool fn(int power, int number, int maxipower, int accsum)
    {
        if(accsum== number)
            return true;
        if(accsum>number)
            return false;
        if(power > maxipower)
            return false;
        bool leave = fn(power+1, number, maxipower, accsum);
        if(leave)
            return true;
        bool pick = fn(power+1, number, maxipower, pow(3,power)+accsum);
        return pick ;
    }
public:
    bool checkPowersOfThree(int n) {
    
        int base = 3;
        int maxi = ceil(std::log(n) / std::log(base));  
        return fn(0, n, maxi,0);

    }
};
class Solution {
    vector<bool> generatePrimes(int limit) {
    vector<bool> prime(limit + 1, true);
    
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p]) {
            // Update all multiples of p as false
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
    }
    int fn(int no1, int no2, int maxiv, vector<int>& x)
    {
        if(x[no2]==-1)
            return INT_MIN;
        if(no1 - x[no2] > maxiv)
            {
                return x[no2];
            }
        return fn(no1, x[no2], maxiv, x);
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int limit = 1000;
        vector<bool> v = generatePrimes(limit);
        vector<int> x(1001,0);
        int curprime = -1;
        for(int i =0; i< v.size(); i++)
        {
            x[i] = curprime;
            if(v[i] == true)
            {
                curprime= i;
            }
        }
        int maxiv = INT_MIN;
        for(int i = 0; i< nums.size(); i++)
        {
            int val = fn(nums[i], nums[i], maxiv, x);
            cout<<val<<" \n";
            if(val == INT_MIN)
            {
                if(maxiv == INT_MIN)
                    maxiv = nums[i];
                else
                {
                    if(nums[i]>maxiv)
                        maxiv=nums[i];
                    else
                        return false;
                }
            }
            else
            {
                if(nums[i]-val <= maxiv)
                {
                    return false;  
                } 
                maxiv = nums[i] -val;
            }
        }return true;
        
    }
};
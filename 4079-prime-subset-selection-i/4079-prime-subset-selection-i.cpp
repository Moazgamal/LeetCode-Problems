class Solution {
    // const int N = 1e6;

vector<int> getPrimes(int N) {
    vector<bool> isPrime(N, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; ++i) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j < N; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; ++i) 
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    return primes;
}
public:
    vector<int> maxPrimes(int n, int s) {
        const int N = n+1;
        vector<int> primes = getPrimes(N);
        int sum = 0; 
        vector<int>ans;
        for(int i = 0; i< primes.size(); i++)
        {
            if(sum+primes[i] <= s)
            {
                ans.push_back(primes[i]);
                sum+=primes[i];
            }
        }
        if(sum>s)
            return {};
        return ans; 
        
    }
};
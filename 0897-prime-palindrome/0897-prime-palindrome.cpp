class Solution {
    vector<int>mirror1{0}; vector<int>mirror2{0};
    bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int gen(int dig, int factor, int &n)
{
    vector<int> mirror;
    for(int i = 0; i< 10; i++)
    {
        for(int j = 0; j< mirror1.size(); j++)
        {
            int num = factor*i+ mirror1[j]*10 + i;
            mirror.push_back(num);
            if(num>=n && isPrime(num))
                return num;
        }
    }
    swap(mirror1, mirror2);
    swap(mirror2, mirror);
    return gen(dig+1, factor*10,n);
}
public:
    int primePalindrome(int n) {

        for(int i =1; i< 10; i++)
        {
            if(isPrime(i))
            {
                if(i>=n)
                {
                    return i; 
                }
            }
            mirror2.push_back(i);
        }
        return gen(2, 10,n);

        
    }
}; 
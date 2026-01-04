class Solution {
    void getPrimes(int num, int &sum)
    {
        int p = 0; 
        set<int>v;
        int sum2 = 0; 
        int org = num;
        for(int i = 2; num>1 && i<=num; i++)
        {
            int f = 1; 
            while((num>1)&& (num%i == 0) )
            {
                v.insert(i*f);
                f=i*f;
                num /= i; 
            }
        }
        v.insert(org); v.insert(1);
        if(v.size()==4)
        {
            v.insert(1);
            for(auto m: v)
                sum += m;
        }
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int tot = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            int sum = 0; 
            getPrimes(nums[i], sum);
            tot+=sum;
        }
        return tot; 
    }
};
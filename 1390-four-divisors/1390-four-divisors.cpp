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
                if(v.size()==4)
                    return; 
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
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            int sum = 0; 
            if(mp.count(nums[i]) >0)
            {
                tot += mp[nums[i]];
                continue;
            }
            getPrimes(nums[i], sum);
            tot+=sum;
            mp[nums[i]]= sum; 
        }
        return tot; 
    }
};

class Solution {
    int fn(int num)
    {
        int cnt = 0; 
        while(num > 0)
        {
            if(num %2 == 1)
                cnt++;
            num /= 2;
        }return cnt;
    }
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool>v(right+1, true);
        v[0]=false; v[1]=false;
        for(int i = 2 ; i <= right; i++)
        {
            if(v[i] == false)
                continue;
            int cnt = 2; 
            while(i*cnt < right+1)
            {
                v[i*cnt] = false; 
                cnt++;
            }
        }int ans = 0; 
        for(int i = left; i <= right; i++)
        {
            int numOfSetBits = fn(i);
            if(v[numOfSetBits] == true)
                ans++;
        }return ans; 
    }
};
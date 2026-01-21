class Solution {
    string fn(int num)
    {
        string str = "";
        while(num>0)
        {
            str.push_back((num%2)+'0');
            num /= 2;
        }
        str.push_back('0');
        reverse(str.begin(), str.end());
        return str; 
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]%2 == 0)
                continue;
            string str = fn(nums[i]);
            int cnt = 0;
            for(int j = str.size()-1; j>=0; j--,cnt++)
            {
                if(str[j] == '0')
                {
                    int x = nums[i] - (1<<(cnt-1));
                    ans[i] = x;
                    break;
                }
            }
        }
        return ans;
    }
};
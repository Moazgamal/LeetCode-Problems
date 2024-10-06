class Solution {
    string br(int &no)
    {
        string s = "";
        while(no>0)
        {
            s+=((no%2)+'0');
            no= no/2;
        }
        reverse(s.begin(), s.end());
        cout<<s<<" ";
        
        return s;
    }
    int eval(string s1)
    {
        int ans = 0;
        int x = 1;
        for(int i = s1.size()-1; i>=0; i--)
        {
            if(s1[i]=='0')
            {
                x=x*2;
                continue;
            }
            ans += ((s1[i]-'0')*x);
            x = x*2;
        }
        return ans;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        
        
        string s1 =br(nums[0]);
        string s2 = br(nums[1]);
        string s3 = br(nums[2]);
        int ans = 0;
        ans = max(ans, eval(s1+s2+s3));
        ans = max(ans, eval(s1+s3+s2));
        ans = max(ans, eval(s2+s1+s3));
        ans = max(ans, eval(s2+s3+s1));
        ans = max(ans, eval(s3+s2+s1));
        ans = max(ans, eval(s3+s1+s2));
        return ans;
        
    }
};
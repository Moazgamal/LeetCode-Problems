class Solution {
    int fn(int num)
    {
        string str = "";
        while(num >0)
        {
            str.push_back((num%2)+'0');
            num /=2;
        }
        int j = 0; int newNum = 0; 
        for(int i= str.size()-1; i>=0; j++,i--)
        {
            if(str[i] == '0')
                continue;
            newNum += (1<<j);
        }
        return newNum;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i = 0; i< nums.size(); i++)
        {
            v.push_back({fn(nums[i]), nums[i]});
        }sort(v.begin(), v.end());
        vector<int>ans;
        for(int i = 0; i< v.size(); i++)
        {
            ans.push_back(v[i].second);
        }return ans; 
        
    }
};
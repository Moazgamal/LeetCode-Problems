class Solution {
    bool backtracking(int idx , unordered_set<string>&st, string &ans, int &sz)
    {
        if(idx == sz)
        {
            if(st.find(ans) == st.end())
            {
                return true;
            }
            return false;
        }
        ans.push_back('0');
        if(backtracking(idx+1, st, ans, sz))
            return true;
        ans.pop_back();
        ans.push_back('1');
        if(backtracking(idx+1, st,ans, sz))
            return true;
        ans.pop_back();
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(int i =0; i< nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        string ans = "";
        int sz = nums.size();
        backtracking(0, st, ans, sz);
        return ans;
        
    }
};
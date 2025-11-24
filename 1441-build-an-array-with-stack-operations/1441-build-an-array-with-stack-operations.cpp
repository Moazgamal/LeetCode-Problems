class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int curr = 0; 
        int i = 1; 
        while(i<= n && curr< target.size())
        {
            if(target[curr] == i)
            {
                ans.push_back("Push");
                curr++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        return ans; 
        
    }
};
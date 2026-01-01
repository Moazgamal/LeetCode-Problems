class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; 
        for(int i = digits.size()-1; i>=0; i--)
        {
           int coll = digits[i] + carry;
           carry = coll / 10; 
           digits[i] = coll %10;
        }
        vector<int>ans;
        if(carry > 0)
            ans.push_back(carry);
        for(int i = 0; i< digits.size(); i++)
        {
            ans.push_back(digits[i]);
        }
        return ans; 
        
    }
};
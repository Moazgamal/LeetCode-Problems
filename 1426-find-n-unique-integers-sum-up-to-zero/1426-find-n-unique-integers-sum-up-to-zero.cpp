class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2 != 0)
            ans.push_back(0);
        int sz = n/2;
        while(sz-- > 0)
        {
            ans.push_back(n); ans.push_back(-n);
            n--;
        }return ans; 
        
        
    }
};
class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        int n1 = nums[0];
        int n2 = nums[1];
        int n3 = nums[2];
        if(n1 + n2 <= n3 || n1+n3 <= n2 || n2+n3<=n1)
            return "none";
        if(n1 == n2  && n2== n3)
            return "equilateral";
        if(n1 == n2 || n1 == n3 || n2 == n3)
            return "isosceles";
        return "scalene";

    }
};
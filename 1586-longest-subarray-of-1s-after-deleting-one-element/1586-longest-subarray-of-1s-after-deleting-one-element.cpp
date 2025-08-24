class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i = 0; int j = 0; int zeros = 0;  int ans1 = -1; int ans2= -1; 
        while(i < nums.size())
        {
            if(nums[i] == 1)
            {
                i++;
                if(zeros ==0)
                {
                    ans2 = max(ans2, i-j)-1;
                }
                else
                    ans1 = max(ans1, i-j-zeros);
                continue;
            }
            else
            {
                zeros++;
                if(zeros==2)
                {
                    while(j<i)
                    {
                        if(nums[j] == 0)
                        {
                            zeros--; j++; break;
                        }
                        else
                            j++;
                    }
                }
                i++;
                if(zeros == 0)
                    ans2 = max(ans2, i-j-zeros)-1;
                else
                    ans1 = max(ans1, i-j-zeros);
            }
        }
        return max(ans1, ans2);
        
    }
};
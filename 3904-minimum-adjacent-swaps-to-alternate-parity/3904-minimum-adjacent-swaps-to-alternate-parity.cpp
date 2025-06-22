class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int odds = 0;
        int evens = 0; 
        for(int i = 0; i< nums.size(); i++)
            {
                if(nums[i]%2 ==0)
                    evens++;
                else
                    odds++;
            }
        if(nums.size()%2 ==0)
        {
            if(evens != odds)
                return -1;
        }
        else
        {
            bool x = false;
            if(evens == odds+1 || odds == evens+1)
                x=true;
            if(!x)
                return -1;
        }
        int ans = INT_MAX; 
        vector<int>v1;
        vector<int>v2;
        for(int i = 0; i< nums.size(); i++)
            {
                if(nums[i]%2 ==0)
                {
                    v1.push_back(i);
                }
                else
                {
                    v2.push_back(i);
                }
            }
        if(evens == odds && evens == 1)
            return 0 ;
        
        if(evens>odds)
        {
            int acc1 = 0; 
            for(int i = 0; i< v1.size(); i++)
                {
                    acc1 += abs(v1[i]- 2*i);
                }
            ans = min(ans, acc1);
        }
        if(odds>evens)
        {
            int acc = 0; 
            for(int i = 0; i< v2.size(); i++)
                {
                    acc+= abs(v2[i] - 2*i);
                }
            ans = min(ans, acc);
        }

        if(odds == evens)
        {
            int acc1 = 0; 
            for(int i = 0; i< v1.size(); i++)
                {
                    acc1 += abs(v1[i]- 2*i);
                }
            ans = min(ans, acc1);

            int acc = 0; 
            for(int i = 0; i< v2.size(); i++)
                {
                    acc+= abs(v2[i] - 2*i);
                }
            ans = min(ans, acc);
            
        }
        return ans; 
    }
};
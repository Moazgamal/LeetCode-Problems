class Solution {
    void fn(vector<int>&arr, int &ans, bool val)
    {
        int i = 0; 
        while(i < arr.size())
        {
            int j = i+1; 
            bool x = i %2 == 0 ? val: !val; 
            while(j< arr.size())
            {
                if(x)
                {
                    if(arr[j] > arr[j-1])
                    {
                        j++; x = !x; ans = max(ans, j-i); continue;
                    }
                    else
                    {
                        ans = max(ans, j-i); i = j; break;
                    }
                }
                else
                {
                    if(arr[j]< arr[j-1])
                    {
                        j++; x= !x; ans = max(ans, j-i); continue;
                    }
                    else
                    {
                        ans = max(ans, j-i); i = j; break;
                    }
                }
            }
            if(j == arr.size())
                return;
        }
        return;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 0;
        if(arr.size()==1)
            return 1; 
        fn(arr, ans, true);
        fn(arr, ans, false);
        return ans; 
        
    }
};
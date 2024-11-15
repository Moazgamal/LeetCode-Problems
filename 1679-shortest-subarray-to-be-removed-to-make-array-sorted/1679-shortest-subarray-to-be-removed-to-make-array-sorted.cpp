class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) 
        {
            right--;
        }

        int ans = right;
        if(ans == 0)
            return ans;
        int left = 0;
        while ((left == 0 || arr[left - 1] <= arr[left])) 
        {
            // find next valid number after arr[left]
            while (right < arr.size() && arr[left] > arr[right]) 
            {
                right++;
            }
            // save length of removed subarray
            ans = min(ans, right - left - 1);
            left++;
        }
        return ans;
    }
};
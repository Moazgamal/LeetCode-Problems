class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size()-1; i++)
            mini = min(mini, abs(arr[i+1]-arr[i]));
        vector<vector<int>>ans;
        for(int i = 0; i< arr.size()-1; i++)
            if(abs(arr[i+1]-arr[i]) == mini)
                ans.push_back({arr[i], arr[i+1]});
        return ans; 
    }
};
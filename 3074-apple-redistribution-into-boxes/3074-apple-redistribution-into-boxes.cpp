class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int sum = 0; 
        for(int i = 0; i< apple.size(); i++)
        {
            sum += apple[i];
        }
        int ans = 0; 
        sort(capacity.rbegin(), capacity.rend());
        for(int j = 0; j< capacity.size(); j++)
        {
            sum -= capacity[j];
            ans++;
            if(sum <=0)
            {
                return ans; 
            }
        }return ans;
        
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {

        vector<int>v1(height.size(), -1);
        vector<int>v2(height.size(), -1);
        stack<int>st1;
        for(int i = 0; i< height.size(); i++)
        {
            if(st1.empty())
            {
                st1.push(i); continue;
            }
            while(!st1.empty() && height[st1.top()] < height[i])
            {
                v1[st1.top()] = i; st1.pop();
            }
            st1.push(i);
        }
        stack<int>st2;
        for(int i = height.size()-1; i>=0; i--)
        {
            if(st2.empty())
            {
                st2.push(i); continue;
            }
            while(!st2.empty() && height[st2.top()] < height[i])
            {
                v2[st2.top()] = i; st2.pop();
            }
            st2.push(i);
        }
        int i = 0; int j = height.size()-1;
        int ans = 0; 
        while(i < j && i != -1 && j != -1)
        {
            int mini = min(height[i], height[j]);
            ans = max(ans, mini*(j-i));
            if(height[i] == height[j])
            {
                i = v1[i]; j = v2[j];
            }
            else if(height[i] > height[j])
            {
                j = v2[j];
            }
            else
            {
                i = v1[i];
            }
        }
        return ans; 
        
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minCost = 0; 
        int i = 0; 
        int sz = colors.size();
        while(i< sz)
        {
            int j =i+1;
            int acc = neededTime[i]; 
            int maxi = neededTime[i];
            while(j< sz && colors[i] == colors[j])
            {
                acc += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }
            if(j-i>1)
            {
                acc -= maxi;
                minCost+=acc;
            }
            i=j;
        }return minCost;
        
    }
};
class Solution {
    int maxN(int start, int end, vector<pair<int,int>>&v, vector<vector<vector<int>>>& memo, int cnt) {
        // Base case: empty string requires 0 turns
       if(start == end)
       {
        return (cnt+v[start].second)*(cnt+v[start].second);
       }
        if (start > end) {
            return 0;
        }

        // If result is memoized, return it
        if (memo[start][end][cnt] != -1) {
            return memo[start][end][cnt];
        }
        int k = cnt+v[start].second;
        // Initialize with worst case: print each character separately
        int maxi = k*k + maxN(start + 1, end, v, memo, 0);

        // Try to optimize by finding matching characters
        for (int j = start+1; j <=end; j++) {
            if (v[j].first == v[start].first) 
            {
                // If match found, try splitting the problem
                int turnsWithMatch = maxN(start+1, j - 1, v, memo,0) +
                                     maxN(j, end, v,memo,k);
                maxi = max(maxi, turnsWithMatch);
            }
        }

        // Memoize and return the result
        return memo[start][end][cnt] = maxi;
    }
public:
    int removeBoxes(vector<int>& boxes) {

        vector<pair<int,int>>v;
        for(int i = 0; i< boxes.size(); )
        {
            int j = i+1;
            while(j< boxes.size() && boxes[j] == boxes[i])
            {
                j++;
            }
            v.push_back({boxes[i], j-i});
            i=j;
        }
        int n = v.size();
vector<vector<vector<int>>> memo(101, vector<vector<int>>(101, vector<int>(101,-1)));
        return maxN(0, n - 1, v, memo,0); 
        
    }
};
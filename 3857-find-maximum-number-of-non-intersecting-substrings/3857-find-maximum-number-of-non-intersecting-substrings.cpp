class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
    vector<pair<int, int>> intervals;
        vector<vector<int>> pos(26);
    for (int i = 0; i < n; ++i) 
    {
        pos[word[i] - 'a'].push_back(i);
    }

    for (int c = 0; c < 26; ++c) 
    {
        auto &v = pos[c]; 
        int sz = v.size();
        for (int i = 0; i < sz; ++i) 
        {
            for (int j = i+1; j <= sz - 1; ++j) 
            {
                if (v[j] - v[i] + 1 >= 4) 
                {
                    intervals.push_back({v[j], v[i]});
                    break; 
                }
            }
        }
    }
    sort(intervals.begin(), intervals.end());
    int lastend = -1; 
    int ans = 0; 
    for(int i = 0; i< intervals.size(); i++)
    {
        if(lastend == -1)
        {
            ans++; lastend= intervals[i].first;
            continue;
        }
        else if(intervals[i].second <= lastend)
            continue;
        else
        {
             ans++; lastend= intervals[i].first;
            continue;
        }
        
    }return ans; 


        
    }
};
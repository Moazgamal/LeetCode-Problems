class Solution {
    bool backtracking(string &cur, int idx, unordered_map<char, unordered_map<char, unordered_set<char> >> &mp, string acc , int level, int levels)
    {
        if(level == levels)
        {
            return true; 
        }
        if(idx == cur.size()-1)
        {
            return backtracking(acc, 0, mp, "", level+1, levels); 
        }
        
        if(mp[cur[idx]][cur[idx+1]].size() == 0 || mp.count(cur[idx]) == 0||
        mp[cur[idx]].count(cur[idx+1]) == 0)
            return false; 
        for(auto x: mp[cur[idx]][cur[idx+1]])
        {
            acc.push_back(x);
            if(backtracking(cur, idx+1, mp, acc, level, levels))
                return true;
            acc.pop_back();
        }
        return false; 
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        // Apply Backtracking

        unordered_map<char, unordered_map<char, unordered_set<char> >> mp;
        for(int i = 0; i< allowed.size(); i++)
        {
            int left = allowed[i][0];
            int right = allowed[i][1];
            int c = allowed[i][2];
            mp[left][right].insert(c);
        }
        string acc = "";
        return backtracking(bottom, 0, mp, acc, 1, bottom.size());
    }
};
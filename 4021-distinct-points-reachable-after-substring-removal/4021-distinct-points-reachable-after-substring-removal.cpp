class Solution {
    void fn(int x, int y, string &s, int idx, vector<pair<int,int>> &v)
    {
        if(idx == s.size())
            return; 
        if(s[idx] == 'L') x--;
        else if(s[idx] == 'R') x++;
        else if(s[idx] == 'D') y--;
        else y++;
        v[idx+1] = {x, y};   // prefix position
        fn(x, y, s, idx+1, v);
    }
    void fn2(int i, int k, vector<pair<int,int>> &v, set<pair<int,int>> &st)
    {
        if(i+k > v.size()-1) return;
        auto total = v.back();
        // final = total displacement - removed displacement
        int fx = total.first - (v[i+k].first - v[i].first);
        int fy = total.second - (v[i+k].second - v[i].second);
        st.insert({fx, fy});
        fn2(i+1, k, v, st);
    }
public:
    int distinctPoints(string s, int k) {
        if(s.size() <= k) return 1; 
        
        vector<pair<int,int>> v(s.size()+1);
        v[0] = {0,0};
        fn(0,0,s,0,v);   // build prefix sums

        set<pair<int,int>> st;
        fn2(0, k, v, st);
        return (int)st.size();
    }
};

class Solution {

    pair<pair<int,int>, vector<int>> fn(
        int IDX,
        vector<pair<int,int>>& v,
        vector<pair<pair<int,int>, vector<int>>>& Dp,
        vector<int>& nxt
    )
    {
        if(IDX >= v.size())
            return {{0,0}, {}};

        auto &ret = Dp[IDX];

        if(ret.first.first != -1)
            return ret;

        // leave
        auto leave = fn(IDX + 1, v, Dp, nxt);

        // pick
        auto pickNext = fn(nxt[IDX], v, Dp, nxt);

        pair<pair<int,int>, vector<int>> pick = pickNext;

        pick.first.first++;
        pick.first.second += v[IDX].second - v[IDX].first + 1;
        pick.second.push_back(v[IDX].first);

        if(pick.first.first > leave.first.first)
            return ret = pick;

        if(pick.first.first < leave.first.first)
            return ret = leave;

        // same number -> minimum total length
        if(pick.first.second < leave.first.second)
            return ret = pick;

        return ret = leave;
    }


public:

    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        /*
            valid intervals

            For every character, start with [first[c], last[c]]
            and expand it if it contains another character.
        */

        vector<pair<int,int>> v;

        for(int c = 0; c < 26; c++)
        {
            if(last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for(int i = l; i <= r; i++)
            {
                int x = s[i] - 'a';

                if(first[x] < l)
                {
                    valid = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if(valid)
                v.push_back({l,r});
        }

        sort(v.begin(), v.end());

        /*
            nxt[i] = first interval whose start is
            strictly after v[i].second
        */

        vector<int> nxt(v.size());

        for(int i = 0; i < v.size(); i++)
        {
            int pos = v.size();

            for(int j = i + 1; j < v.size(); j++)
            {
                if(v[j].first > v[i].second)
                {
                    pos = j;
                    break;
                }
            }

            nxt[i] = pos;
        }

        vector<pair<pair<int,int>, vector<int>>> Dp(
            v.size() + 1,
            {{-1,-1}, {}}
        );

        vector<int> ans = fn(
            0,
            v,
            Dp,
            nxt
        ).second;

        vector<string> answer;

        for(int start : ans)
        {
            for(auto &p : v)
            {
                if(p.first == start)
                {
                    answer.push_back(
                        s.substr(
                            p.first,
                            p.second - p.first + 1
                        )
                    );

                    break;
                }
            }
        }

        return answer;
    }
};
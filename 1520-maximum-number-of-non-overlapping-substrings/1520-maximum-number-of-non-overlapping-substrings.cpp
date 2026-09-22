class Solution {

    pair<pair<int,int>, vector<int>> fn(
        int IDX,
        vector<pair<int,int>>& v,
        vector<pair<pair<int,int>, vector<int>>>& Dp,
        vector<int>& nxt
    )
    {
        if(IDX >= v.size())
        {
            return {{0,0},{}};
        }

        auto &ret = Dp[IDX];

        if(ret.first.first != -1)
            return ret;

        // pick
        pair<pair<int,int>, vector<int>> pick = fn(
            nxt[IDX],
            v,
            Dp,
            nxt
        );

        pick.first.first++;

        pick.first.second +=
            v[IDX].second - v[IDX].first + 1;

        pick.second.push_back(v[IDX].first);


        // leave
        pair<pair<int,int>, vector<int>> leave =
            fn(
                IDX + 1,
                v,
                Dp,
                nxt
            );


        // more substrings
        if(pick.first.first > leave.first.first)
            return ret = pick;

        if(pick.first.first < leave.first.first)
            return ret = leave;


        // same number of substrings
        // minimum total length
        if(pick.first.second < leave.first.second)
            return ret = pick;

        return ret = leave;
    }


    int BS(
        vector<pair<int,int>>& v,
        int start,
        int enD,
        int target
    )
    {
        int pos = -1;

        while(start <= enD)
        {
            int miD = start + (enD - start) / 2;

            if(v[miD].first > target)
            {
                pos = miD;
                enD = miD - 1;
            }
            else
            {
                start = miD + 1;
            }
        }

        return pos;
    }


public:

    vector<string> maxNumOfSubstrings(string s)
    {
        vector<int> starts(26,-1);
        vector<int> enDs(26,-1);


        // first / last occurrence
        for(int i = 0; i < s.size(); i++)
        {
            if(starts[s[i] - 'a'] == -1)
                starts[s[i] - 'a'] = i;

            enDs[s[i] - 'a'] = i;
        }


        vector<pair<int,int>> v;

        unordered_map<int,int> mp;


        // build valid intervals
        for(int i = 0; i < 26; i++)
        {
            if(starts[i] == -1)
                continue;

            int start = starts[i];
            int enD = enDs[i];

            bool valid = true;

            for(int j = start; j <= enD; j++)
            {
                int c = s[j] - 'a';

                if(starts[c] < start)
                {
                    valid = false;
                    break;
                }

                enD = max(enD, enDs[c]);
            }

            if(valid)
            {
                v.push_back({start,enD});

                mp[start] = enD;
            }
        }


        sort(v.begin(),v.end());


        // next interval
        vector<int> nxt(v.size());

        for(int i = 0; i < v.size(); i++)
        {
            nxt[i] = BS(
                v,
                i + 1,
                (int)v.size() - 1,
                v[i].second
            );

            if(nxt[i] == -1)
                nxt[i] = v.size();
        }


        // DP only depends on IDX
        vector<pair<pair<int,int>, vector<int>>> Dp(
            v.size(),
            {{-1,-1},{}}
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
            int E = mp[start];

            answer.push_back(
                s.substr(
                    start,
                    E - start + 1
                )
            );
        }

        return answer;
    }
};
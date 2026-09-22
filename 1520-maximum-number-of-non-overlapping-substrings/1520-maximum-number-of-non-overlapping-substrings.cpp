class Solution {

    pair<pair<int,int>, vector<int>> fn(
        int IDX,
        vector<pair<int,int>>& v,
        vector<vector<pair<pair<int,int>, vector<int>>>>& Dp,
        vector<int>& IND,
        int lastEnD,
        unordered_map<int,int>& mp,
        vector<int>& IND2
    )
    {
        if(IDX >= v.size())
        {
            return {{0,0},{}};
        }

        auto &ret = Dp[IDX][lastEnD];

        if(ret.first.first != -1)
            return ret;

        // pick
        pair<pair<int,int>, vector<int>> pick = {{0,0},{}};

        int newIDX = IND[IDX];

        if(newIDX != -1)
        {
            pick = fn(
                newIDX,
                v,
                Dp,
                IND,
                v[IDX].second,
                mp,
                IND2
            );
        }

        pick.first.first++;
        pick.first.second +=
            v[IDX].second - v[IDX].first + 1;

        pick.second.push_back(v[IDX].first);

        // leave
        pair<pair<int,int>, vector<int>> leave = {{0,0},{}};

        if(IDX + 1 < v.size())
        {
            leave = fn(
                IDX + 1,
                v,
                Dp,
                IND,
                lastEnD,
                mp,
                IND2
            );
        }

        // more substrings
        if(leave.first.first < pick.first.first)
            return ret = pick;

        if(leave.first.first > pick.first.first)
            return ret = leave;

        // same number of substrings
        // choose minimum total length
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


        vector<int> IND(v.size() + 1);
        vector<int> IND2(s.size() + 1);


        for(int i = 0; i < v.size(); i++)
        {
            IND[i] = BS(
                v,
                i + 1,
                (int)v.size() - 1,
                v[i].second
            );

            IND2[v[i].first] = IND[i];
        }


        vector<vector<pair<pair<int,int>, vector<int>>>> Dp(
            v.size() + 1,
            vector<pair<pair<int,int>, vector<int>>>(
                s.size() + 1,
                {{-1,-1},{}}
            )
        );


        vector<int> ans = fn(
            0,
            v,
            Dp,
            IND,
            v.size(),
            mp,
            IND2
        ).second;


        vector<string> answer;

        for(int i = 0; i < ans.size(); i++)
        {
            int E = mp[ans[i]];

            answer.push_back(
                s.substr(
                    ans[i],
                    E - ans[i] + 1
                )
            );
        }

        return answer;
    }
};
class Solution {

    pair<pair<int,int>, vector<int>> fn(
        int IDX,
        vector<pair<int,int>>& v,
        vector<vector<pair<pair<int,int>, vector<int>>>>& Dp,
        vector<int>& IND,
        int lastEnD,
        unordered_map<int,int>& mp,
        vector<int>& IND2,
        string& s,
        vector<int>& starts,
        vector<int>& enDs
    )
    {
        if(IDX >= v.size())
        {
            return {{0,0},{}};
        }

        auto &ret = Dp[IDX][lastEnD];

        if(ret.first.first != -1)
            return ret;


        // =========================
        // pick
        // =========================

        int start = v[IDX].first;
        int enD = v[IDX].second;

        bool canTake = true;


        // =========================
        // validate / expand
        // =========================

        for(int i = start; i <= enD; i++)
        {
            int c = s[i] - 'a';

            // this character appeared before start
            // so current substring cannot contain it
            if(starts[c] < start)
            {
                canTake = false;
                break;
            }

            // expand interval
            enD = max(enD, enDs[c]);
        }


        pair<pair<int,int>, vector<int>> pick = {{0,0},{}};


        if(canTake)
        {
            int newIDX = BS(
                v,
                IDX + 1,
                (int)v.size() - 1,
                enD
            );


            if(newIDX == -1)
            {
                pick = {{1,0},{}};
            }
            else
            {
                pick = fn(
                    newIDX,
                    v,
                    Dp,
                    IND,
                    enD,
                    mp,
                    IND2,
                    s,
                    starts,
                    enDs
                );

                pick.first.first++;
            }


            pick.first.second += enD - start + 1;

            pick.second.push_back(start);
        }


        // =========================
        // leave
        // =========================

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
                IND2,
                s,
                starts,
                enDs
            );
        }


        if(!canTake)
            return ret = leave;


        // =========================
        // compare
        // =========================

        if(pick.first.first > leave.first.first)
            return ret = pick;

        if(pick.first.first < leave.first.first)
            return ret = leave;


        // same number of substrings
        // choose smaller total length
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


        // =========================
        // first / last occurrence
        // =========================

        for(int i = 0; i < s.size(); i++)
        {
            if(starts[s[i] - 'a'] == -1)
                starts[s[i] - 'a'] = i;

            enDs[s[i] - 'a'] = i;
        }


        vector<pair<int,int>> v;

        unordered_map<int,int> mp;


        // =========================
        // initial intervals
        // =========================

        for(int i = 0; i < 26; i++)
        {
            if(starts[i] == -1)
                continue;


            int start = starts[i];
            int enD = enDs[i];


            v.push_back({start,enD});

            mp[start] = enD;
        }


        sort(v.begin(),v.end());


        vector<int> IND(v.size()+1);
        vector<int> IND2(s.size()+1);


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


        // =========================
        // DP
        // =========================

        vector<vector<pair<pair<int,int>, vector<int>>>> Dp(
            v.size()+1,
            vector<pair<pair<int,int>, vector<int>>>(
                s.size()+1,
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
            IND2,
            s,
            starts,
            enDs
        ).second;


        // =========================
        // build answer
        // =========================

        vector<string> answer;


        for(int i = 0; i < ans.size(); i++)
        {
            int start = ans[i];

            int enD = mp[start];


            for(int j = start; j <= enD; j++)
            {
                int c = s[j] - 'a';

                enD = max(enD, enDs[c]);
            }


            answer.push_back(
                s.substr(
                    start,
                    enD - start + 1
                )
            );
        }


        return answer;
    }
};
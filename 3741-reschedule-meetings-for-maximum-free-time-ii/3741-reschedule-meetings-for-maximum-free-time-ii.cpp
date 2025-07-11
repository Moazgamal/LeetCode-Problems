class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        multiset<int> st;
        for (int i = 0; i < startTime.size(); i++)
        {
            v.push_back({startTime[i], endTime[i]});
        }
        sort(v.begin(), v.end());
        int ans = 0; 
        for (int i = 0; i < v.size(); i++)
        {
            int start = v[i].first; 
            int end   = v[i].second;
            if (i == 0)
            {
                int x = start ;
                if (x >= 1) st.insert(x);
            }
            else
            {
                int x = start - v[i-1].second;
                if (x >= 1) st.insert(x);
            }

            if (i == v.size() - 1) 
            {
                int y = eventTime - end;
                if (y >= 1) st.insert(y);
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            int start = v[i].first; 
            int end   = v[i].second;
            if (i == 0)
            {
                int x = start;
                if (x >= 1)
                {
                    st.erase(st.find(x));
                }

                if (i + 1 < v.size())
                {
                    int y = v[i+1].first - end;
                    ans = max(ans, start + (v[i+1].first - end));
                    if (y >= 1)
                        st.erase(st.find(y));
                    
                    int duration = end - start;
                    int val = -1;
                    if(!st.empty())
                            val = *st.rbegin();
                    if (val >= duration)
                    {
                        ans = max(ans, v[i+1].first);
                    }

                    st.insert(y);
                    
                }
                else
                {
                    int y = eventTime - end;
                    ans = max(ans, start + (eventTime - end));
                    if (y >= 1)
                        st.erase(st.find(y));
                    
                    int duration = end - start;
                    int val = -1;
                    if(!st.empty())
                            val = *st.rbegin();
                    if (val >= duration)
                        ans = max(ans, eventTime);
                    st.insert(y);
                }

                if (x >= 1)
                    st.insert(x);
            }
            else if (i == v.size() - 1)
            {
                int x = start - v[i-1].second;
                if (x >= 1) st.erase(st.find(x));

                int y = eventTime - end;
                if (y >= 1) st.erase(st.find(y));

                ans = max(ans, (eventTime - end) + (start - v[i-1].second));
                int duration = end - start;
                int val = -1;
                if(!st.empty())
                    val = *st.rbegin();
                if (val >= duration)
                    ans = max(ans, eventTime - v[i-1].second);

                if (x >= 1) st.insert(x);
                if (y >= 1) st.insert(y);
            }
            else
            {
                int x = start - v[i-1].second;
                int y = v[i+1].first - end;
                if (x >= 1) st.erase(st.find(x));
                if (y >= 1) st.erase(st.find(y));

                int duration = end - start;
                int val = -1;
                if(!st.empty())
                    val = *st.rbegin();
                if (val >= duration)
                    ans = max(ans, v[i+1].first - v[i-1].second);

                ans = max(ans, x + y);

                if (x >= 1) st.insert(x);
                if (y >= 1) st.insert(y);
            }
        }

        return ans;
    }
};

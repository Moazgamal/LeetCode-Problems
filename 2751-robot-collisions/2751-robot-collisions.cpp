class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        vector<pair<int,int>>v;
        vector<pair<int,int>>v2;
        for(int i = 0; i< positions.size(); i++)
            v.push_back({positions[i], i});
        sort(v.begin(), v.end());
        stack<int>st;
        for(int i = 0; i< v.size(); i++)
        {
            if(st.empty())
            {
                st.push(v[i].second);
                continue;
            }
            
            char curDir = directions[v[i].second];
            
            if(curDir == directions[st.top()]  || curDir=='R' && directions[st.top()] == 'L')
            {
                st.push(v[i].second); continue;
            }
            while(!st.empty() && curDir == 'L' && directions[st.top()] == 'R')
            {
                if(healths[v[i].second] > healths[st.top()])
                {
                    st.pop();
                    healths[v[i].second]--;
                    if(st.empty() || curDir == directions[st.top()])
                    {
                        st.push(v[i].second);
                        break;
                    }
                    continue;
                }
                else if(healths[v[i].second] == healths[st.top()])
                {
                    st.pop();
                    break;
                }
                else
                {
                    healths[st.top()]--;
                    break;
                }
            }
        }
        while(!st.empty())
        {
            v2.push_back({st.top(), healths[st.top()]});
            st.pop();
        }
        sort(v2.begin(), v2.end());
        vector<int>ans;
        for(int i = 0; i< v2.size(); i++)
            ans.push_back(v2[i].second);
        return ans; 
    }
};
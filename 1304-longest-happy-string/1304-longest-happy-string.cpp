class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>> pq;
        if(a>0)
            pq.push({a,'a'});
        if(b>0)
            pq.push({b,'b'});
        if(c>0)
            pq.push({c,'c'});
        string ans = "";
        while(!pq.empty())
        {
            pair<int,char> p = pq.top();
            pq.pop();
            int count = p.first;
            int charac = p.second;

            if(ans.size()>=2 && ans[ans.size()-1] == charac && ans[ans.size()-2] == charac)
            {
                if(pq.empty())
                    break;
                pair<int,char> temp = pq.top();
                pq.pop();
                ans+=temp.second;
                if(temp.first-1>0)
                    pq.push({temp.first-1, temp.second});
            }
            else
            {
                count--;
                ans+=charac;
            }
            if(count>0)
                pq.push({count, charac});

        }
        return ans;
    }
};
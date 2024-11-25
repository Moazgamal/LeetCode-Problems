class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {


        string finalState = "123450";
        queue<string>q;
        string s = "";
        for(int i = 0; i< board.size(); i++)
        {
            for(int j = 0; j< board[0].size(); j++)
            {
                s+=board[i][j]+'0';
            }
        }
        q.push(s);
        unordered_map<string,int>mp;
        unordered_map<int,vector<int>> v;
        v[0].push_back(1); v[0].push_back(3); v[1].push_back(0); v[1].push_back(2); v[1].push_back(4);
        v[2].push_back(1); v[2].push_back(5); v[3].push_back(4); v[3].push_back(0);
        v[4].push_back(3); v[4].push_back(5); v[4].push_back(1); v[5].push_back(2);
        v[5].push_back(4);
        if(s==finalState)
            return 0;
        for(int level=0, sz = q.size(); !q.empty(); sz= q.size(), level++)
        {
            while(sz--)
            {
                string ss = q.front(); q.pop();
                cout<<ss;
                if(ss==finalState)
                    return level;
                int i = 0;
                for(; i< ss.size(); i++)
                {
                    if(ss[i]=='0')
                        break;
                }
                for(int j =0; j<v[i].size(); j++)
                {
                    swap(ss[v[i][j]],ss[i]);
                    if(mp.count(ss)==0)
                        q.push(ss);
                    mp[ss]++;
                    cout<<ss<<" \n";
                    swap(ss[v[i][j]],ss[i]);
                }
            }
        }return -1;
        
    }
};
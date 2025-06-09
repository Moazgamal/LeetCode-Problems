class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>v;
        v.push_back(a); v.push_back(b); v.push_back(c);
        sort(v.begin(), v.end());
        int mini = -1; 
        if(v[1]-v[0] ==1)
        {
            if(v[2]-v[1] ==1)
                mini= 0;
            else
                mini= 1;
        }
        if(v[2]-v[1] ==1)
        {
            if(v[1]-v[0]==1)
                mini= 0; 
            else
                mini= 1; 
        }
        if(mini==-1)
        {
            if(v[1]-v[0]==2 || v[2]-v[1]==2)
            {
                mini = 1;
            }
            else
                mini=2;
        }
        int maxi = (v[1]-v[0]-1)+(v[2]-v[1]-1);
        return {mini, maxi};
        
    }
};
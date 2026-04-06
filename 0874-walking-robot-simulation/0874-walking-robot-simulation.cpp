class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {


        unordered_map<int, unordered_set<int> > mp;
        for(int i = 0; i< obstacles.size(); i++)
        {
            int x = obstacles[i][0];
            int y = obstacles[i][1];
            mp[x].insert(y);
        }
        char curDir = 'N';
        int ans = 0; 
        int curX = 0; int curY = 0;
        for(int i = 0; i< commands.size(); i++)
        {
            if(commands[i] == -1)
            {
                if(curDir == 'N')
                    curDir = 'E';
                else if(curDir == 'E')
                    curDir = 'S';
                else if(curDir == 'S')
                    curDir = 'W';
                else if(curDir == 'W')
                    curDir = 'N';
            }
            else if(commands[i] == -2)
            {
                if(curDir == 'N')
                    curDir = 'W';
                else if(curDir == 'E')
                    curDir = 'N';
                else if(curDir == 'S')
                    curDir = 'E';
                else if(curDir == 'W')
                    curDir = 'S';
            }
            else
            {
                int steps = commands[i];
                if(curDir == 'N')
                {
                    while(steps && (mp.count(curX)==0||mp[curX].find(curY+1)==mp[curX].end())){
                        
                        curY++;
                        ans = max(ans, curX*curX + curY*curY);
                        steps--;
                    }
                }
                else if(curDir == 'E')
                {
                    while(steps && (mp.count(curX+1)==0||mp[curX+1].find(curY)==mp[curX+1].end())){
                        
                        curX++;
                        ans = max(ans, curX*curX + curY*curY);
                        steps--;
                    }
                }
                else if(curDir == 'S')
                {
                    while(steps && (mp.count(curX)==0||mp[curX].find(curY-1)==mp[curX].end())){
                        
                        curY--;
                        ans = max(ans, curX*curX + curY*curY);
                        steps--;
                    }
                }
                else if(curDir == 'W')
                {
                    while(steps && (mp.count(curX-1)==0||mp[curX-1].find(curY)==mp[curX-1].end())){
                        
                        curX--;
                        ans = max(ans, curX*curX + curY*curY);
                        steps--;
                    }
                }
            }
        }
        return ans; 
    }
};
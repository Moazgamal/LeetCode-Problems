class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        
        long long ans = 0; 
        unordered_map<int,bool> vis;
        for(int i = 0; i< instructions.size(); )
            {
                if(vis.count(i)!=0)
                    return ans;
                if(instructions[i] == "add")
                {
                    vis[i]= true;
                    ans+= values[i];
                    i++;
                }
                else
                {
                    vis[i]= true;
                    i = i + values[i];
                }
                
            }
        return ans;
    }
};
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long>v(skill.size()); v[0] = skill[0]*mana[0];
        for(int i =1; i< v.size(); i++)
        {
            v[i] = v[i-1]+(mana[0]*skill[i]);
        }
        int j = 1; 
        while(j < mana.size())
        {
            int lastIdx = 0;
            for(int i = 0; i< v.size()-1; i++)
            {
                long long acc = v[i]+ (skill[i]*mana[j]);
                if(acc >= v[i+1])
                {
                    v[i] = acc; v[i+1] = acc;
                }
                else
                {
                    v[i] = v[i+1];
                    lastIdx = i; 
                }
            }
            v[v.size()-1] += (skill[v.size()-1]*mana[j]);
            for(int i = lastIdx; i>0; i--)
            {
                v[i-1]= (v[i]-(skill[i]*mana[j])) ;
            }
            j++;
        }
        return v[v.size()-1];
        
    }
};
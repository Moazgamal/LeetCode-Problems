class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum=skill[0]+skill[skill.size()-1];
        int sz = skill.size()-1;
        long long ans = skill[0]*skill[skill.size()-1];
        for(int i = 1; i< skill.size()/2; i++)
        {
            if(skill[i] + skill[sz-i] != sum)
                return -1;
            else
                ans+=(skill[i]*skill[sz-i]);
        }
        return ans;
        
    }
};
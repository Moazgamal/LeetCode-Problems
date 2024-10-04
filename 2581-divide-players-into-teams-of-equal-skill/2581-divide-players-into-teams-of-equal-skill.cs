public class Solution {
    public long DividePlayers(int[] skill) {

        Array.Sort(skill);
        int sz = skill.Length-1;
        int sum=skill[0]+skill[sz];
        
        for(int i = 1; i< skill.Length/2; i++)
        {
            if(skill[i] + skill[sz-i] != sum)
                return -1;
        }
        long ans =0;
        for(int i  =0; i< skill.Length/2; i++)
        {
            ans+=(skill[i]*skill[sz-i]);
        }return ans;
        
    }
}
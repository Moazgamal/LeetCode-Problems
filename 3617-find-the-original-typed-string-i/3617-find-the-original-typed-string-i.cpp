class Solution {
public:
    int possibleStringCount(string word) {

        
        int ans=0;
        for(int i = 0; i< word.size(); i++)
            {
                int j =i;
                while(j<word.size() && word[j] == word[i])
                    {
                        j++;
                    }
                ans+=(j-i-1);
                i=j-1;
            }
        
        return ans+1;
        
    }
};
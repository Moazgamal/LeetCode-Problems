class Solution {
    bool isvowel(char c)
    {
        if(c== 'a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result(queries.size(),0);
        vector<int> prefixSum(words.size(),0);
        int prefix = 0; 
        for(int i =0; i< words.size(); i++)
        {
            int sz = words[i].size();
            if(isvowel(words[i][0]) && isvowel(words[i][sz-1]))
                prefix++;
            prefixSum[i] = prefix;
        }
        for(int i = 0; i< queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            if(start ==0)
            {
                result[i] = prefixSum[end];
            }
            else
            {
                result[i] = prefixSum[end] -prefixSum[start-1];
            }
        }return result;
        
    }
};
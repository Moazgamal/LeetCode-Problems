class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1Idx = 0;
        int word2Idx = 0;
        int charIdx1 = 0;
        int charIdx2 = 0;
        int word1Sz = word1.size();
        int word2Sz= word2.size();
        while(word1Idx < word1Sz && word2Idx < word2Sz)
        {
            if(word1[word1Idx][charIdx1] != word2[word2Idx][charIdx2])
                return false;
            
            if(charIdx1 + 1 == word1[word1Idx].size())
            {
                charIdx1 = 0;
                word1Idx++;
            }
            else
                charIdx1++;

            if(charIdx2 +1 == word2[word2Idx].size())
            {
                charIdx2 = 0;
                word2Idx++;
            }
            else
                charIdx2++;
        }
        if(word1Idx != word1Sz || word2Idx != word2Sz)
            return false;
        return true;


        
    }
};
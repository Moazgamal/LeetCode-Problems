class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 0;
        for(int i = 0; i< sentence.size(); i++)
        {
            int j = 0; 
            while(j<searchWord.size()&&i< sentence.size() && sentence[i] != ' ')
            {
                if(searchWord[j] == sentence[i])
                    {
                        j++;i++;
                    }
                else
                    {
                        while(i< sentence.size() && sentence[i] != ' ')
                        {
                            i++;
                        }
                    }
            }
            idx++;
            if(j==searchWord.size())
                return idx;
        }
        return -1;
        
    }
};
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt = 1;
        for(int i = 0; i< sentence.size(); i++)
        {
            int j =0; 
            while(j<searchWord.size() && i<sentence.size() && sentence[i] != ' ')
            {
                if(sentence[i] == searchWord[j])
                {
                    i++; j++;
                }
                else
                {
                    while(i<sentence.size()&&sentence[i] != ' ')
                    {
                        i++;
                    }
                }
            }
            if(j==searchWord.size())
                return cnt;
            cnt++;

        }return -1;
        
    }
};
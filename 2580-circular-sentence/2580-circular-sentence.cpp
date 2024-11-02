class Solution {
public:
    bool isCircularSentence(string sentence) {

        for(int i = 0; i< sentence.size() ; i++)
        {
            int j = i;
            while(j< sentence.size() && sentence[j] != ' ')
            {
                j++;
            }
            if(j== sentence.size())
            {
                if(sentence[j-1] != sentence[0])
                    return false;
            }
            else if(sentence[j-1] != sentence[j+1])
                return false;
            i=j;

        }
        return true;
        
    }
};
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int j =0; 
        for(int i = 0; i< sentence.size() ; i++)
        {
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
            i=j; j++;

        }
        return true;
        
    }
};
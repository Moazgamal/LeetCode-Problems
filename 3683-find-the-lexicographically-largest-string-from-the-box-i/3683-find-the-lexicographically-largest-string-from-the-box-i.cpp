class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
            return word;
        int maxLength = word.size() - numFriends +1;
        string ans = word.substr(0,maxLength);
        
        for(int i = 0; i< word.size(); i++)
            {
                if(word[i]< ans[0])
                        continue;
                if(i+maxLength-1 >= word.size())
                {
                    if(ans < word.substr(i,word.size()-i))
                    {
                        ans = word.substr(i,word.size()-i);
                    }
                }
                else if(ans < word.substr(i,maxLength))
                {
                    ans = word.substr(i,maxLength);
                }
            }
        return ans;
        
    }
};
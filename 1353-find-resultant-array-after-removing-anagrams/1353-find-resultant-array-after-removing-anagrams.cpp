class Solution {
    bool areAnagrams(string &str1, string &str2)
    {
        if(str1.size() != str2.size())
            return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i = 0; i< str1.size(); i++)
        {
            v1[str1[i]-'a']++;
            v2[str2[i]-'a']++;
        }
        for(int i = 0; i< 26; i++)
        {
            if(v1[i] != v2[i])
                return false; 
        }
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string>ans;
        int start = 0;
        ans.push_back(words[start]);
        for(int end = 1; end< words.size(); end++)
        {
            if(areAnagrams(words[start], words[end]))
                continue;
            ans.push_back(words[end]);
            start = end; 
        }
        return ans; 
        
    }
};
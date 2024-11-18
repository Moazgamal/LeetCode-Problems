class Solution {
    class Trie
    {
        public :
        const static int MAXCHAR  = 26;
        Trie* arr[MAXCHAR]{};
        int cnt{}; 
         void add_word(string &str, int idx=0)
        {
            if(idx>=str.size())
                return ;
            int i = str[idx]-'a';
            if(arr[i] == nullptr)
                arr[i] = new Trie();
            arr[i]->cnt++;
            arr[i]->add_word(str, idx+1);
        }
    int is_prefix(string &str, int idx= 0)
        {
            int sum = 0; 
            if(idx>=str.size())
                return 0;
            int i = str[idx]-'a';
            
            if(!arr[i])
                return 0;
            sum += arr[i]->cnt;
            return sum+arr[i]->is_prefix(str, idx+1);
        }
        
    };
   
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(int i = 0; i< words.size(); i++)
        {
            trie->add_word(words[i]);
        }
        vector<int>result(words.size(),0);
        for(int i = 0; i< words.size(); i++)
        {
            int cnt = 0; 
            
                cnt += trie->is_prefix(words[i]);
            
            result[i]= cnt;
        }return result;
        
    }
};
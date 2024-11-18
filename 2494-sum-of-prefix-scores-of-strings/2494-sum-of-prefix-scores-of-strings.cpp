class Solution {
    class Trie
    {
        public :
        const static int MAXCHAR  = 26;
        Trie* arr[MAXCHAR]{};
        int cnt{}; 
        
        
    };
    void add_word(Trie* &trie,string &str, int idx=0)
        {
            if(idx>=str.size())
                return ;
            int i = str[idx]-'a';
            if(trie->arr[i] == nullptr)
                trie->arr[i] = new Trie();
            trie->arr[i]->cnt++;
            add_word(trie->arr[i],str, idx+1);
        }
    int is_prefix(Trie* &trie,string &str, int idx= 0)
        {
            int sum = 0; 
            if(idx>=str.size())
                return 0;
            int i = str[idx]-'a';
            
            if(!trie->arr[i])
                return 0;
            sum += trie->arr[i]->cnt;
            return sum+is_prefix(trie->arr[i],str, idx+1);
        }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(int i = 0; i< words.size(); i++)
        {
            add_word(trie,words[i]);
        }
        vector<int>result(words.size(),0);
        for(int i = 0; i< words.size(); i++)
        {
            int cnt = 0; 
            
                cnt += is_prefix(trie,words[i]);
            
            result[i]= cnt;
        }return result;
        
    }
};
class Solution {
    class trie
    {
        public:
        static const int m=26;
        trie* child[m];
        int cnt=0;
       
        trie(){
            memset(child, 0, sizeof(child));
        }
        
        
        
    };
    void insert(trie* Trie, string str, int indx=0)
        {
            
            while(indx<str.size())
            {
                int cur = str[indx]-'a';
                if(Trie->child[cur] == 0)
                    Trie->child[cur] = new trie();
                Trie->child[cur]->cnt++;
                Trie= Trie->child[cur];
                indx++;
            }
                
        }
    int word_exist(trie* &Trie,string str, int indx=0)
        {
            if(indx == str.size())
                return 0;
            
            int x = 0; 
           
            trie* f = Trie;
           
            while(indx<str.size())
            {
                
                x+= f->child[str[indx]-'a']->cnt;
                f=f->child[str[indx]-'a'];
                indx++;
            }
            return x;
        }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie* Trie  = new trie();
        for(int i = 0; i< words.size(); i++)
        {
            insert(Trie, words[i]);
        }
        vector<int> ans;
        for(int i = 0; i< words.size(); i++)
        {
             
            ans.push_back(word_exist(Trie,words[i],0));

        }
        return ans;

    }
};
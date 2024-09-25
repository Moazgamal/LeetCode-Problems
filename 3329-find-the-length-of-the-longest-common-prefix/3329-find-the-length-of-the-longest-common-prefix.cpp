class Solution {
    class trie
    {
        public :
        static const int MAX_CHAR=10;
        trie* child[MAX_CHAR];
        
        trie(){
            memset(child,0,sizeof(child));
        }
        void insert(string str, int indx=0)
        {
            if(indx ==(int)str.size())
                return ;
            else
            {
                int cur = str[indx]-'0';
                if(child[cur] ==nullptr)
                    child[cur]=new trie();
                child[cur]->insert(str,indx+1);
            }
        }
        int word_exist(string str, int indx=0)
        {
            if(indx == (int)str.size())
                return indx;
            int cur= str[indx]-'0';
            if(!child[cur])
                return indx;
            return child[cur]->word_exist(str,indx+1);
        }
    };
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie* Trie = new trie();
        for(int i =0; i< arr1.size(); i++)
        {
            string s= to_string(arr1[i]);
            Trie->insert(s,0);
        }
        int ans = 0; 
        for(int i = 0; i< arr2.size(); i++)
        {
            string s = to_string(arr2[i]);
            ans = max(ans, Trie->word_exist(to_string(arr2[i])));
        }return ans;
        
    }
};
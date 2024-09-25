class trie
    {
        
         public const int m=26;
        public trie[] child;
        public int cnt=0;
       
        public trie(){
            child=new trie[26];
        }
        
        
        
    };

    




public class Solution {
    public int[] SumPrefixScores(string[] words) {


        trie Trie  = new trie();
        for(int i = 0; i< words.Length; i++)
        {
            insert(Trie, words[i]);
        }
        int[]ans = new int[words.Length];
        for(int i = 0; i< words.Length; i++)
        {
            ans[i]= (word_exist(Trie,words[i],0));

        }
        return ans;

        void insert(trie Trie, string str, int indx=0)
        {
            
            while(indx<str.Length)
            {
                int cur = str[indx]-'a';
                if(Trie.child[cur] == null)
                    Trie.child[cur] = new trie();
                Trie.child[cur].cnt++;
                Trie= Trie.child[cur];
                indx++;
            }
                
        }

        int word_exist(trie Trie,string str, int indx=0)
        {
            if(indx == str.Length)
                return 0;
            
            int x = 0; 
           
            trie f = Trie;
           
            while(indx<str.Length)
            {
                
                x+= f.child[str[indx]-'a'].cnt;
                f=f.child[str[indx]-'a'];
                indx++;
            }
            return x;
        }
        
    }
}










    
    

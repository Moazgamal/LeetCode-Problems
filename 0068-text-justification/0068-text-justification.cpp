class Solution {
    string distribute(int start, int end, int spaces, vector<string> &words, bool lastline)
    {
        int no_of_words= end-start+1;
        int places = no_of_words - 1; 
        string s  = words[start++];
        if(places == 0)
        {
            while(spaces--)
                s.push_back(' ');
            return s;
        }
        int normalspace = spaces/places;
         int specplaces = (spaces%places);
         int orgplaces = places;
         places -= specplaces;
        if(!lastline)
        {
            while(specplaces-- >0)
            {
                int ns = normalspace+1;
                while(ns--)
                    s.push_back(' ');
                s+=words[start++];
            }
            
            while(places--)
            {
                int ns = normalspace;
                while(ns--)
                    s.push_back(' ');
                s+=words[start++];
            }
        }
        else
        {
           int p = orgplaces;
           while(orgplaces--)
           {
                s.push_back(' ');
                s+=words[start++];
           }
           spaces -= p;
           while(spaces--)
                s.push_back(' ');
        }
        return s;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ans;
        bool lastline = false;
        for(int i = 0; i< words.size();)
        {
            string cur = words[i];
            int j = i+1;
            int depth = maxWidth-cur.size();
            while(j< (int)words.size())
	        {
	            int diff = words[j].size() +1;
	            if(depth-diff >= 0)
	            {
	            	j++; depth-=diff;
	            }
	            else
	            	break;
	        }
            if(j== words.size())
                lastline = true;
            int spaces = depth + (j-i-1);
            string k = distribute(i, j-1, spaces, words, lastline);
            ans.push_back(k);
            i=j;
        }
        return ans;




    }
};
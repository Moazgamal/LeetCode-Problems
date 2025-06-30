class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        if((int)words.size()==1)
            return {0}; 

        vector<int>v(words.size(),0);
        vector<int>answer(words.size(),0);
        multiset<int, greater<int>>mst;
        for(int i = 0; i< (int)words.size()-1; i++)
        {
            int j =0; int k = 0; 
            while(j< (int)words[i].size() && k<(int)words[i+1].size() && 
            words[i][j] == words[i+1][k])
            {
                j++; k++;
            }
            v[i] = j;
            mst.insert(j);
        }
        for(int i = 0; i< (int)words.size(); i++)
        {
            if(i==0)
            {
                int val = v[i];
                mst.erase(mst.find(val));
                answer[i] = *mst.begin();
                mst.insert(val);
            }
            else if(i == (int)words.size()-1)
            {
                int val = v[i-1]; mst.erase(mst.find(val));
                answer[i] = *mst.begin(); 
            }
            else
            {
                int val1 = v[i];
                int val2 = v[i-1];
                mst.erase(mst.find(val1));
                mst.erase(mst.find(val2));
                int j =0; int k = 0; 
                while(j< words[i+1].size() && k<words[i-1].size() && 
                words[i+1][j] == words[i-1][k])
                {
                    j++; k++;
                }
                mst.insert(j);
                answer[i] = *mst.begin();
                mst.erase(mst.find(j));
                mst.insert(val1);
                mst.insert(val2);
            }
        }
        return answer;
        
    }
};
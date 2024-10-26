class Solution {
    vector<int> fn(string &pat)
    {
        vector<int> longestk(pat.size(),0);
        for(int i=1, k=0; i< pat.size(); i++)
        {
            while(k>0 && pat[i] != pat[k])
            {
                k= longestk[k-1];
            }
            if(pat[k] == pat[i])
                longestk[i]=++k;
            longestk[i] =k;
        }return longestk;
    }
    vector<int> fn2(string &str, string &pat, vector<int>&longestk)
    {
        vector<int> f;
        for(int i = 0, k=0; i<str.size(); i++)
        {
            while(k>0 && pat[k] != str[i])
            {
                k= longestk[k-1];
            }
            if(pat[k] == str[i])
            {
                k++;
            }
            if(k==pat.size())
            {
                f.push_back(i-pat.size()+1);
                k=longestk[k-1];
            }
        }return f;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> va = fn(a);
        vector<int> vb= fn(b);
        vector<int>aa = fn2(s,a,va);
        vector<int>bb=fn2(s,b,vb);
        vector<int> result;

    // Iterate over each element in array a
    for (int i = 0; i < aa.size(); ++i) {
        // Binary search to find the range of elements in array b satisfying the condition
        int low = upper_bound(bb.begin(), bb.end(), aa[i] - k-1) - bb.begin();
        int high = upper_bound(bb.begin(), bb.end(), aa[i] + k) - bb.begin();

        if(low != bb.size() && abs(bb[low]-aa[i])<=k)
        {
            result.push_back(aa[i]);
            continue;
        }
        if(high!= bb.size() && abs(bb[high]-aa[i])<=k)
        {
            result.push_back(aa[i]);
            continue;
        }
       
        }
    

    return result;
        
    }
};
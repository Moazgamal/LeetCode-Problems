class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int ans = 0; 
        vector<int>res(A.size());
        for(int i = 0; i< A.size(); i++)
        {
            if(A[i] == B[i])
            {
                res[i] = ++ans;

            }
            else
            {
                mp1[A[i]]++;
                mp2[B[i]]++;
                if(mp1.count(B[i]) >0)
                {
                    ans++;
                }
                if(mp2.count(A[i])> 0)
                {
                    ans++;
                }
                res[i] = ans;
            }
        }
        return res;

    }
};
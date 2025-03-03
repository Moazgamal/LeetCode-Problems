class Solution {
public:
    vector<vector<vector<int>>>dp;
    int mini(char &a,char &b){
        int diff=abs(a-b);
        return min(diff,26-diff);
    }
    int solve(int i,int j,string &s,int k){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=max(solve(i+1,j,s,k),solve(i,j-1,s,k));
        int c=mini(s[i],s[j]);
        if(c<=k){
            ans=max(ans,2+solve(i+1,j-1,s,k-c));
        }
        return dp[i][j][k]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        dp.resize(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(0,s.size()-1,s,k);
    }
};
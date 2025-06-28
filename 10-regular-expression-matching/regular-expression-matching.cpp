class Solution {
public:
    int l1,l2;
    vector<vector<int>> dp;
    bool solve(string s,string p,int n,int m){
        if(n==l1 && m==l2)return true;
        if(n!=l1 && m==l2)return false;
        if(dp[n][m]!=-1)return dp[n][m];
        if(n==l1 && m!=l2){
            if(m+1<l2 && p[m+1]=='*')return dp[n][m+2]=solve(s,p,n,m+2);
            return false;
        }

        if(m+1<l2 && p[m+1]=='*'){
            bool coming = (p[m]=='.'|| p[m]==s[n])?solve(s,p,n+1,m):false;
            
            bool notComing = solve(s,p,n,m+2);
            dp[n][m+2]=notComing;
            return dp[n][m]=(coming || notComing);
        }

        if(p[m]=='.'){
            return dp[n+1][m+1]=solve(s,p,n+1,m+1);
        }

        if(p[m]==s[n])return dp[n+1][m+1]=solve(s,p,n+1,m+1);
        return dp[n][m]=false;
    }

    bool isMatch(string s, string p) {
        l1=s.length();
        l2=p.length();
        dp = vector<vector<int>> (l1+1,vector<int>(l2+1,-1));
        return solve(s,p,0,0);
    }
};
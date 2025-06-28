class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s,string &p,int n,int m){

        // base cases
        
        if(n==s.length() && m==p.length())return true;

        if(n!=s.length() && m==p.length())return false;

        if(dp[n][m]!=-1)return dp[n][m];

        if(n==s.length() && m!=p.length()){
            if(p[m]!='*')return false;
            else 
            {
                return dp[n][m+1]=solve(s,p,n,m+1);
            }
        }

        //

        if(p[m]=='?'){
            return dp[n+1][m+1]=solve(s,p,n+1,m+1);
        }

        if(p[m]=='*'){
            bool consume = solve(s,p,n+1,m);
            dp[n+1][m]=consume;
            bool notConsume = solve(s,p,n,m+1);
            dp[n][m+1]=notConsume;

            return consume||notConsume;
        }

        if(s[n]!=p[m])return dp[n][m]=false;
        return dp[n+1][m+1]=solve(s,p,n+1,m+1);


    }
     
    bool isMatch(string s, string p) {
        dp =vector<vector<int>> (s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,0,0);
    }
};
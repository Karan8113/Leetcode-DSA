class Solution {
public:
    int m,n;
    
    int solve(int i,int j,int k,vector<vector<int>>& coins,vector<vector<vector<int>>> &dp){
        if(i<0 || i>m-1 || j<0 || j>n-1)return INT_MIN;
        if(dp[i][j][k]!=INT_MIN)return dp[i][j][k];
        if(i==m-1 && j==n-1){
            int c=coins[i][j];
            if(c>=0)dp[i][j][k]=c;
            else{
                if(k>0)dp[i][j][k]=0;
                else{
                    dp[i][j][k]=c;
                }
            }
            return dp[i][j][k];
        }
        int c=coins[i][j];
        int down=solve(i+1,j,k,coins,dp);
        int right=solve(i,j+1,k,coins,dp);
        int best=max(down,right);
        if(c>=0){
            dp[i][j][k]=c+best;
        }
        else{
            int pay=c+best;
            int skip=INT_MIN;
            if(k>0){
                int d=solve(i+1,j,k-1,coins,dp);
                int r=solve(i,j+1,k-1,coins,dp);
                skip=max(d,r);
            }
           
            dp[i][j][k]=max(pay,skip);
        }
        return dp[i][j][k];
    }
    int maximumAmount(vector<vector<int>>& coins) {
        
        m=coins.size();
        n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return solve(0,0,2,coins,dp);
    }
};
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int k,int n){
        if(k==1 || n==0 || n==1)return n;

        if(dp[k][n]!=-1)return dp[k][n];
        int ans=INT_MAX;
        int low=1,high = n;
        while(low<=high){
            int mid = (low+high)/2;
            int breaked = solve(k-1,mid-1);
            int noBreak = solve(k,n-mid);

            int tempAns = 1 + max(breaked,noBreak);

            if(breaked>noBreak)high=mid-1;
            else low=mid+1;

            ans = min(tempAns,ans);
        }
        return dp[k][n]=ans;
    }

    int superEggDrop(int k, int n) {
        dp = vector<vector<int>> (k+1,vector<int>(n+1,-1));
        return solve(k,n);
    }
};
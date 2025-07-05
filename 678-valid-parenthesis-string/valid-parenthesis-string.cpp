class Solution {
public:
int n;
    vector<vector<int>> dp;
    bool solve(string &s,int idx,int count){
        if(idx==n){
            if(count==0)return true;
            return false;
        }
        if(count<0 )return false;

        if(dp[idx][count]!=-1)return dp[idx][count];

        bool ans;
        if(s[idx]=='(')
        ans = solve(s,idx+1,count+1);
        

        if(s[idx]==')')
        ans = solve(s,idx+1,count-1);

        if(s[idx]=='*'){
            bool first = solve(s,idx+1,count+1);
            
            bool sec=solve(s,idx+1,count-1);
            
            bool third=solve(s,idx+1,count);
           

            ans= first || sec;
            ans = ans || third;
        }

        return dp[idx][count]=ans;
    }

    bool checkValidString(string s) {
        n=s.length();
        dp= vector<vector<int>> (n+1,vector<int>(n+1,-1));
        return solve(s,0,0);
    }
};
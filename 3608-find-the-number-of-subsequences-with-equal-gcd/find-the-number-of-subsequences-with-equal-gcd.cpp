class Solution {
public:

    const int modd =1e9+7;
    int t[201][201][201];

    int solve(int i,int n,vector<int>&nums,int gcd1,int gcd2){
        if(i==n){
            if((gcd1==gcd2)&&(gcd1!=0))return 1;
            else{
                return 0;
            }
        }

        if(t[i][gcd1][gcd2]!=-1)return t[i][gcd1][gcd2];

        int skip = solve(i+1,n,nums,gcd1,gcd2);
        int take1 = solve(i+1,n,nums,__gcd(gcd1,nums[i]),gcd2);
        int take2 = solve(i+1,n,nums,gcd1,__gcd(gcd2,nums[i]));

        return t[i][gcd1][gcd2]=(0LL + skip +take1 +take2)%modd;

    }
    int subsequencePairCount(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return solve(0,n,nums,0,0);
    }
};
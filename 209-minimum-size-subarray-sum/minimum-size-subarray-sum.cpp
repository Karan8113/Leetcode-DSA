class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();
        vector<int> prefix(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=target)return 1;
            sum+=nums[i];
            prefix[i]=sum;
        }

        int i=0,j=1;
        int ans=n+1;
        while(j<n){
            if(i==0){
                if(prefix[j]>=target){
                    ans=min(ans,j-i+1);
                    i++;

                }else{
                    j++;
                }
            }
            else{
                if(prefix[j]-prefix[i-1]>=target){
                    ans=min(ans,j-i+1);
                    i++;
                }
                else{
                    j++;
                }
            }
        }

        return ans==n+1?0:ans;

        
    }
};
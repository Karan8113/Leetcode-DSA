class Solution {
public:

    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=0;
        int maxAns=0;

        vector<int> prefix(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
        }

        if(n==1)return prefix[0];

        for(int i=0;i<n-1;i++){
            int count=1;
            start=i;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]<nums[j]){
                    end=j;
                }
                else{
                    break;

                }
            }

            if(start==0 && maxAns<prefix[end]){
                maxAns=prefix[end];
            }
            else if(maxAns<prefix[end]-prefix[start-1]){
                maxAns=prefix[end]-prefix[start-1];
            }

           
        }

        return maxAns;
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        int ans=0;
        int pre=0;
        for(int i=0;i<n;i++){
            if(i==0 && nums[i]>0){
                pre=nums[0];
            }
            else{
                pre=pre+nums[i];

            }

            if(pre<0){
                prefix[i]=0;
                pre=0;
            }
            else{
                prefix[i]=pre;
                ans=max(ans,pre);
            }

        }
     

        prefix[0]=nums[0];
        pre=0;


        for(int i=0;i<n;i++){
            nums[i]=nums[i]*-1;
        }
        for(int i=0;i<n;i++){
            if(i==0 && nums[i]>0){
                pre=nums[0];
            }
            else{
                pre=pre+nums[i];

            }

            if(pre<0){
                prefix[i]=0;
                pre=0;
            }
            else{
                prefix[i]=pre;
                ans=max(ans,pre);
            }

        }
     

        return ans;
        
    }
};
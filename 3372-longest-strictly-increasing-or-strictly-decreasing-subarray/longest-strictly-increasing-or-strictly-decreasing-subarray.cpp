class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int Maxcount=1;
        for(int i=0;i<n-1;i++){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]<nums[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            Maxcount=max(Maxcount,count);
        }

        for(int i=0;i<n-1;i++){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]>nums[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            Maxcount=max(Maxcount,count);
        }
        return Maxcount;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=nums[0],minProduct=nums[0],result=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(maxProduct,minProduct);

            maxProduct=max(nums[i],nums[i]*maxProduct);
            minProduct=min(nums[i],nums[i]*minProduct);

            result = max(result,maxProduct);
        }

        return result;
    }
};
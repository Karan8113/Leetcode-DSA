class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[maxi])maxi=i;
            else if(nums[i]==nums[maxi] && nums[(i+1)%n]<nums[i]){
                maxi=i;
            }
        }

        int j=(maxi+1)%n;
        int count=n-1;
        while(count--){
            if(nums[j%n]>nums[(j+1)%n])return false;
            j++;
        }
        return true;


        
    }
};
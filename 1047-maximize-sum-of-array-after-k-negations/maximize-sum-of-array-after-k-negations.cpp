class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int neg=0,zero=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)neg++;
            if(nums[i]==0)zero=1;
        }

        int i=0;

        while(i<neg && k>0){
            nums[i]*=-1;
            i++,k--;
        }
        int sum;
        if(zero){
            sum = accumulate(nums.begin(),nums.end(),0);
            return sum;
        }
        
        sort(nums.begin(),nums.end());
   
        while(k>0){
            nums[0]*=-1;
            k--;
        }
        
        sum = accumulate(nums.begin(),nums.end(),0);
        return sum;

    }
};
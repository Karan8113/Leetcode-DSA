class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int minEl=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curSum=digitSum(nums[i]);
            if(curSum<minEl){
                minEl=curSum;
            }
          //  cout<<curSum<<" "<<minEl<<endl;
        }
        return minEl;
    }
};
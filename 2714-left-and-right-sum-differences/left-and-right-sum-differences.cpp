class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        int totalSum = accumulate(nums.begin(),nums.end(),0);

        int leftSum=0;
        for(auto &it:nums){
            int rightSum= totalSum-(leftSum+it);
            res.push_back(abs(leftSum-rightSum));
            leftSum+=it;
        }
        return res;
    }
};
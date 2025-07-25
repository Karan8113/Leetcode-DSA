class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int maxEl = *max_element(nums.begin(),nums.end());
        int maxx=0;
        if(maxEl<0)return maxEl;

        unordered_set<int> st;

        for(auto it:nums){
            cout<<st.count(it)<<"  ";
            if(!st.count(it) && it>0){
                maxx+=it;
                st.insert(it);
            }
        }

        return maxx;
    }
};
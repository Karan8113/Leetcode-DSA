class Solution {
public:


    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={i,nums[i]};
        }

        sort(v.begin(),v.end(),[](pair<int,int> &p1,pair<int,int> &p2){
            return p1.second>p2.second;
        });

        sort(v.begin(),v.begin()+k);

        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=v[i].second;
        }
        return ans;
    }
};
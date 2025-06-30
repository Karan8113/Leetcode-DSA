class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        int res=0;

        for(auto it:mp){
            int num=it.first;

            if(mp.count(num+1)){
                int curAns=mp[num]+mp[num+1];
                res=max(res,curAns);
            }
        }
        return res;
    }
};
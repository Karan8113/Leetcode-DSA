class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }

        for(auto it:mp){
            if(it.second==2){
                count+=8;
            }
            else if(it.second>2){

                int x=((it.second-1)*(it.second))/2;
                count+=(x*8);
            }
        }
        return count;
    }
};
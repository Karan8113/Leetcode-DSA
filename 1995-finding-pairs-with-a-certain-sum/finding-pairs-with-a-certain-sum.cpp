class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    int n;
    unordered_map<int,int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(auto it:nums2){
            mp[it]++;
        }

    }
    
    void add(int index, int val) {
        int oldValue=nums2[index];
        nums2[index]=nums2[index]+val;
        mp[oldValue]--;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it:nums1){
            ans+=mp[tot-it];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
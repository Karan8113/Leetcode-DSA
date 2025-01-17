class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr=derived[0];
        int n=derived.size();

        for(int i=1;i<=n-1;i++){
            xorr^=derived[i];
        }

        return xorr==0?true:false;
    }
};
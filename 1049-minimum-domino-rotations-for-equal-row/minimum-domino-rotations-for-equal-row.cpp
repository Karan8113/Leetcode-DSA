class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;

        unordered_map<int,int> top;
        unordered_map<int,int> bottom;


        for(int i=0;i<n;i++){
            top[tops[i]]++;
            bottom[bottoms[i]]++;
        }

        for(int i=1;i<=6;i++){
            int isPossible=1;
            int swap=n;
            for(int j=0;j<n;j++){
                if(tops[j]==i || bottoms[j]==i){
                    continue;
                }
                else{
                    isPossible=0;
                    break;
                }
            }
            if(isPossible==1){
                int occurence=max(top[i],bottom[i]);
                swap=min(swap,n-occurence);
                ans=min(ans,swap);
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};
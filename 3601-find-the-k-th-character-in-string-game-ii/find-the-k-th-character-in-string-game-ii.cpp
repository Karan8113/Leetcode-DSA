class Solution {
public:

    char solve(long long k,int idx,int shift,vector<int>& operations){
        if(idx<0)return 'a'+(shift)%26;
        char ans;
        long long x=pow(2,idx+1)/2;
        if(k>x){
            if(operations[idx]==1)shift++;
            ans=solve(k-x,idx-1,shift,operations);
        }
        else{
            ans=solve(k,idx-1,shift,operations);
        }
        return ans;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        int n=operations.size();

        int i=0;
        while(k>pow(2,i+1)){
            i++;
        }
        
        return solve(k,i,0,operations);
    }
};
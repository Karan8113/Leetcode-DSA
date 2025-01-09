class Solution {
public:
    int maxScore(string s) {
        int len=s.length();
        int left=0,right=0,maxSc=0;

        for(int i=0;i<len;i++){
            if(s[i]=='1')right++;
        }

        for(int i=0;i<len-1;i++){
            if(s[i]=='0')left++;
            else if(s[i]=='1')right--;

            maxSc=max(maxSc,left+right);
        }
        return maxSc;
    }
};
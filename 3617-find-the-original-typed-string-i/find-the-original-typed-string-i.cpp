class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> v(26,0);

        int n=word.length();
        int len=0;
        for(int i=0;i<n-1;i++){
            if(word[i]!=word[i+1])len++;
        }
        len+=1;

        return 1+(n-len);

    }
};
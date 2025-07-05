class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int min=0,maxx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++,maxx++;
            }
            else if(s[i]==')'){
                min=max(0,min-1);
                maxx--;
            }
            else{
                min=max(0,min-1);
                maxx++;
            }
            if(maxx<0)return false;
        }

        return min==0;
    }
};
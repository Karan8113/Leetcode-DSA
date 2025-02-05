class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n!=m)return false;

        vector<int> v(26,0);

        for(auto it:s1){
            v[it-'a']++;
        }

        for(auto it:s2){
            v[it-'a']--;
        }

        for(auto it:v){
            if(it!=0)return false;
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])count++;
        }

        if(count>2)return false;
        return true;
    }
};
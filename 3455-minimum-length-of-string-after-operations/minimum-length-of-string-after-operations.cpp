class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26,0);
        int n=s.length();
        int removed=0;
        for(char c:s){
            v[c-'a']++;
            
            if(v[c-'a']==3){
                v[c-'a']-=2;
                removed+=2;
            }
            
        }
        return n-removed;
        
        
        
    }
};
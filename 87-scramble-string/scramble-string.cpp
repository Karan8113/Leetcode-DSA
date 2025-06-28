class Solution {
public:
    unordered_map<string,bool> mp;

    bool solve(string s1,string s2){
        if(s1==s2)return true;
        if(s1.length()<=1)return false;

        string key = s1+"  "+s2;
        if(mp.find(key)!=mp.end())return mp[key];

        int n=s1.length();

        for(int i=1;i<n;i++){
            bool case1 = (solve(s1.substr(0,i),s2.substr(n-i))&&solve(s1.substr(i),s2.substr(0,n-i)));

            bool case2 = (solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i),s2.substr(i)));

            if(case1 || case2)return mp[key]=true;
        }

        return mp[key]=false;
        

    }

    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())return false;
        return solve(s1,s2);
    }
};
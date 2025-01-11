class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(k>n)return false;
        unordered_map<char,int> mp;

        for(char ch:s)mp[ch]++;

        int odd=0,even=0;
        for(auto it:mp){
           even+=it.second/2;
           odd+=it.second%2;
        }

        return odd<=k;
        

        

    }
};
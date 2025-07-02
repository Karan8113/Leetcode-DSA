#define ll long long
class Solution {
public:
    ll md = 1e9 + 7;
    int possibleStringCount(string word, int k) {
        int  n = word.size();
        int cnt = 1, total = 1;
        vector<int> seg;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                cnt++;
            }
            else{
                total = ((ll) total * cnt)%md;
                seg.push_back(cnt-1);
                cnt = 1;
            }
        }
        //add the last segment
        total = ((ll) total * cnt)%md;
        seg.push_back(cnt-1);
        
        int mnlen = seg.size();
        if(k<=mnlen) return total;

        k-=mnlen;

        vector<ll> dp(k); dp[0] = 1;
        //go thru seg
        for(int x : seg){
            vector<ll> pref(k); pref[0] = dp[0];
            for(int i=1;i<k;i++){
                pref[i] = (pref[i-1] + dp[i])%md; 
            }
            for(int i=0;i<k;i++){
                // naively i could have run another loop for the summation
                // taking : 0, 1, 2 .... x elements
                if(i-x-1>=0) dp[i] = (pref[i] - pref[i-x-1] + md)%md; // sum : dp[i] + dp[i-1] + .. + dp[i-x] 
                else dp[i] = pref[i] ;
            }
        }
        //O(n + k^2 + k)
        int invalid = 0;
        for(int x : dp) invalid = (invalid + x)%md;
        // >= k  => total - (<k) 
        return (total - invalid + md)%md;
    }
};
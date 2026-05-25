class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n=s.length();

        vector<int> visited(n,0);

        q.push(0);
        visited[0]=1;
        int farthest=0;
        while(!q.empty()){
            int curIndex = q.front();
            q.pop();
            int start = max(curIndex+minJump,farthest);
            int end= min(curIndex+maxJump,n-1);

            for(int i=start;i<=end;i++){
                if(i==n-1 && s[i]=='0')return true;
                if(visited[i]==0 && s[i]=='0'){
                    q.push(i);
                    visited[i]=1;
                }
            }
            farthest = end+1;
        }

        return false;
    }
};
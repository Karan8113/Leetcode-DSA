class Solution {
public:

    vector<int> topologicalSort(unordered_map<int,vector<int>> mp,int n,vector<int> &inDeg){
        queue<int> q;
        int count=0;

        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
                count++;
            }
        }

        vector<int> ans(n,0);
        int it=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ans[it]=v;
            it++;
            for(auto ele:mp[v]){
                inDeg[ele]--;
                if(inDeg[ele]==0){
                    q.push(ele);
                    count++;
                }
            }
        }

        vector<int> empty;
       return count==n?ans:empty;

        

    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> inDeg(n,0);
        int len=prerequisites.size();
        vector<int> res(n,0);
        if(len==0){
            for(int i=0;i<n;i++){
                res[i]=i;
            }
        }

        for(int i=0;i<len;i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDeg[prerequisites[i][0]]++;
        }

        return topologicalSort(mp,n,inDeg);

    }
};
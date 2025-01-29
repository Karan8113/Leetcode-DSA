class Solution {
public:

    bool dfs(unordered_map<int,vector<int>> &mp,int u,int v,vector<bool>&visited){
        visited[u]=true;
        if(u==v)return true;

        for(auto it:mp[u]){
            if(!visited[it]){
                if(dfs(mp,it,v,visited))return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        unordered_map<int,vector<int>> mp;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

           vector<bool> visited(n,false);

            if(mp.find(u)!=mp.end() && mp.find(v)!=mp.end() && dfs(mp,u,v,visited)){
                return edge;
            }

            mp[v].push_back(u);
            mp[u].push_back(v);
        }

        return {};
    }
};
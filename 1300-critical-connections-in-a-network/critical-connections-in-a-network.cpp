class Solution {
public:

    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int>&level,vector<int>&low,vector<bool>&visited,vector<vector<int>>&bridges,int count){
        visited[node]=true;
        level[node]=low[node]=count;

        for(int i=0;i<adj[node].size();i++){
            int neib=adj[node][i];

            if(parent==neib)continue;
            else if(visited[neib]){
                low[node]=min(low[node],low[neib]);
            }
            else{
                count++;
                dfs(neib,node,adj,level,low,visited,bridges,count);
                low[node]=min(low[node],low[neib]);
                if(low[neib]>level[node]){
                    bridges.push_back({node,neib});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,0);
        vector<int>level(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

         dfs(0,-1,adj,level,low,visited,bridges,0);

        return bridges;
    }
};
class Solution {
public:

    int find(int u,vector<int>&parent){
        if(u==parent[u])return u;
        return parent[u]=find(parent[u],parent);
    }

    void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
        int u_parent=find(u,parent);
        int v_parent=find(v,parent);

        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }
        else if(rank[u_parent]<rank[v_parent]){
            parent[u_parent]=v_parent;
        }
        else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        // vector<pair<int,int>> adj[n];
        vector<pair<int,pair<int,int>>> v;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                // adj[i].push_back({j,cost});
                v.push_back({cost,{i,j}});
            }
        }

        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++)parent[i]=i;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq(v.begin(), v.end());
        int count=0;
        int cost=0;
        while(!pq.empty()){
            int c=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();

            if(find(u,parent)!=find(v,parent)){
                unionn(u,v,parent,rank);
                count++;
                cost+=c;
                if(count==n-1)break;
            }
        }

        return cost;


    }
};

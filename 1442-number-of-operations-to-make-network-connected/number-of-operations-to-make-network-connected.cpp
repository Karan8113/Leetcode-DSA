class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x==y)return;

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        if(size<n-1)return -1;

        parent.resize(n);
        rank.resize(n,1);

        for(int i=0;i<n;i++)parent[i]=i;

        int count=0;

        for(auto &edge:connections){
            int u =edge[0];
            int v=edge[1];

            int u_parent=find(u);
            int v_parent=find(v);

            if(u_parent!=v_parent){
                Union(u,v);
                count++; 
            }

        }


        return n-count-1;
    }
};
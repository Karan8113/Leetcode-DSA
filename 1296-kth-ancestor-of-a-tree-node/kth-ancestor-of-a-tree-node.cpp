class TreeAncestor {
public:
    //int n;
    //vector<int> parent;
    vector<vector<int>> up;
    TreeAncestor(int n, vector<int>& parent) {
       // this->n=n;
        //this->parent=parent;

        int Log=0;
        while((1<<Log)<=n){
            Log++;
        }
        up.resize(n+1,vector<int>(Log+1,-1));

        for(int i=0;i<parent.size();i++){
            up[i][0]=parent[i];
        }

        for(int k=1;k<Log+1;k++){
            for(int node=0;node<n;node++){
                int temp=up[node][k-1];
                if(temp==-1){
                    up[node][k]=-1;
                }
                else{
                    up[node][k]=up[temp][k-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {

    
        
        int bitPos=0;
        while(k){
            int bit=k%2;
            k=k/2;
            if(bit==1){
                node = up[node][bitPos];
                if(node==-1)return -1;
            }
            
        
            bitPos++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
class Solution {
public:
    int r,c;
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,int &count){
        if(row<0 || col<0 || row>=r || col>=c || visited[row][col]!=0 || grid[row][col]==0)return;
        
        visited[row][col]=1;
        count+=grid[row][col];

        dfs(row,col+1,grid,visited,count);
        dfs(row,col-1,grid,visited,count);
        dfs(row+1,col,grid,visited,count);
        dfs(row-1,col,grid,visited,count);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        int maxFish=0;

        vector<vector<int>> visited(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    int count=0;
                    dfs(i,j,grid,visited,count);
                    maxFish=max(maxFish,count);
                }
            }
        }
        return maxFish;
    }
};
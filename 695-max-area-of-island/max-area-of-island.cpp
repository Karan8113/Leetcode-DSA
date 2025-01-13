class Solution {
public:
    int row,col;
    void DFS(int r,int c,vector<vector<int>> &grid,int &count){
        if(r<0  || r>=row || c<0 || c>=col || grid[r][c]==0){
            return;
        }

        grid[r][c]=0;
        count++;

        DFS(r+1,c,grid,count);
        DFS(r-1,c,grid,count);
        DFS(r,c+1,grid,count);
        DFS(r,c-1,grid,count);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int count=0;
        int maxArea=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int area=0;
                    DFS(i,j,grid,area);
                    maxArea=max(maxArea,area);
                    count++;
                }
            }
        }

        return count==0?0:maxArea;
        
    }
};
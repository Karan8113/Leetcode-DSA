class Solution {
public:
    int row,col;

    void DFS(int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(r<0 || r>=row || c<0 || c>=col || grid1[r][c]!=1 || grid2[r][c]!=1 )return;

        grid1[r][c]=-1;
        grid2[r][c]=-1;

        DFS(r+1,c,grid1,grid2);
        DFS(r-1,c,grid1,grid2);
        DFS(r,c+1,grid1,grid2);
        DFS(r,c-1,grid1,grid2);
    }

    void DFS2(int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(r<0 || r>=row || c<0 || c>=col || grid2[r][c]==0)return;
        grid2[r][c]=0;

        DFS2(r+1,c,grid1,grid2);
        DFS2(r-1,c,grid1,grid2);
        DFS2(r,c+1,grid1,grid2);
        DFS2(r,c-1,grid1,grid2);
    }

    void DFS3(int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(r<0 || r>=row || c<0 || c>=col || grid2[r][c]!=-1)return;
        grid2[r][c]=0;

        DFS2(r+1,c,grid1,grid2);
        DFS2(r-1,c,grid1,grid2);
        DFS2(r,c+1,grid1,grid2);
        DFS2(r,c-1,grid1,grid2);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row=grid2.size();
        col=grid2[0].size();
        int count1=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    DFS(i,j,grid1,grid2);
                }
            }
        }
        cout<<count1<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid2[i][j]==1){
                    DFS2(i,j,grid1,grid2);
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid2[i][j]==-1){
                    DFS3(i,j,grid1,grid2);
                    count1++;
                }
            }
        }

        return count1;
    }
};
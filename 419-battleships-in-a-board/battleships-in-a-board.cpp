class Solution {
public:
    int row,col;
    void DFS(int r,int c,vector<vector<char>>& board){
        if(r<0 ||r>=row || c<0 || c>=col || board[r][c]=='.'){
            return;
        }

        board[r][c]='.';
        DFS(r+1,c,board);
        DFS(r,c+1,board);
        DFS(r-1,c,board);
        DFS(r,c-1,board);
    }

    int countBattleships(vector<vector<char>>& board) {
        row=board.size();
        col=board[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='X'){
                    DFS(i,j,board);
                    count++;
                }
            }
        }

        return count;
    }
};
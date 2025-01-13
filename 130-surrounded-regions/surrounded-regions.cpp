class Solution {
public:
    int row,col;
    
    void DFS(int r,int c,vector<vector<char>>& board){
        if(r<0 || r>=row || c<0|| c>=col || board[r][c]!='O'){
            return;
        }

        board[r][c]='#';

        DFS(r+1,c,board);
        DFS(r-1,c,board);
        DFS(r,c+1,board);
        DFS(r,c-1,board);
    }

    void solve(vector<vector<char>>& board) {
        row=board.size();
        col=board[0].size();

        for(int i=0;i<row;i++){
            if(board[i][0]=='O')DFS(i,0,board);
            if(board[i][col-1]=='O')DFS(i,col-1,board);
        }

        for(int i=0;i<col;i++){
            if(board[0][i]=='O')DFS(0,i,board);
            if(board[row-1][i]=='O')DFS(row-1,i,board);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                   board[i][j]='X';
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='#'){
                   board[i][j]='O';
                }
            }
        }
    }
};
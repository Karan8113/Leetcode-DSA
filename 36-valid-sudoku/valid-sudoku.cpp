class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='.') mp[board[i][j]]=0;
                else mp[board[i][j]]++;
                
                if(mp[board[i][j]]>1) return false;
            }
            mp.clear();
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[j][i]=='.') mp[board[j][i]]=0;
                else mp[board[j][i]]++;
                
                if(mp[board[j][i]]>1) return false;
            }
            mp.clear();
        }
        
        for(int count=0;count<9;count++){
            int startRow=((count*3)/9)*3;
            int endRow=startRow+3;
            
            int startCol=(count*3)%9;
            int endCol =startCol+3;
            
            for(int i=startRow;i<endRow;i++){
                for(int j=startCol;j<endCol;j++){
                    if(board[i][j]=='.') mp[board[i][j]]=0;
                    else mp[board[i][j]]++;

                    if(mp[board[i][j]]>1) return false;
                }
                
            }
            mp.clear();
        }
        
        return true;
        
    }
};
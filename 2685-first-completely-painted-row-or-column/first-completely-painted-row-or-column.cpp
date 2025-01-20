class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();

        vector<int> colVisit(col,0);
        vector<int> rowVisit(row,0);

        unordered_map<int,pair<int,int>> mp;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        int len=arr.size();
        int curRow,curCol;
        for(int i=0;i<len;i++){
            curRow=mp[arr[i]].first;
            curCol=mp[arr[i]].second;
            rowVisit[curRow]++;
            if(rowVisit[curRow]==col)return i;
            colVisit[curCol]++;
            if(colVisit[curCol]==row)return i;
        }
        return 0;
        
    }
};
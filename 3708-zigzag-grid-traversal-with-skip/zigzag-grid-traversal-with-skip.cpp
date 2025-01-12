class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> ans;
        int itr=row*col;
        int count=0;
        int r,c;
        while(count<itr){
            r=count/col;
            c=count%col;
            if(r%2==0){
                ans.push_back(grid[r][c]);
            }
            else{
                ans.push_back(grid[r][col-1-c]);
            }
            count+=2;
        }
        return ans;
    }
};
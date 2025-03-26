class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r=grid.size();
        int c=grid[0].size();
        vector<int> v;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<grid[i][j]<<"  ";
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(),v.end());

        int newSize= v.size();
        int mid=floor(newSize/2);
        int midEl = v[mid];
        int count=0;
        int diff=0;
        for(auto it:v){
            if(abs(it-midEl)%x!=0)return -1;
            else{
                diff=abs(it-midEl);
                count+=((diff)/x);
            }
        }

        return count;
    }
};
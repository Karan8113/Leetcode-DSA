class Solution {
public:
    int m,n;
    bool isValid(int r,int c){
        if(r<0 || r>=m || c<0 || c>=n){
            return false;
        }
        return true;
    }
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        unordered_map<int,pair<int,int>> mp;
        mp[1]={0,1};
        mp[2]={0,-1};
        mp[3]={1,0};
        mp[4]={-1,0};

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        

        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        vector<vector<int>> visited(m,vector<int>(n,0));
        cost[0][0]=0;
        int curRow,curCol,curCost;
        int newCost;
        while(!pq.empty()){
           
            curCost=pq.top().first;
            curRow=pq.top().second.first;
            curCol=pq.top().second.second;

             pq.pop();
            

            if(visited[curRow][curCol]==0){
                for(int i=1;i<=4;i++){
                    int first=mp[i].first;
                    int sec=mp[i].second;

                    if(isValid(curRow+first,curCol+sec)){
                        if(i==grid[curRow][curCol]){
                            newCost=curCost;
                        }
                        else{
                            newCost = curCost + 1;
                        }
                        if(cost[curRow+first][curCol+sec]>newCost){
                            cout<<curRow+first<<"  "<<curCol+sec<<"  "<<newCost<<endl;
                            cost[curRow+first][curCol+sec]=newCost;
                            pq.push({newCost,{curRow+first,curCol+sec}});
                        }                    
                    }
                    
                    
                }

            }
            visited[curRow][curCol]=1;
        }

       
        return cost[m-1][n-1];
    }
};
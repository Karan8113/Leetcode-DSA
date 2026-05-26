class Solution {
public:

    int solve(vector<int>&arr,int curIndex,int &d,int &n,vector<int> &visited){
        if(visited[curIndex]!=-1)return visited[curIndex];
        int res=1;
        for(int i=curIndex-1;i>=max(0,curIndex-d);i--){
            if(arr[curIndex]<=arr[i])break;
            res=max(res,1+solve(arr,i,d,n,visited));
        }

        for(int i=curIndex+1;i<=min(n-1,curIndex+d);i++){
            if(arr[curIndex]<=arr[i])break;
            res=max(res,1+solve(arr,i,d,n,visited));
        }

        return visited[curIndex]=res;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> visited(n,-1);
        int result = 0;
        for(int i=0;i<n;i++){
            result = max(result,solve(arr,i,d,n,visited));
        }
        return result;
    }
};
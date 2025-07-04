class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> v(n);

        for(int i=0;i<n;i++){
            v[i]={points[i][1],points[i][0]};
        }

        sort(v.begin(),v.end(),[](pair<int,int>f,pair<int,int>s){
            return f.first<s.first;
        });

        int count=0;
        int curEnd=INT_MIN;
        int curStart=INT_MIN;

        if(v[0].second==INT_MIN){
            count++;
            curStart=v[0].second;
            curEnd=v[0].first;
        }

        for(int i=0;i<n;i++){
            
            if(curEnd>=v[i].second){
                curStart=min(curStart,v[i].second);
                curEnd=min(curEnd,v[i].first);
            }else{
                count++;
                curStart=v[i].second;
                curEnd=v[i].first;
            }
        }
        return count;
    }
};
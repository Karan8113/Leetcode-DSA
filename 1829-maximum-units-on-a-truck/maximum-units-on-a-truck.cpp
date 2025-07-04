class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({boxTypes[i][1],boxTypes[i][0]});
        }

        sort(v.begin(),v.end(),[](pair<int,int>f,pair<int,int>s){
            return f.first>s.first;
        });

        int i=0;
        
        int ans=0;

        while(i<n && truckSize){
            if(v[i].second<truckSize){
                ans+=(v[i].second*v[i].first);
                truckSize-=v[i].second;
                
            }
            else{
                ans+=(v[i].first*truckSize);
                truckSize=0;
            }
            i++;
        }

        return ans;


    }   
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(make_pair(arr[i],i));
        }
        
        pair<int,int> pa;
        int count=1;
        while(!pq.empty()){
            pa=pq.top();
            arr[pa.second]=count;
            pq.pop();
            
            if(!pq.empty() && pq.top().first==pa.first){
                continue;
            }
            else{
                count++;
            }
            
        }
        
        return arr;
    }
};
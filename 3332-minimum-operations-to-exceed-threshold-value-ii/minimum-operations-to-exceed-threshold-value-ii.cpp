class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        for(auto it:nums){
            pq.push(it);
        }
        long long x,y;
        int count=0;
        while(pq.size()>=2){
           x= pq.top();
           pq.pop();
           if(x>=k)break;
        

            y=pq.top();
            pq.pop();
            
                
   
           
           x=static_cast<long long>(min(x,y)*2+max(x,y));
           pq.push(x);
          
           
           count++;
        }
        return count;
    }
    
};
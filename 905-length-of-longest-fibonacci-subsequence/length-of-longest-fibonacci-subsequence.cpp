class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> mp;
        int len=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<len;i++){
            mp[arr[i]]=i;
        }

        
        int maxC=0;
        int temp;

        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int count=0;
                int k=j;
                int l=i;
                while(mp.find(arr[l]+arr[k])!=mp.end()){
                    // cout<<arr[l]<<"  "<<arr[k]<<"  "<<arr[l]+arr[k]<<endl;
                    count++;
                    temp=k;
                    k=mp[arr[l]+arr[k]];
                    l=temp;
                }
                maxC=max(maxC,count);
            }
        }

        return maxC==0?0:maxC+2;
        
    }
};
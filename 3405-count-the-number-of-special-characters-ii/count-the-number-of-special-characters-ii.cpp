class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int> visited(26,0);
        int count=0;
        for(auto it:word){
            if(islower(it)){
                if(visited[it-'a']==0)visited[it-'a']=1;
                else if(visited[it-'a']==-1)continue;
                if(visited[it-'a']==2){
                    visited[it-'a']=-1;
                    count--;
                }
            }
            else{
                if(visited[it-'A']==-1)continue;
                else if(visited[it-'A']==0){
                    visited[it-'A']=-1;
                  
                }
                else if(visited[it-'A']==1){
                    visited[it-'A']=2;
                    count++;
                }
            }
           // cout<<it<<"  "<<count<<endl;  
        }
        return count;

    }
};
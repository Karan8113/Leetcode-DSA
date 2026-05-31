class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto it:asteroids){
            if((long long)it>sum)return false;
            sum+=it;
        }
        return true;
    }
};
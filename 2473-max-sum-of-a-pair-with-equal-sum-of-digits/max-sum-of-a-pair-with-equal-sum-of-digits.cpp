class Solution {
public:
    int getSum(int a) {
        int sum = 0;
        while (a) {
            sum += (a % 10);
            a /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1;

        for (int num : nums) {
            int digitSum = getSum(num);
            
            if (mp.find(digitSum) != mp.end()) {
                ans = max(ans, mp[digitSum] + num);
            }

            // Store the maximum value corresponding to the digit sum
            mp[digitSum] = max(mp[digitSum], num);
        }

        return ans;
    }
};

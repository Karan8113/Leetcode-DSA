class Solution {
public:

    int count(int n){
        int c=0;
        while(n){
            if(n%2!=0)c++;
            n/=2;
        }
        return c;
    }

    int minimizeXor(int num1, int num2) {
        int count2=count(num2);
         int res = 0;

        // Use the set bits of num1
        for (int i = 31; i >= 0 && count2 > 0; --i) {
            if (num1 & (1 << i)) {
                res |= (1 << i);
                count2--;
            }
        }

        // Use remaining unset bits
        for (int i = 0; i < 32 && count2 > 0; ++i) {
            if (!(num1 & (1 << i))) {
                res |= (1 << i);
                count2--;
            }
        }

        return res;
    }
};
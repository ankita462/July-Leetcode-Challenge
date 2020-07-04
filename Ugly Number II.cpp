class Solution {
public:
    int nthUglyNumber(int n) {
         int ugly[n];
        ugly[0] = 1;
        int count = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        while(count < n){
            int val2 = ugly[idx2]*2;
            int val3 = ugly[idx3]*3;
            int val5 = ugly[idx5]*5;
            int val = min({val2, val3, val5});
            if(val == val2) idx2++;
            if(val == val3) idx3++;
            if(val == val5) idx5++;
            ugly[count++] = val;
        }
        return ugly[n-1];
    }
};

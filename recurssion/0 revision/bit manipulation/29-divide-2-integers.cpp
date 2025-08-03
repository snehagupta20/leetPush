class Solution {
public:
    int divide(int divisor, int divident) {

        if(divisor == INT_MIN && divident == -1){
            return INT_MAX;
        }

        long long result = 0;

        bool isNeg = (divisor<0) ^ (divident<0);

        long long a = abs((long long)divisor);
        long long b = abs((long long)divident);

        for(int i=31; i>=0; i--){
            if((b << i) <= a){
                a -= (b << i);
                result += (1 << i);
            }
        }

        return isNeg ? -result : result;
    }
};
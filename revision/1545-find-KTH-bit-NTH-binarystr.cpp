class Solution {
public:
    char findKthBit(int n, int k) {
        //base case: if n == 1, the string is "0"
        if (n == 1) {
            return '0';
        }

        //calculate the length of S(n-1), which is 2^(n-1) - 1
        int lengthOfPrevious = pow(2, (n - 1)) - 1;

        //if k lies in the first part, recursively find it in S(n-1)
        if (k <= lengthOfPrevious) {
            return findKthBit(n - 1, k);
        }
        //if k is exactly in the middle, return '1'
        else if (k == lengthOfPrevious + 1) {
            return '1';
        }
        //if k lies in the second part, find the corresponding position in S(n-1) and invert the result
        else {
            int mirroredK = 2 * lengthOfPrevious + 2 - k; // Mirror k
            char result = findKthBit(n - 1, mirroredK);
            return result == '0' ? '1' : '0'; // Invert the bit
        }
    }
};

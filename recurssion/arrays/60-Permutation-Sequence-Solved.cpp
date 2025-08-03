class Solution {
public:
    int fact(int n){
        // base case
        if(n==0 || n==1){
            return 1;
        }

        // computational body & recursive function
        return n * fact(n-1);
    }

    void permutation(int n, int k, vector<int> &digits, string &ans){
        // base case
        if(digits.size()==1){
            ans += to_string(digits[0]);
            return;
        }

        // body computation
        int factorial = fact(n-1);
        int dig = (k)/factorial ;
        ans = ans + to_string(digits[dig]);
        digits.erase(digits.begin()+dig);
        k = k % factorial;

        // recursive function
        permutation(n-1, k, digits, ans);
        return;
    }

    string getPermutation(int n, int k) {
        // making digits vector
        vector<int> digits;
        for(int i=1;i<=n;i++){
            digits.push_back(i);
        }

        string ans = "";
        permutation(n, k-1, digits, ans);

        return ans;
    }   
};

/*
n! unique permutations

brute force
- num = exponential of n
- find all the permutation sequence of num - stored in a vector
- return vector[k-1];

mathematical approach
- make nums vector with all digit from 1,2...n
- dig 1 = k-1 / (n-1)!
= ans += dig1
remove dig1 from nums vector
- k = k % (n-1)
- repeat
*/

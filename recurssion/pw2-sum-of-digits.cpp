// Given an integer, find out the sum of its digits using recursion
// Problem 1 Given an integer, find out the sum of its digits using recursion.
// Input n= 1234
// Output 10
// Explanation 1+2+3+4=10

#include <iostream>
using namespace std;

void printSum(int n, int sum){
    if(n==0){
        cout<<sum;
        return;
    }
    int dig = n%10;
    sum+=dig;
    n=n/10;
    printSum(n,sum);
    return;
}

int main(){
    printSum(52345, 0);
    return 0;
}
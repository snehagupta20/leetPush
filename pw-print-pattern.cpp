// Q1 - Given a number n, print the following pattern without using any loop.
// n, n-5, n-10, ..., 0, 5, 10, ..., n-5, n
// There should be 0 or at most one occurrence of negative number in the series.
// Sample Input: n = 16
// Sample Output: 16, 11, 6, 1, -4, 1, 6, 11, 16
// Sample Input: n = 10
// Sample Output: 10, 5, 0, 5, 10

#include <iostream>
using namespace std;

void printPattern(int n){
    if(n<=0){
        n=+5;
        cout<<n;
    }
    n=-5;
    cout<<n;
    printPattern(n);
}

int main(){
    printPattern(16);
    return 0; 
}
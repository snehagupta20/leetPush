// Problem 7: Fibonacci Number (Using Recursion)
// 👉 Input: n = 5
// 👉 Output: 5 (since Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8...)


#include <iostream>
#include <string>
using namespace std;

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    
    return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    int n = 5;
    cout<<fibonacci(n);
    
    return 0;
}
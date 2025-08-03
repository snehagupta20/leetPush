// Problem 2 Given two numbers a & b, find the value a^b using a recursive function.
// Input a =5 , b=3
// Output 125
// Explanation (5*5*5)=125

#include <iostream>
using namespace std;

int power(int a, int b, int helper){
    if(b==0) return 1;
    helper = a*a;
    return power(a, b-1, helper);
}

int main(){
    cout<<power(5,3,1);
    return 0;
}
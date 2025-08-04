// Example 2 Write a program to check whether a given number is palindrome or not.
//  Input num = 1234321
//  Output Yes
//  Explanation: This number remains the same when digits are reversed as we know that a palindrome number is 
// a number that remains the same when digits are reversed

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string n){
    if(n.size()==1 || n.size()==0) return true;
    if(n[0]==n[n.size()-1]){
        n.erase(0,1);
        n.erase(n.size()-1,1);
        isPalindrome(n);
    }
    else{
        return false;
    }
    return true;
}

int main(){
    cout<<isPalindrome("123321");
    return 0;
}
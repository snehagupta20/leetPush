// Problem 6: Check if a String is Palindrome (Using Recursion)
// 👉 Input: "madam"
// 👉 Output: true

// 👉 Input: "hello"
// 👉 Output: false


#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string input, int left, int right){
    if(left>=right) return true;
    
    if(input[left]!=input[right]) return false;
    
    return isPalindrome(input, left+1, right-1);
}

int main() {
    string input1 = "madam";
    string input2 = "hello";
    
    if(isPalindrome(input1,0,input1.size()-1)) cout<<"input 1 is palindrome";
    else cout<<"input 1 is not a palindrome";
    
    cout<<endl;
    
    if(isPalindrome(input2,0,input2.size()-1)) cout<<"input 2 is a palindrome";
    else cout<<"input 2 is not a palindtome";
    
    return 0;
}
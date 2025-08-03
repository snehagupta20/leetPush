// 8: Generate All Binary Strings of Length N (Using Recursion)
// 👉 Input: n = 3
// 👉 Output:
// 000  
// 001  
// 010  
// 011  
// 100  
// 101  
// 110  
// 111  
// 👉 Explanation: You need to generate all possible binary strings of length n using recursion.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void binaryString(int n,string current){
    if(current.size()==n){
        cout<<current<<endl;
        return;
    }
    
    binaryString(n, current+"0");
    binaryString(n, current+"1");
}

int main() {
    int n = 3;
    // string binary_n = "000";
    // string empty="";
    binaryString(3,"");
    
    return 0;
}
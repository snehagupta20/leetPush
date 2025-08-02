// Problem 10: Print All Permutations of a String (Using Recursion)
// 👉 Input: "abc"
// 👉 Output:
// abc  
// acb  
// bac  
// bca  
// cab  
// cba  
// 👉 Explanation: A permutation is a rearrangement of characters, where order matters.


#include <iostream>
using namespace std;

void perumtation(string s, int index){
    if(index==s.size()-1){
        cout<<s<<endl;
        return;
    }
    
    for(int i=index;i<s.size();i++){
        swap(s[index], s[i]);
        perumtation(s, index+1);
        swap(s[index], s[i]);
    }
    
    return;
}
int main() {
    perumtation("abc", 0);

    return 0;
}
// Example 1 Remove all the occurrences of ‘a’ from string s = “abcax”.
//  Input s=”abcax” ch=’a’
//  Output bcx

#include <iostream>
#include <string>
using namespace std;

void remove(string a, char b, int start){
    if(a.size()-1==start) {
        cout<<a;  
        return;
    }
    if(a[start]!=b) start++;
    else if(a[start]==b) a.erase(start,1);
    remove(a,b,start);
    return;
}

int main(){
    remove("abcdefaabcdef",'a',0);
    return 0;
}
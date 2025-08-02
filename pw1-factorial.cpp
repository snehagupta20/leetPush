#include <iostream>
using namespace std;

int printFactorial(int n){
    if(n==1) return 1;
    return printFactorial(n-1)*n;
}

int main(){
    cout<<printFactorial(5);
    return 0;
}


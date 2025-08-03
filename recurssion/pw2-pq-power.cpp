// give 2 nums p & q, find the value p^q using recusion.

#include <iostream>
using namespace std;

int power(int p, int q){
    if(q==1) return p;
    if(q==0) return 1;

    return power(p,q-1)*p;
}

int main(){
    cout<<power(2,5);
    return 0;
}
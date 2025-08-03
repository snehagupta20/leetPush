#include <iostream>
using namespace std;

int sum(int num){
    if(num<10) return num;

    return sum(num/10) + (num%10);
}

int main(){
    cout<<sum(54637);
    return 0;
}
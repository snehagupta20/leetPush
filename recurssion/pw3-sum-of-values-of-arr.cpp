//  Problem Find the sum of the values of the array [2, 3, 5, 20, 1]
#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> v){
    if(v.size()==0) return 0;
    vector<int> newV(v.begin()+1, v.end());
    return sum(newV)+v[0];
}

int main(){
    vector<int> v = {1,2,3,4,5};
    cout<<sum(v);
    return 0;
}
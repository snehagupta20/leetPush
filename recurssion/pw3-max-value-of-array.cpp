//  Print the max value of the array [ 3, 10, 3, 2, 5]

#include <iostream>
#include <vector>
using namespace std;

void maxNum(vector<int> v, int ans){
    if(v.size()==0){
        cout<<ans;
        return;
    }
    if(v[0] > ans) ans = v[0];
    vector<int> newV(v.begin()+1,v.end());
    maxNum(newV,ans);
    return;
}

int main(){
    vector<int> v = {20,30,59404,22,22,0};
    maxNum(v,0);
    return 0;
}
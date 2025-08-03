// Problem 5: Reverse an Array Using Recursion
// 👉 Input: arr = [1, 2, 3, 4, 5]
// 👉 Output: [5, 4, 3, 2, 1]

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse_arr(vector<int> arr, int left, int right){
    
    if(left>=right) return arr;
    
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    
    return reverse_arr(arr,left+1, right-1);
    
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    arr = reverse_arr(arr,0,4);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
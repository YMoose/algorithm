// Given an array, rotate the array to the right by k steps, where k is non-negative.
// Leetcode 189
#include <iostream>
#include <vector>
using namespace std;
vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8};
template <typename T>
void vector_reverse(T& array, int lo, int hi){
    for(int i = 0; i< ((hi - lo)>>1); i++){
        swap(array[lo + i], array[hi - 1 - i]);
    }
}

template <typename T>
void vector_rotate(T& array, int k){
    k = k % array.size();
    vector_reverse(array, 0, array.size());
    vector_reverse(array, k, array.size());
    vector_reverse(array, 0, k);
}

int main(){
    int k;
    cout<<"Please type in the rotate num k";
    cin>>k;
    vector_rotate(array, k);
    for(int i = 0; i < array.size(); i++)
        cout<< array[i] << " ";
    cout<<endl;
    return 0;
}

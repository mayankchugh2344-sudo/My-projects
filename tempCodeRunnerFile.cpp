#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n;
cout<<"Enter the size of the array: ";
cin>>n;
int arr[n];
cout<<"Enter the elements of the array: ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int target;
cout<<"Enter the target element: ";
cin>>target;
//sort the array
sort(arr,arr+n);
//binary search only works on sorted array of stl
if(binary_search(arr, arr+n, target)){
    cout<<target<<endl;
    return 0;
}
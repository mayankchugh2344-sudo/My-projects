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
sort(arr,arr+n);
int max_diff=0;
//the maximum diffrence between two adjacent elements in the sorted array
for(int i=0;i<n-1;i++){
    if(arr[i+1]-arr[i]>max_diff){
        max_diff=arr[i+1]-arr[i];
    }
}
cout<<"The maximum difference is: "<<max_diff<<endl;
return 0;
}
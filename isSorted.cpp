#include<iostream>
using namespace std;

int isSorted(int n, int arr[]){
    if(n==1){
        return 1;
    }
    if(arr[n-1]<arr[n-2]){
        return 0;
    }
    else{
        return isSorted(n-1,arr);
    }
}

int main(){

int arr[5]={2,1,3,4,5};
int o=0;
o=isSorted(5,arr);
cout<<o<<" is the value returned";
}
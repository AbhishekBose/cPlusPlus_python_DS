#include<iostream>
//#include<conio>
//creating a max heap
using namespace std;
int a[5]={4,10,3,5,1};
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int arr[],int n,int i){
  int largest=i; //intializing the largest element in the heap;
  int l=2*i+1;
  int r=2*i+2;

  if(l<n && arr[l]>arr[largest]){
    largest=l;
  }
  if(r<n && arr[r]> arr[largest]){
    largest=r;
  }
  if(largest!=i){
    swap(&arr[i],&arr[largest]);
    heapify(arr,n,largest);
  }
}

int main() {
  int n= sizeof(a)/sizeof(a[0]) ;
  for(int i=(n/2)-1;i>=0;i--){
    heapify(a,n,i);
  }
  cout<<"The max heap is as follows: ";
  for(int j=0;j<n;j++){
    cout<<a[j]<<" ";
  }
  cout<<"\n";

  return 0;
}

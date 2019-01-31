#include<iostream>

using namespace std;

int a[6]={4,10,3,24,50,1};
int k=3;
int b[3]={-1,-1,-1};
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

  if(l<n && arr[l]<arr[largest]){
    largest=l;
  }
  if(r<n && arr[r]< arr[largest]){
    largest=r;
  }
  if(largest!=i){
    swap(&arr[i],&arr[largest]);
    heapify(arr,n,largest);
  }
}

void k_smallest(int arr[],int n,int m,int i){
  for(int j=(n/2)-1;j>=0;j--){
    heapify(arr,n,j);
  }
  for(int j=i+1;j<m;j++){
    if(a[j]>arr[0]){
      swap(&a[j],&arr[0]);
      heapify(arr,n,0);
    }
  }
}

int main(){
  int n=sizeof(a)/sizeof(a[0]);
//  for(int i=0;i<=n-k;i++){
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    k_smallest(b,k,n,k-1);
  //}
  cout<<"The largest elements are as follows: ";
  for(int i=0;i<k;i++){
    cout<<b[i]<<" ";
  }
  cout<<"\n";
  return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int a[8]={6,8,1,4,5,3,7,2};
    int i=0;
    int v=0;
    int j=0;
    for(i=1;i<8;i++){
        v=a[i];
        j=i;
        while(a[j-1]>v && j>=1){
            a[j]=a[j-1];
            j--;
        }
        a[j]=v;
    }
    cout<<"The sorted array is::"<<"\n";
    for(i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
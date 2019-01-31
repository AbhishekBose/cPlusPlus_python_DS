#include<iostream>
using namespace std;
int A[3]={0,0,0};
void binary(int n){
    if(n<1){
        for(int i=0;i<3;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    else{
        A[n-1]=0;
        binary(n-1);
        A[n-1]=1;
        binary(n-1);
    }
}

int main(){
    binary(3);
    return 0;
}
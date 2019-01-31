#include<iostream>
using namespace std;

void towers_of_hanoi(int n,char from_peg,char to_peg,char aux_peg){
    if(n==1){
        cout<<"Moving disc 1 from "<<from_peg<<" to "<<to_peg<<"\n";
    }
    else{
        towers_of_hanoi(n-1,from_peg,aux_peg,to_peg);
        cout<<"Moving disc "<<n<<" from "<<from_peg<<" to "<<to_peg<<"\n";
        towers_of_hanoi(n-1,aux_peg,to_peg,from_peg);
   }
}

int main()
{
    char fp= 'a';
    char tp= 'b';
    char ap= 'c';
    towers_of_hanoi(3,fp,tp,ap);
    return 0;
}
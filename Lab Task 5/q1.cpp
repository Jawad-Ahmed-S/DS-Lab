#include <iostream>
using namespace std;

int calculateFactorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n *calculateFactorial(n-1);
    }
}

int main() {
   int n= calculateFactorial(10);
cout<<n;
    return 0;
}
#include <iostream>
using namespace std;
void funcB(int n);
void funcA(int n){

    if(n==0){
        return;
    }
    else{
        cout<<n<<" ";
        funcB(n-1);
    }
}
void funcB(int n){

    if(n==0){
        return;
    }
    else{
        cout<<n<<" ";
        funcA(n-1);
    }
}
int main() {
    funcA(8);
    return 0;
}
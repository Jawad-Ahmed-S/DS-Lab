#include <iostream>
using namespace std;

int sumNonTail(int n){
    if(n==0){
        return n;
    }
    else{
        return n+sumNonTail(n-1);
    }
}
int main() {
    int n=sumNonTail(10);
    cout<<n<<" ";

    return 0;
}
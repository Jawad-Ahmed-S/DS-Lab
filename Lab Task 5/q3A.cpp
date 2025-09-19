#include <iostream>
using namespace std;

int sumTail(int n,int total){
    if(n==0){
        return total +n;
    }
    else{
        total+=n;
        return sumTail(n-1,total);
    }
}
int main() {
    int n=sumTail(10,0);
    cout<<n<<" ";

    return 0;
}
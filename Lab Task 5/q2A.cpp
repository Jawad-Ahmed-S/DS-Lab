#include <iostream>
using namespace std;
void printNumbers(int n){

    if(n==0){
        return;
    }
    else{
        cout<<n<<" ";
        printNumbers(n-1);
    }
}
int main() {
    printNumbers(4);
    return 0;
}
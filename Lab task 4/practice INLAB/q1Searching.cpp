#include <iostream>
using namespace std;

int LinearSearch(int target,int array[],int n){
    for(int i=0;i<n;i++){
        if(array[i]==target){
            cout<<"Found! at Index : "<<i<<endl;
            return i;
        }
        
    }
    cout<<"Not Found!"<<endl;
    return -1;
}
int main() {
    int array[5]={3,4,5,1,0};
    int n=5;
    int target=0;
    LinearSearch(target,array,n);

    return 0;
}
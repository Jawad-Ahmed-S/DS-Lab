#include <iostream>
using namespace std;


    int ackerMan(int m,int n){
        if(m==0)
        {
            cout<<"Returning as (m==0) , m: "<<m<<"n: "<<n<<endl;            
            return n+1;}

        if( m >0 && n==0){
            cout<<"(m>0 and n=0): m: "<<m<<"n: "<<n<<endl;
            ackerMan(m-1,1);
        }
        if( m >0 && n>0){
            cout<<"(m>0 and n>0): m: "<<m<<"n: "<<n<<endl;
            ackerMan(m-1,ackerMan(m,n-1));
        }
    }
int main() {
    ackerMan(3,4);
    return 0;
}
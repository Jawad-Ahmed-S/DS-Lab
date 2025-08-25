#include<iostream>
using namespace std;
class Box{
    int *size;
    public:
     Box(int siz){
         size = new int(siz);
     }
     Box(){
        size = new int(0);
     }
     Box(const Box &b){
        size = new int(*b.size);
     }
     ~Box(){
        delete size;
     }
     Box& operator=(const Box&other){
        delete size;
        size = new int(*other.size);
        return *this;
     }
     void setSize(int sizeUpdate){
        delete size;
        size =new int(sizeUpdate);

     }
     int displaySize(){
        return *size;
     }
};
int main() {

     Box b(100);
     cout<<"b created with size="<<b.displaySize()<<endl;
     Box b1 = b; //Copy Assignment operator Called so value of b should be in b1;
     cout<<"b1 created with size="<<b1.displaySize()<<endl;
     b1.setSize(50);
     cout<<"b1 size updated with ="<<b1.displaySize()<<endl;//b1 updates to 50 
     cout<<"As Deep Copy b doesnt got updated; size="<<b.displaySize()<<endl;// b doesnt update means DEEP COPY 
     // If Shallow Copy then b also updates
     Box b2;                         
     cout<<"b2 created with default constructor; size="<<b2.displaySize()<<endl;
     b2=b;
     cout<<"After using Copy Assignment on b2 \nsize="<<b2.displaySize();
 
    return 0;
}
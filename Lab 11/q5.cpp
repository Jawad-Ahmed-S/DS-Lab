#include <iostream>
#include <list>
using namespace std;

class HashMap{
    int * array;
    bool * occupied;
    int size;

    public:
    HashMap(int size){
        this->size=size;
        array = new int[size];
        occupied = new bool[size];

        for(int i=0;i<size;i++){
            array[i]=NULL;
            occupied[i]=false;
        }
        
    }
    int hash(int key){
        return key%size;
    }
    void insert(string name,int rollNumber){
        int index=hash(rollNumber);
        int startIndex= index;

        for(int i=0;i<size;i++){
            int newIndex = (index + i*i)%size;

            if(!occupied[newIndex]){
                array[newIndex]=rollNumber;
                occupied[newIndex]=true;
                return;
            }
            if(array[newIndex]==rollNumber){
                return;
            }


        }
        cout<<"Hash Table full"<<endl;
    }
    void search(int rollNumber){
        int index=hash(rollNumber);
        int startIndex= index;

        for(int i=0;i<size;i++){
            int newIndex = (index + i*i)%size;

            if(!occupied[newIndex]){
                cout<<"Not Found!"<<endl;
                return;
            }
            if(array[newIndex]==rollNumber){
               cout << "Found at index " << newIndex << endl;
                return;
            }


        }
         cout << "Not found"<<endl;
    } 
};
int main() {
    HashMap test(10);
    test.insert("jawad",123);
    test.insert("ahmed",456);
    test.search(456);
    return 0;
}
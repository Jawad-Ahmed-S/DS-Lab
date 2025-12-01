#include <iostream>
#include <list>
using namespace std;

class HashMap{
    list <string>* array;
    int size;

    public:
    HashMap(int size){
        this->size=size;
        array = new list<string>[size];
    }
    int hash(string key){
        int sum=0;
        for( char c:key){
            sum+=c;
        }
        return sum%size;
    }
    void insert(string key){
        array[hash(key)].push_front(key);
    }
    void deleteEntry(string key){
        int index = hash(key);
        if(!array[index].empty()){
            array[index].erase(array[index].begin());
        }   
    }
    void search(string key){
        int index = hash(key);
        for(auto i=array[index].begin();i!=array[index].end();i++){
            if(*i==key){
                cout<<"Found"<<endl;
                break;
            }
        }
        } 
};
int main() {
    HashMap test(10);
    test.insert("jawad");
    test.insert("ahmed");
    test.search("ahmed");
    test.deleteEntry("jawad");
    return 0;
}
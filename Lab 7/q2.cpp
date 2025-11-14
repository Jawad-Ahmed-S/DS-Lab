#include<iostream>
using namespace std;
class Heap{
    int array[100];
    int size=0;

    public:

    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (2*i)+1;}
    int right(int i){ return (2*i)+2;}

    void heapifyUp(int index){
        while(index!=0 && array[index]>array[parent(index)]){
            swap(array[index],array[parent(index)]);
            index = parent(index);
        }
    }
    void heapifyDown(int index){
        int largest = index;
        int l = left(index);
        int r = right(index);

        if(l<size && array[l]> array[largest]){
            largest = l;
        }
        if(r<size && array[r]> array[largest]){
            largest = r;
        }

        if(largest!=index){
            swap(array[index],array[largest]);
            heapifyDown(largest);
        }
    }
    void insert(int val){
        if(size ==100){
            cout<<"Heap Overflow";
        }
        array[size]=val;
        heapifyUp(size);
        size++;
    }
    void deletion(){
        if(size==0){
            cout<<"Heap underflow!";
            return;
        }
        array[0]=array[size-1];
        size--;

        heapifyDown(0);

    }
    void update(int i,int val){
        if(i>size){
            cout<<"out of bounds"<<endl;
            return;
        }
        int old = array[i];
        array[i]=val;
        if(old<val){
            heapifyUp(i);
        }
        else{
            heapifyDown(0);
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    void isBinaryHeap(){
        
        for(int i=0;i<(size-2)/2;i++){
            int l = left(i);
            int r = right(i);

            if(l< size && array[i]<array[l]){
                return false;
            }
            if(r< size && array[i]<array[r]){
                return false;
            }

        }
    }

};

int main(){

    Heap h1;
    h1.insert(8);
    h1.insert(7);
    h1.insert(6);
    h1.insert(5);
    h1.insert(4);
    h1.display();
    h1.update(2,4);
    h1.display();

}
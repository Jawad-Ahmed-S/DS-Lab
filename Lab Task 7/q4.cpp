#include <iostream>
using namespace std;

class Product{
    string name;
    int price;
    string description;
    bool availability;

    public:
    Product(string n,int p,string d,bool a){
        name=n;
        price=p;
        description=d;
        availability=a;
    }
    int getprice(){
        return price;
    }
    void setProduct(string n,int p,string d,bool a){
        name=n;
        price=p;
        description=d;
        availability=a;
    }
    void display(){
        cout<<name<<" "<<price<<" "<<description<<" "<<availability<<" "<<endl;
    }
};
int partition(Product arr[],int low,int high){
    int pivot=arr[low].getprice();
    int i=low+1;
    int j=high;   

    while(i<=j){

        while(i<=high && arr[i].getprice()<=pivot){
            i++;
        }
        while(j>=low && arr[j].getprice()>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;

}

void quickSort(Product arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}


int main() {

    Product p1("Product A",1000,"Descriptive A",true);
    Product p2("Product B",200,"Descriptive B",false);
    Product p3("Product C",100,"Descriptive C",true);
    Product p4("Product D",500,"Descriptive D",false);
    Product p5("Product E",800,"Descriptive E",true);
    Product arr[5] = {p1,p2,p3,p4,p5};

    quickSort(arr,0,6);
    for(int i=0;i<6;i++){
        arr[i].display();
    }
    return 0;
}
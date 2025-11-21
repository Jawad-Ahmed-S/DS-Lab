#include <iostream>
using namespace std;

struct Node{
int data;
Node* next;

Node(int d){
    data =d;
    next=nullptr;
}

};

class ll{
    public:
    Node* head;

    ll(){
        head=nullptr;
    }
    void insertBucket(int data){
        Node *newNode= new Node(data);
        Node *temp= head;
        if(temp==nullptr){
            head=newNode;
            return;
        }
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void clearBucket(){
        Node* temp;
        while(head!=nullptr){
            temp=head;
            head=head->next;
            delete temp;
        } 
    }
};
int getMax(int arr[],int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void radixSort(int arr[],int size){
    int max = getMax(arr,size);
    int exp =1;

    ll buckets[10];

    while(max/exp>0){
        
        for(int i=0;i<size;i++){
            int digit = (arr[i]/exp)%10;
            buckets[digit].insertBucket(arr[i]);
        }

        int indx=0;
        for(int i=0;i<10;i++){
            Node * temp = buckets[i].head;
            while(temp!=nullptr){
                arr[indx]=temp->data;
                indx++;
                temp=temp->next;
            }
            buckets[i].clearBucket();
        }

        exp*=10;

    }
}

void radixSortDescending(int arr[],int size){
    int max = getMax(arr,size);
    int exp =1;

    ll buckets[10];

    while(max/exp>0){

        for(int i=0;i<size;i++){
            int digit = (arr[i]/exp)%10;
            buckets[digit].insertBucket(arr[i]);
        }

        int indx=0;
        for(int i=9;i>=0;i--){
            Node * temp = buckets[i].head;
            while(temp!=nullptr){
                arr[indx]=temp->data;
                indx++;
                temp=temp->next;
            }
            buckets[i].clearBucket();
        }

        exp*=10;

    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
   int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array: (Ascending)";
    printArray(arr, n);
    radixSortDescending(arr,n);
    cout << "Sorted array: (Descending)";
    printArray(arr, n);

    return 0;
}
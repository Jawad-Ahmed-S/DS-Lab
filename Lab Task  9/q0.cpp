#include <iostream>
#include <vector>
using namespace std;
class AVL{

    public:
    void insert(int data){

    }
};
struct node{

    int data;
    node * right;
    node * left;

    node(int data):data(data){
        right=left=nullptr;
    };
};
void inorder(node* root,vector <int> vec){
        if(!root) return;
        inorder(root->left,vec);
        vec.push_back(root->data);
        inorder(root->right,vec);
    }
int main() {
        
    node * n1= new node(10);
    node * n2= new node(6);
    node * n3= new node(4);
    node * n4= new node(16);
    node * n5= new node(12);
    node * n6= new node(18);
    node * n7= new node(8);

    n1->left=n2;
    n1->right=n4;
    n2->left=n3;
    n2->right=n7;
    n4->left=n5;
    n4->right=n6;
    vector <int> vec;
    inorder(n1,vec);

    AVL avl;

    for(int i=0;i<vec.size();i++){
        avl.insert(vec[i]);
    }

    return 0;
}
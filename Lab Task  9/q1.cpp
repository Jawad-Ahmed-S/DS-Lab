#include <iostream>
using namespace std;

struct Student{
    string name;
    int data;

    Student(string name,int data){
        this->name= name;
        this->data = data;
    }
};

struct Node{

    Student *st;
    Node* left;
    Node* right;
    int height;

    Node(string name,int data){
        st = new Student(name,data);
        left=right = NULL;
        height=0;
    }
    
};

    int height(Node* root){

        if(root==NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return ((lh>rh)?lh:rh)+1;
    };
   
    Node* rightRot(Node * oldParent){
        Node * orphan = oldParent->right;
        Node * newParent = oldParent->left;
        newParent->right = oldParent;

        oldParent->left = orphan;

        newParent->height = height(newParent);
        oldParent->height = height(oldParent);
        
        return newParent;
    }
    Node* leftRot(Node * oldParent){
        Node* orphan = oldParent->left;
        Node* newParent = oldParent->right;
        newParent->left = oldParent;
        
        oldParent->right=orphan;
        newParent->height = height(newParent);
        oldParent->height = height(oldParent);

        return newParent;
    }
    Node* insert(string name,int data,Node* root){
        
        
        if(root==NULL){
            Node *newNode = new Node(name,data);
            root= newNode;
        }
       
        if(root->st->data>data){
            root->left = insert(name,data,root->left);
        }
        else{
            root->right = insert(name,data,root->right);
        }
        root->height = height(root);

        if((root->left->height - root->right->height)==2){

            if((root->left->left->height - root->left->right->height)==1){
                root = rightRot(root);
            }

            if((root->left->left->height - root->left->right->height)==-1){
                root= rightRot(root->left);
                root= leftRot(root);
            }

        }
        if((root->left->height - root->right->height)==-2){

            if((root->right->left->height - root->right->right->height)==1){
                root = leftRot(root);
            }

            if((root->right->left->height - root->right->right->height)==-1){
                root= leftRot(root->right);
                root= rightRot(root);
            }
        }
        
        return root;

    }
    void inorder(Node *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->st->name<<" "<<root->st->data<<endl;
        inorder(root->right);
    }
int main() {
    Node * root=NULL;

    root = insert("jawad",10,root);
    root = insert("jawad",20,root);
    root = insert("jawad",30,root);
    root = insert("jawad",40,root);
    root = insert("jawad",50,root);
    root = insert("jawad",15,root);
    inorder(root);


    return 0;
}
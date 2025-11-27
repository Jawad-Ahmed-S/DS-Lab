#include <iostream>
#include <vector>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data){
        this->data = data;
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
    Node* insert(int data,Node* root){
        
        
        if(root==NULL){
            Node *newNode = new Node(data);
            root= newNode;
        }
       
        if(root->data>data){
            root->left = insert(data,root->left);
        }
        else{
            root->right = insert(data,root->right);
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
    int inorder(Node *root,vector <int> &vec,int k){
        if(root==NULL){
            return -1;
        }
        int leftSmallest= inorder(root->left,vec,k);
        if(leftSmallest!=-1){ return leftSmallest;}
        vec.push_back(root->data);
        if(vec.size()==k){
            return root->data;
        }

        return inorder(root->right,vec,k);
        }
int main() {
    Node * root=NULL;

    root = insert(50,root);
    root = insert(30,root);
    root = insert(70,root);
    root = insert(20,root);
    root = insert(40,root);
    root = insert(60,root);
    root = insert(80,root);
    root = insert(65,root);
    vector <int> vec;
    int smallest  =inorder(root,vec,2);


    return 0;
}
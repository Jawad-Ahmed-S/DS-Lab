#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
    }
};

    Node *Search(Node *root,int target){
        if(root==NULL)return root;

        if(root->data == target)return root;
        else if(root->data>target) {return Search(root->left,target);}
        else{return Search(root->right,target);}
   
    }
    Node* insert(Node* root,int data){
        if(root==NULL){
            return new Node(data);
        }

        if(data<root->data){
            root->left = insert(root->left,data);
        }
        else  if(data>root->data){
            root->right = insert(root->right,data);
        }

        return root;

    }
    void inorder(Node* root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(Node* root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    Node* findMax(Node *root){
        while(root&& root->right!=NULL){
            root= root->right;
        }
        return root;
    }
    Node * deleteNode(Node *root,int target){

        root = Search(root,target);
        if(root==NULL){
            cout<<"Empty"<<endl;
            return;
        }

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        else if(root->left==NULL){
            Node * temp = root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node * temp = root;
            root=root->left;
            delete temp;
        }

        Node * temp = findMax(root->left);
        root->data = temp->data;
        root->right = deleteNode(root->left,target);

    }
    bool isBSTHelper(Node* root,int min,int max){
        if(root==NULL){
            return true;
        }

        if(root->data <=min || root->data > max){
            return false;
        }

        return (isBSTHelper(root->left,min,max) && isBSTHelper(root->right,min,max));

    }

int main() {
    
    return 0;
}
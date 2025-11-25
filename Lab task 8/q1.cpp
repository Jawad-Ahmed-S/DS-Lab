#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

    Node *Search(Node *root,int target){
        if(root==NULL)return NULL;

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

        if(root==NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node* root){
        if(root==NULL) return;  
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root){
        if(root==NULL) return;  
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    Node* findMax(Node *root){
        if(root==NULL) return;  
        while(root&& root->right!=NULL){
            root= root->right;
        }
        return root;
    }
    Node * deleteNode(Node *root,int target){

        root = Search(root,target);
        if(root==NULL){
            cout<<"Empty"<<endl;
            return root;
        }

        if(target<root->data){
            root->left = deleteNode(root->left,target);
        }
        else if(target>root->data){
            root->right = deleteNode(root->right,target);
        } 
        else{

        if(root->left==NULL){
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
        return root;
    }


int main() {
    
    Node * root =NULL;
    insert(root,50);
    insert(root,20);
    insert(root,70);
    insert(root,80);
    insert(root,60);

    


    return 0;
}
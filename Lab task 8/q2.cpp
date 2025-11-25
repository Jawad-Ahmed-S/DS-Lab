#include <iostream>
using namespace std;
#include<ctime>
#include<cstdlib>

struct Node{
    int data;
    Node* left;
    Node* right;
    int HealthPoints;
    int AttackPoints;
    string name;
    Node(int data,int HP,int AP){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
        HealthPoints=HP;
        AttackPoints=AP;
    }
};

    Node *Search(Node *root,int target){
        if(root==NULL)return NULL;

        if(root->data == target)return root;
        else if(root->data>target) {return Search(root->left,target);}
        else{return Search(root->right,target);}
   
    }
    Node* insert(Node* root,int data,int HP,int AP){
        if(root==NULL){
            return new Node(data,HP,AP);
        }

        if(data<root->data){
            root->left = insert(root->left,data,HP,AP);
        }
        else  if(data>root->data){
            root->right = insert(root->right,data,HP,AP);
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
        if(root==NULL) return root;  
        while(root&& root->right!=NULL){
            root= root->right;
        }
        return root;
    }
    Node * deleteNode(Node *root,int target){

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
            delete temp;
            return temp;
        }
        else if(root->right==NULL){
            Node * temp = root;
            delete temp;
            return temp;
        }
        
        Node * temp = findMax(root->left);
        root->data = temp->data;
        root->HealthPoints=temp->HealthPoints;
        root->AttackPoints=temp->AttackPoints;
        root->left = deleteNode(root->left,target);
    }
        return root;
    }
    
    Node* findSmallest(Node *root){
        if(root==NULL) return root;  
        while(root && root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    void Attack(Node* Attacker,Node* &VictimRoot,Node* ToBeAttacked){


        int randomVal = rand()%5;
        
        ToBeAttacked->HealthPoints-=Attacker->AttackPoints+randomVal;
        if(ToBeAttacked->HealthPoints<=0){
            VictimRoot= deleteNode(VictimRoot,ToBeAttacked->data);
        }
        
    }
    
int main() {
        
        srand(time(0));
    Node * Heroes =NULL;
    Heroes =insert(Heroes,50,100,40);
    Heroes =insert(Heroes,20,100,50);
    Heroes =insert(Heroes,70,100,80);
    Heroes =insert(Heroes,80,100,90);
    Heroes =insert(Heroes,60,100,10);
    
    Node * Enemies =NULL;
    Enemies = insert(Enemies,50,100,40);
    Enemies = insert(Enemies,20,100,50);
    Enemies = insert(Enemies,70,100,80);
    Enemies = insert(Enemies,80,100,90);
    Enemies = insert(Enemies,60,100,10);


    while(!(Heroes==NULL || Enemies==NULL)){


        Node* Attacker = findSmallest(Heroes);
        Node* ToBeAttacked = findSmallest(Enemies);
        if(Heroes && Enemies){
            Attack(Attacker,Enemies,ToBeAttacked);
        }
        if (Enemies == NULL) break;
        
        Attacker = findSmallest(Enemies);
        ToBeAttacked = findSmallest(Heroes);

        if(Heroes && Enemies){
            Attack(Attacker,Heroes,ToBeAttacked);
        }

    }
    


    return 0;
}
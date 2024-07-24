#include <bits/stdc++.h>
using namespace std;
// TAIL POINTER IS THE POINTER TO THE LAST NODE OF THE LL
// INSERTION AT BEGINNING: Inserting first in the list i.e. in front of tail node
// INSERTION AT END: insert front of tail and make tail point to the new node
class node{
    public:
    int data;
    node* next;
    public:
    node(int data){
      this->data=data;
      this->next=NULL;
    }
    ~node(){
      int val=this->data;
     if(next!=NULL){
        delete next;
        next=NULL;
      }  
      cout<<"memory free for node with data "<<val<<endl;
    }
};

void insert(node* &tail ,int element, int d ){
    if(tail==NULL){
        node* newNode= new node(d);
        tail=newNode;
        newNode->next=newNode;
      
    }
    else{
          node* temp=tail;
          while(temp->data!=element) temp=temp->next;
          node* newNode = new node(d);
          newNode->next=temp->next;
          temp->next=newNode;
    }
}
void deleteNode(node* &tail,int d){
  if(tail==NULL){ cout<<"list already empty."<<endl; return; }
  else{
  node* ptr=tail->next;
  node* preptr=tail;
  while(ptr->data!=d){
    preptr=ptr;
    ptr=ptr->next;  }
    if(preptr==ptr){ //single node in list so both pointer points to the same node
      tail=NULL;
    } 
    // more than 1 node in list
    preptr->next=ptr->next;
     if(tail==ptr){
      tail=preptr; //since it's a circular LL, tail can point to any node 
    }
    ptr->next=NULL;
    delete ptr;
} 
}

void insertAtEnd(node* &tail, int d){
  node* newNode=new node(d);
  newNode->next=tail->next;
  tail->next=newNode;
  tail=tail->next;
}

void print(node* tail){
  if(tail==NULL) cout<<"list is already empty."<<endl; 
  node* temp=tail;
  do{
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=tail); //if there's only one node in list, so (temp!=tail) condition won't work cuz a single node will point to itself thus using do-while loop as it executes for atleast one time 
  cout<<endl;
}
int main()
{
    node* tail=NULL ;
    insert(tail,1,3);
   // print(tail);
   insert(tail,3,5);
   /*
   // print(tail);
   insert(tail,3,9);
  //  print(tail);
  insert(tail,3,7);
   // print(tail);
      insert(tail,5,21);
    print(tail); */
   
    print(tail); 
    insertAtEnd(tail,1);
    insert(tail,3,9);
    cout<<tail->data<<endl;
        print(tail); 


return 0;
} 
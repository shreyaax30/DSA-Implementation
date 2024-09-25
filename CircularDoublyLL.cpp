#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    node* prev;
    int data;
    node* next;
    node(int d){
       this->prev=NULL;
       this->data=d;
       this->next=NULL;
    }
    ~node(){
        int n=this->data;
        if(next!=NULL) next=NULL;
        delete next;
        cout<<"memory free for node with data "<<n<<endl;
    }
};

void insertAtBegin(node* &tail,int d){
    if(tail==NULL){
        node* newNode=new node(d);
        newNode->prev=newNode;
        newNode->next=newNode;
        tail=newNode;
    }
    else{
        //INSERT AT BEGINNING
        node* temp=tail->next; // temp points to the first node of the list
     node* newNode=new node(d);
     newNode->next=temp;
     newNode->prev=tail;
     temp->prev=newNode;
     tail->next=newNode;
    }
}
void insertAtEnd(node* &tail,int d){
    if(tail==NULL){
        node* newNode=new node(d);
        newNode->prev=newNode;
        newNode->next=newNode;
        tail=newNode;
    }
    else{
        node* ptr=tail->next; ///ptr points to the first node
      node* newNode=new node(d);     
      newNode->prev=tail;
      newNode->next=ptr;
      tail->next=newNode;
      ptr->prev=newNode;  //tail->next->prev=newNode;
     tail=newNode;
    }
}
void insertAfter(int element,node* &tail,int d){
    node* temp=tail;
    while(temp->data!=element){
        temp=temp->next;
    }
    node* newNode=new node(d);
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
  
}
void print(node* tail){
    node* temp=tail->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
    cout<<endl;
}
void deleteNode(int d,node* &tail){
    node* temp=tail->next;
    node* preptr=tail;

    while(temp->data!=d) { 
        preptr=temp;
        temp=temp->next;}
        //single node present
    if(preptr==temp){
        tail=NULL;
        delete temp;
        return;
    }
    //multiple nodes present
    preptr->next=temp->next;
    temp->next->prev=preptr;
    if(tail==temp){ // delete tail node
        tail=preptr;
    }
    
    delete temp;
}
int main()
{
node* tail=NULL;
insertAtBegin(tail,5);
print(tail);
insertAtBegin(tail,10);
print(tail);
insertAtBegin(tail,15);
print(tail);
insertAtEnd(tail,3);
print(tail);
insertAfter(10,tail,12);
print(tail);
cout<<endl;
deleteNode(5,tail);
print(tail);
cout<<tail->data;

return 0;
}
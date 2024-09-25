#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    public:
    node(int data){
      this->data=data;
      this->next=NULL;
    }
  node(int data ,node* next){
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

void Insert(node* &head,int data){
  if(head==NULL){
     node* newNode = new node(data,nullptr);
     head=newNode; }
  else {
    node* ptr=head;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    node* newNode = new node(data,nullptr);
    ptr->next=newNode;

  }
}

void print(node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;

  }
  cout<<endl;
}

void InsertAtPosition(node* &head,int pos,int d  ){
  int cnt(1);
   node* temp=head;
   while(cnt!=pos-1 ){
    temp=temp->next;
    cnt++;
   }
   node* n =new node(d,temp->next);
   temp->next=n;
}


void insertAtBegin(node* &head,int data){
  node* newNode=new node(data,head);
  head=newNode;

}

void deleteAtEnd(node* &head){
  node* preptr;
  node* ptr=head;
  while(ptr->next!=NULL){
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=NULL;
  free(ptr);
}

void deleteAtFront(node* &head){
  node* temp=head;
  head=head->next;
  free(temp);
}

void deleteNode(node* head, int data){
  node* ptr=head;   // ptr points to the node i.e. to be deleted
  node* preptr;     // points to the previous node
  while(ptr->data!=data){
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=ptr->next;
  delete ptr;
}


void deleteAfterNode(node* &head, int value){
node* temp=head;
while(temp->data!=value){
  temp=temp->next;
}
// temp points to the node which has data 'value'
// we need to delete node after temp 
node* ptr=temp->next;   //ptr is to be deleted 
temp->next=ptr->next;
free(ptr);
}

void deleteBeforeNode(node* &head, int value){
  node* preptr; // points to the previous of node i.e. to be deleted 
  node* ptr;    // points to the node i.e to be deleted
  node* temp;   // temp points to the node which stores 'value'
  temp=head;
  while(temp->data!=value){
    preptr=ptr;
    ptr=temp;
    temp=temp->next;
  }
  preptr->next=temp;
  free(ptr);
}
void insertAfter(node* &head,int targetNode, int d){
  node* temp;
  temp=head;
  while(temp->data!=targetNode){
    temp=temp->next;
  }
node* newNode=new node(d);
newNode->next=temp->next;
temp->next=newNode;
}

void insertBefore(node* &head, int targetNode, int data){
  node* ptr=head;
  node *preptr;  
  while(ptr->data!=targetNode){
    preptr=ptr;
    ptr=ptr->next;
  }
  node* newNode= new node(data,ptr);
  preptr->next=newNode;
}
void count(node* &head){
node* temp=head;
int cnt(0);
while(temp!=NULL){
  temp=temp->next;
  cnt++;
}
cout<<"Length of the LL: "<<cnt<<endl;
}
void DeleteList(node* &head){
  if(head==NULL) cout<<"Linked List already empty."<<endl;
  else{
    cout<<"Linked list being deleted"<<endl;
    while(head!=NULL){
      node* temp=head;
      head=head->next;
      delete temp;
    }
    cout<<"Linked List deleted"<<endl;
  }
}
void reverse(node*& head){
  node *prev, *curr ,*next;
  curr=head;
  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  head=prev;
}

  int main()
{
  node* head=NULL;
 Insert(head,5);
 Insert(head,10);
 Insert(head,15);
 Insert(head,20);
 Insert(head,25);
 
 
 //Insert(head,8);
 print(head);

  reverse(head);
   print(head);
return 0;  
}
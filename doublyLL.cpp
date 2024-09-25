#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    node* prev;
    int data;
    node* next;
    node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};
void insertAtHead(node* &head,int d){
    node* newNode= new node(d);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void insertAtEnd(node* &head, int d){
    if(head==NULL){
        node* newNode= new node(d);
        head=newNode;
    }
    else{
    node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    node* newNode=new node(d);
    ptr->next=newNode;
    newNode->prev=ptr;
}}
void insertAtPosition(node* &head, int pos, int d){
    int cnt(1);
    node* ptr=head;
    while(cnt!=pos-1){
        ptr=ptr->next;
        cnt++;
    }
    node* newNode = new node(d);
    newNode->next=ptr->next;
    ptr->next=newNode;
    newNode->prev=ptr;

}
void insertAfterNode(node* &head,int targetNode,int d){
    node* current=head;
    while(current->data!=targetNode){
        current=current->next;
    }
     node* newNode = new node(d);
     newNode->next=current->next;
     newNode->prev=current;
     current->next=newNode;
}
void insertBeforeNode(node* &head,int targetNode,int d){
node* ptr=head;
node* preptr;
while(ptr->data!=targetNode){
    preptr=ptr;
    ptr=ptr->next;
}
node* newNode=new node(d);
newNode->prev=preptr;
newNode->next=ptr;
preptr->next=newNode;
ptr->prev=newNode;
}

void deleteAtFront(node* &head){
    node* ptr=head;
    head=head->next;
    head->prev=NULL;
    delete ptr;
}

void deleteAtEnd(node* &head){
    node* ptr=head;
    node* preptr;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    delete ptr;
}

void deleteNode(node* &head, int target){
    node* ptr=head;
    node *preptr, *postptr;
    while(ptr->data!=target){
        preptr=ptr;
        ptr=ptr->next;
    }
    postptr=ptr->next;
    preptr->next=postptr;
    postptr->prev=preptr;
    delete ptr;
}

void deleteBeforeNode(node* &head,int nodeValue){
    node* preptr;
    node* ptr;  // to be deleted
    node* temp=head;
    while(temp->data!=nodeValue){
        preptr=ptr;
        ptr=temp;
        temp=temp->next;
    }
  preptr->next=temp;
  temp->prev=preptr;
  delete ptr;
}

void deleteAfterNode(node* &head,int nodeValue){
    node* temp=head;
    while(temp->data!=nodeValue){
        temp=temp->next;
    }
    node* ptr=temp->next;
    temp->next=ptr->next;
    ptr->next->prev=temp;
    delete ptr;
}
void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
      cout<<ptr->data<<" ";
      ptr=ptr->next;
    }
    cout<<endl;
}

void count(node* head){
    node* ptr=head;
    int cnt(0);
    while(ptr!=NULL){
     cnt++;
     ptr=ptr->next;
    }
    cout<<"Length is "<<cnt<<endl;
}

void deleteList(node* &head){
    if(head==NULL) cout<<"List already empty"<<endl;
    else{
    cout<<"List being deleted..."<<endl;
    while(head!=NULL){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    cout<<"List deleted."<<endl;
}}
int main()
{
node* head=NULL;
insertAtEnd(head,7);
insertAtHead(head,5);
insertAtEnd(head,51);
insertAtPosition(head,3,8);
insertAfterNode(head,8,9);
insertBeforeNode(head,51,10);
deleteAfterNode(head,8);
print(head);
count(head);
print(head);
return 0;
}
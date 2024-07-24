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
node* convertArrayToDoublyLL(vector<int> &arr){
node* head=new node(arr[0]);
node* ptr=head;
for(int i=1;i<arr.size();i++){
node* temp=new node(arr[i]);
temp->prev=ptr;
ptr->next=temp;
ptr=temp ; // or ptr=ptr->next;
}
return head;
}

int main()
{
vector<int> arr={1,2,3,4,5,6};
node* head=convertArrayToDoublyLL(arr);
while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;

}
return 0;
}
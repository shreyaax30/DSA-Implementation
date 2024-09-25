#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* convertArrayToLinkedList(vector<int> &arr){
node* head=new node(arr[0]);
node* ptr=head;
for(int i=1;i<arr.size();i++){
    node* temp=new node(arr[i]);
    ptr->next=temp;
    ptr=ptr->next;
}
return head;
}
int main()
{
vector<int>arr={1,2,3,4,5,6};
node* head=convertArrayToLinkedList(arr);
while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;

}
return 0;
}
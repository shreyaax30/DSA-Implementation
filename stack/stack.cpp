#include<iostream>

class Stack{
  public:
  int top; //for indexing 
  int *arr;
  int size;
   Stack(int size){
    this->size =size;
    arr=new int[size];
    top=-1;
   }

   void push(int value){
     if(top==size-1)  std::cout<<"Stack Overflow"<<std::endl; 
     else{
      top++;
      arr[top]=value;
     }
   }
 
   void pop(){
   if(top==-1) std::cout<<"Stack is Empty";
   else  top--;
   }

   int peek(){
     if(top==-1) {
      std::cout<<"Stack is Empty";
      return -1;
     }
     else return arr[top];
   }

   bool isEmpty(){
    if(top==-1) return true;
    else return false; 
   }
};

int main(){
   Stack st(5);
   st.push(10);
   st.push(20); 
   st.push(20); 
   st.push(20); 
   st.push(20); 
   st.push(20); 
}
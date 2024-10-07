#include<iostream>
using namespace std;
class queue{
  public:
  int front;
  int rear;
  int* arr;
  int size;

  queue(){
  this->size=100;
  arr = new int[size];
  this->front = this->rear = -1;
  }

  void enqueue(int x){
    if(rear==size) cout<<"Queue Overflow"<<endl;
    else if(front==-1 && rear==-1){
      front++;
      rear++;
      arr[rear]=x;
    }
    else{
      rear++;
      arr[rear]=x;
    }
  }

  void dequeue(){
    if(front==-1 && rear==-1) cout<<"queue is empty"<<endl; 
    else{
      front++;
    }
  }

  int front(){
    return arr[front];
  }

  bool isEmpty(){
    if(front==-1) return true;
    return false;
  }

  void isFull(){

  }
};
int main(){
  queue q();
  q.enqueue(5);
}
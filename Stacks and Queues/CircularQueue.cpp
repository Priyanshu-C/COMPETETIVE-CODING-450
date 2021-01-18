#include<bits/stdc++.h> 
using namespace std; 
  
class CircularQueue{
  
  private:
  vector<int> ar;
  int front;
  int rear;
  int capacity;
  
  public:
  CircularQueue(int size)
  {
    front=-1;
    rear=-1;
    capacity=size;
  }

  void enQueue(int val)
  {
    if((front==0 and rear==capacity-1) or rear == (front-1)%(capacity-1))
    {
      cout<<"FULL"<<endl;
      return;
    }
    if(front==-1)
    {
      front = rear = 0;
      ar[rear]=val;
      return;
    }
    if(rear == capacity-1 and front!=0)
    {
      rear=0;
      ar[rear]=val;
      return;
    }
    rear++;
    ar[rear]=val;
    return;
  } 
  int deQueue()
  {
    if(front==-1)
    return -1;
    
    int data = ar[front];
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else if(front == capacity-1)
    front = 0;
    else 
    front++;
    return data;
  } 
  void displayQueue()
  {
    if (front == -1) 
        { 
            printf("\nQueue is Empty"); 
            return; 
        }
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",ar[i]); 
    }
    else
    {
      for (int i = front; i < size; i++) 
            printf("%d ", ar[i]); 
  
      for (int i = 0; i <= rear; i++) 
         printf("%d ", ar[i]); 
    }
  }
};
//Done By PRAKHAR  196032

#include <bits/stdc++.h>
using namespace std;
int queue[n], n = 100, front = - 1, rear = - 1;
void Insert() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}
void Delete() {
   if (front == - 1 or front>rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;
   }
}
void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      	cout<<queue[i]<<" ";
         
   }
   cout<<endl;
}
int size(){
	cout<<"The Size of Queue Is "<<endl;
	return rear+1;
}
bool isEmpty(){
	if(front==-1){
		return true;
	}
	return false;
}
int main() {
   int ch;
   cout<<"Enter The No. From Give Menu"<<endl;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Size of Queue"<<endl;
   cout<<"5) Queue is Empty"<<endl;
   cout<<"6) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<size()<<endl;
         break;
         case 5:
		 	if(isEmpty){
		 		cout<<"Queue is Empty : True"<<endl;
		 	}else{
		 		cout<<"Queue is Empty : False"<<endl;
			}
         	break;
         case 6: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=6);
   return 0;
}

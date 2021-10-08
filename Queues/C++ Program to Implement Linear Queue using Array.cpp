#include <iostream>
using namespace std;
int queue[50];
int n = 50;
int front = - 1;
int rear = - 1;

void Q_insertion() {
   int val;
   if (rear == n - 1)
      cout<<"Queue Overflow"<<endl;
   else {
    
      front = 0;
      cout<<" insert value in the queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}

void Delete() {
   if (front == - 1) {
      cout<<"Queue Underflow ";
   return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}

void Display_Q () {
   if (front == - 1 )
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}
int main() {
   int ch;
   cout<<"1) insertion of element to the queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
do {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: Q_insertion();
         break;
      case 2: Delete();
         break;
      case 3: Display_Q ();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);
   return 0;
}

/*

Output -

1) insertion of element to the queue
2) Delete element from queue
3) Display all the elements of queue
4) Exit
Enter your choice : 
1
 insert value in the queue : 
6
Enter your choice : 
1
 insert value in the queue : 
4
Enter your choice : 
1
 insert value in the queue : 
7
Enter your choice : 
3
Queue elements are : 6 4 7 
Enter your choice : 
2
Element deleted from queue is : 6
Enter your choice : 
3
Queue elements are : 4 7 
Enter your choice : 
2
Element deleted from queue is : 4
Enter your choice : 
3
Queue elements are : 7 
Enter your choice :

*/

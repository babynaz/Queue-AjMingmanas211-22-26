#include <iostream>
using namespace std;
#include "queue.h"

int main(int argc,char *argv[]) {
Queue q;
  
  q.enqueue(5);  
  q.enqueue(1);
  q.dequeue();//5
  q.enqueue(7);
  q.dequeue();//1
  
  q.enqueue(6);
  q.dequeue();////7
  q.dequeue();//6
  
 q.enqueue(8);
   q.enqueue(9);
   q.enqueue(10);
  cout<<"End of program"<<endl;

  }


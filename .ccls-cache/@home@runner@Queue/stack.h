#include "node.h"


class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
   void enqueue(int);
   int dequeue();
   Queue();
   ~Queue(); // dequeue all
};

Queue::Queue(){
  size=0;
  headPtr=NULL;
  tailPtr=NULL;
}

Queue::~Queue(){
  /*basically dequeue all*/
}


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
    /* Add head and tail for me please */
  
	
 }
}
int Queue::dequeue(){
  if(headPtr!=NULL){
     NodePtr t=head;
     int value= t->data;
    //
     /* Add head and tail for me please */
     delete t;
     return value;
  }
  cout<<"The queue is empty ";
  return -1;
}




void enqueue_struct(Queue& q,int x) {
 NodePtr new_node= new QNODE;
 if(new_node){ 
   	new_node->data=x;
		new_node->nextPtr=NULL;

   if(q.headPtr==NULL) q.headPtr=new_node;
    else q.tailPtr->nextPtr=new_node    ;          
	 q.tailPtr=new_node;
   q.size++;
 }

}
int dequeue_struct(Queue& q){
  if(q.size>0){
     NodePtr t=q.headPtr;
     int value= t->data;
    //
     q.headPtr= t->nextPtr;
     if(q.headPtr==NULL) q.tailPtr=NULL;
     delete t;
     return value;
     q.size--;
  }
  return -1;
}
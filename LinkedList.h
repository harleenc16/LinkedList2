//
//  LinkedList.h
//
//  Copyright Â© Tali Moreshet. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

template <class T = int>
class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // constructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
};

template <class T = int>
class LinkedList {
public:
    LinkedList();                                   // constructor
    ~LinkedList();                                  // destructor
    T deleteFromHead();                             // removes and returns content of head
    T deleteFromTail();                              // removes and returns content of tail
    void deleteNode(T data);                         // removes node with specified data
    void InsertToHead(T data);                      // insert node with data at the head
    void InsertToTail(T data);                      // insert node with data at the tail
    int getSize();                                  // returns size of linked list
    void print();                                   // prints linked list
private:
    Node<T>* head;                                 // head of linked list
};

template <class T = int>
class StackFromList{
public:
	StackFromList();
	~StackFromList();
	void push(T data);
	T pop();
	bool isEmpty();
private:
	Node<T>* top;
};


template <class T = int>
class QueueFromList{
public:
	QueueFromList();
	~QueueFromList();
	void enqueue(T data);
	T dequeue();
	bool isEmpty(); 
private:
	Node<T>* start; 
	Node<T>* back; 
};


/******* From here down is the content of the LinkedList.cpp file: ***********************/

 /* Implementation of Node */

 // default constructor
 template<class T>
 Node<T>::Node()
 {
 }
 
 // constructor
 template<class T>
 Node<T>::Node(const T& data, Node<T>* next)
 {
     this->data = data;
     this->next = next;
 }
 
 /* Implementation of linked list */

 // constructor
 template <class T>
 LinkedList<T>::LinkedList()
 {
     head = nullptr;
 }

 // destructor
 template <class T>
 LinkedList<T>::~LinkedList()
 {
	 Node<T>* current = head;
	 while( current != 0 ) {
	    Node<T>* next = current->next;
	     delete current;
	     current = next;
	 }
	 
	 head = 0;
	
 }

 template <class T>
 T LinkedList<T>::deleteFromHead()
 {
    /*** to be implemented ***/
		 
	 if(head==NULL){
		 return 0;
	 }
	 
	 T node = head->data;
	 Node<T>* temp = head; 
	 
	 head = head->next; 
  
	 delete temp;
	 
	 return node;
	  
 }


 template <class T>
 T LinkedList<T>::deleteFromTail()
 {
	
	 /*** to be implemented ***/
    if(head==NULL)
        return NULL;

    T toReturn ;

    if(head->next==NULL)
    {
        toReturn = head->data ; 
        delete(head) ; 
        head=NULL;
        return toReturn ;
    }
    
    Node<T>* temp=head;
    temp=head;
        while(temp->next->next!=NULL)
    temp=temp->next;

    toReturn = temp->next->data ; 
    delete (temp->next);
    temp->next = NULL;
    return toReturn ; 


 }
	 
template <class T>
void LinkedList<T>::deleteNode(T data)
{
	T node = data; 
	Node<T>* tail;  
	 
	if (head != 0)                     
	if (head == tail && node == head->data) {
		 
	delete head;                      
	head = tail = 0;

   }


	else if (node == head->data) { 

	Node<T> *tmp = head;
	head = head->next;
	 delete tmp; 
	              
     }

	 else {                        

	  Node<T> *pred, *tmp;

	 for (pred = head, tmp = head->next; 
	  tmp != 0 && !(tmp->data == node);
	  
	  pred = pred->next, tmp = tmp->next);
	  
	  if (tmp != 0) {
      pred->next = tmp->next;
      if (tmp == tail)
      tail = pred;
	  delete tmp;

	        }

	   }
			 
}
 

 template <class T>
 void LinkedList<T>::InsertToHead(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (head == nullptr)
         head = newNode;
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }


 template <class T>
 void LinkedList<T>::InsertToTail(T data)
 {
	 Node<T> * n = new Node<T>();
	 Node<T> * tail;
	 
	 n->data = data;
	 n->next = NULL;
	 
	 if(head == NULL){
		 head = n;
		 
	 }
	
	 else{
		 tail= head;
		 while(tail->next != NULL)
			 tail = tail->next;
		 
		 tail->next = n;
	 }
	
 }


 template <class T>
 int LinkedList<T>::getSize()
 {
     /*** to be implemented ***/
	 int count =0;
	 Node<T>* current = head;
	 while(current != NULL){
		 count++;
		 current= current -> next;
	 }
	 
	 return count; 
	 
 }


 template <class T>
 void LinkedList<T>::print()
 {
     if (head == nullptr)
     {
         cout << "Linked list is empty" << endl;;
         return;
     }
     
     cout << head->data << " ";
     
     if (head->next == nullptr)
     {
         cout << endl;
         return;
     }
 
     Node<T>* currNode = head->next;
     Node<T>* prevNode = head;
 
     
     while (currNode->next != nullptr)
     {
         cout << currNode->data << " ";
         prevNode = currNode;
         currNode = currNode->next;
     }
 
     cout << currNode->data << endl;
     return;
}
 
 
template <class T>
StackFromList<T>::StackFromList()
{
	top = 0;
}

template <class T>
StackFromList<T>::~StackFromList()
{
 
 Node<T>* current = top;
 while( current != 0 ) {
    Node<T>* next = current->next;
     delete current;
     current = next;
 }
 
 top = 0;	
 	
}

template <class T>
void StackFromList<T>::push(T data)
{
	
	
	Node<T>* temp;
	temp = new Node<T>();
	
	if(!temp){
		exit(1);
	}
	
	temp->data = data;
	temp->next = top;
	
	top = temp;
	
}


template <class T>
T StackFromList<T>::pop()
{
	Node<T>* temp;
	
	T node = top->data;
	
	if(top == NULL){
		exit(1);
		
	}
	
	else{
		temp=top;
		top = top->next;
		temp->next = NULL;
	}
	
	return node;
}

template <class T>
bool StackFromList<T>::isEmpty(){
	
	
	if(top==NULL){
		return true;
	}
	
	else{
		return false;
	}
	
}

template <class T>
QueueFromList<T>::QueueFromList()
{
	start  = back = 0;
	
}

template <class T>
QueueFromList<T>::~QueueFromList()
{
    Node<T>* current = start;
    while( current != 0 ) {
       Node<T>* next = current->next;
        delete current;
        current = next;
    }
 
    start = 0;
	
}


template <class T>
void QueueFromList<T>::enqueue(T data)
{
	
	Node<T>* temp = new Node<T>();
	
	temp->data= data;
	temp->next = NULL;
	
	if(back ==NULL){
		start = back = temp;
	}
	
		back->next=temp;
		back=temp;
	
}

template <class T>
T QueueFromList<T>::dequeue()
{
	
	T node = start->data;
	
	if(start == NULL){
		exit(1);
	}
	
	Node<T>* temp = start;
	start = start->next;
	
	if(start == NULL){
		back = NULL;
	}
	
	delete (temp);
	
	return node;
	
}
 
 
template <class T>
bool QueueFromList<T>::isEmpty()
{
	if(start==NULL){
		return true;
	}
	
	else{
		return false;
	}
	
} 
     
#endif /* LinkedList_h */
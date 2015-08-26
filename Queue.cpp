#include "StdAfx.h"
#include "Queue.h"
#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename elementType>
Queue<elementType>::Queue(void)
{
	numitems = 0;
	backPtr = NULL;
	frontPtr = NULL;
}

template <typename elementType>
void Queue<elementType>::enqueue(elementType newitem){
	try{
		//create a new node
		QueueNode<elementType> *newPtr = new QueueNode<elementType>;
		//set data portion of new node
		newPtr->item = newitem;
		newPtr->next = NULL;
		if (backPtr==NULL)
			//insertion to empty queue
			frontPtr = newPtr;
		else
			//insertion into nonempty queue
			backPtr->next = newPtr;
		numitems++;
		backPtr = newPtr; //new node is at back
		
	}
	catch(exception e ){
		allocation_error();
		cout<<e.what();
	}

}

template <typename elementType>
void Queue<elementType>::dequeue(){
	//Exception thrown

	if (numitems==0){
		try{
		list_empty();
		}
		catch(exception e){
			cout<<e.what();
		}
	}
	else{
		QueueNode *tempPtr = frontPtr;
		if (frontPtr == backPtr){ //then one ne node in queue
			frontPtr = NULL;
			backPtr = NULL;
			numitems--;
		}
		else{
			frontPtr = frontPtr->next;
			tempPtr->next = NULL;
			delete tempPtr;
			numitems--;
		}

	}
}
template <typename elementType>
void Queue<elementType>::dequeueAll(){
	for (int i = 0; i<size();i++)
		dequeue();
	frontPtr = NULL;
	backPtr = NULL;
	numitems = 0;
}

template <typename elementType>
int Queue<elementType>::size(){
	return numitems;

}

template <typename elementType>
elementType Queue<elementType>::peek(){
	if (frontPtr==NULL){
		try{
			list_empty();
	}
	catch(exception e){
		cout<<e.what();
			
	}
	return NULL;
	}
	return frontPtr->item;
}
// Exception Handlers
template <typename elementType>
void Queue<elementType>::list_empty(){

	throw std::exception("QueueException: List is empty ");

}
template <typename elementType>
void Queue<elementType>::allocation_error(){
	throw std::exception("QueueException: Unable Allocate Memory");
}
template <typename elementType>
Queue<elementType>::~Queue(void)
{
}

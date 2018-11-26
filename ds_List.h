
#ifndef LIST_H_
#define LIST_H_


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<class Q, class T>
class List{

	class Node{
		

		public:
			Q* key;
			T* data
			Node* next;
			Node* prev;

			Node() : key(NULL), data(NULL), next(NULL), prev(NULL) {};
			~Node(){
				if (next){
					delete next;
				}
				if (key){
					delete key;
				}
				if (data){
					delete data;
				}
			}
			Q getKeyValue() const {
				return *key;
			}
			Q& getKey(){
				return *key;
			}
			T getDataValue() const {
				return *data;
			}
			T& getData(){
				return *data;
			} 
		
	};

	Node *head;
	Node *tail;
	Node *iter;
	int size;
	bool ordered;

	public:
		List() : head(NULL), tail(NULL), iter(NULL), size(0) {};
		~List(){
			delete head;
		}
		int getSize() const { return size; }
		bool isEmpty() const { return size == 0; }
		void addNode(const Q& nkey, const T& ndata);
		void removeNode(const Q& rkey);
		Node* getNode(const Q& fkey);


	
};


template<class Q, class T>
void List<Q,T>::addNode(const Q& nkey, const T& ndata){

	if (isEmpty()){
		head = new Node();
		head->key = nkey;
		head->data = ndata;
		tail = head;
		size = 1;
	}
	else if (!getNode(nkey)){
		
	}

}

template<class Q, class T>
List<Q,T>::Node* List<Q,T>::getNode(const Q& fkey){

	if (isEmpty()){
		return NULL;
	}
	Node* iterator = head;
	while(iterator && *(iterator->key) <= fkey){
		if ( *(iterator->key) == fkey){
			return iterator;
		}
		else{
			iterator = iterator->next;
		}
	}
	return NULL;
}





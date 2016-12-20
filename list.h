#ifndef  LIST_H
#define LIST_H

#include "node.h"

class List{
	public:
		List();
		List (const List&, bool);
	
		~List();
		bool isEmpty() const;
		int getNumNodes() const;
		void append(Node*);
		void insertNode (Node*);
		void deleteNode(string); //deletes node by val
		void deleteNode (int); //deletes node by pos
		void displayAscending() const;

		Node* getHead()const{
			return head;
		}

		string getName();
		int getAge();

		void bubbleSortAscending();
		void bubbleSortDescending();

	protected:
		Node* head;


};

#endif

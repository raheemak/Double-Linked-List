#include "list.h"

class DoubleLinkedList : public List { 
	
	public: 

		DoubleLinkedList():List(){
			tail = NULL;
		}

		DoubleLinkedList(List const & list){
			Node * curr = list.getHead();
			while (curr){ 
				this -> append (new Node (new Student ( curr -> getStudent())));
				curr = curr->getNext();
			}
		}

		void copy(List const & list, bool sort){
			Node * curr = head;
			while (curr){
				if (sort)
					this -> insert (new Node (new Student (curr->getStudent())));
				else 
					this ->append (new Node (new Student (curr->getStudent())));
				curr = curr->getNext();
			}
		}


		void append (Node* node){
			if (!head)
				head = tail = node;
			else { 
				tail->setNext(node);
				node->setPrev(tail);
				tail = node;
			}
		}


		void insert (Node* node){
			Node *curr;
			
			if (!head){
			       cout << "no head..."<<endl;	       
				head = tail = node;
			}
			else {
				curr = head;
				while (curr->getNext()) {
					cout << "made it to the loop!";
					if (curr->getNext()->getAge() >= node->getAge())
						break;
					else
						curr = curr->getNext();
				}

				if (!curr->getPrev() && curr->getAge()>=node->getAge()){
					head = node;
					node->setNext(curr);
					curr->setPrev(node);
				}
				
				else {
	                               	node -> setNext (curr->getNext());
		   			node -> setPrev (curr);	               
					curr -> setNext (node );
				}
				if (!node->getNext())
						tail = node;
			}	
		}

		void deleteNode (int age){
			Node *curr;
			
			if (!head)
				return;
			else {
				bool found = false;
				curr =head; 
				while (curr->getNext()) { 
					if (curr->getAge() == age){
						found = true;
						break;
					}
					else 
						curr = curr->getNext();
				}

				if (found){
					if (!curr->getPrev()){
						if (!curr->getNext()){
							tail = NULL;
							delete head;
							head= NULL;
						}
						else {
							head = head->getNext();
							head->setPrev(NULL);
							delete curr;
						}
					}
					else {
						curr->getPrev()->setNext(curr->getNext());
						curr->getNext()->setPrev(curr->getPrev());
						if (!curr->getNext())
							tail = curr->getPrev();
						delete curr;
					}
				}
			}
		}

                void displayDescending() const{
                        Node * curr =tail;
                        if (!head){
                                cout << "Empty List... " << endl;
                        }
                        else {
                                cout << "----\nTotal Elements: " << getNumNodes()<< endl;

                                while (curr){
                                        cout << "----" <<endl;
                                        curr->getStudentInfo();
                                        curr = curr->getPrev();
                                };

                                cout << "----" <<endl;
                        }
                }


	private: 
		Node * tail;
};

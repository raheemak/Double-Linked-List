#include "list.h"

List::List(){
	head = NULL;
}

List::List (const List& list, bool sorted){
	Node* curr = list.getHead();
	
	//list.displayAscending();
	//cout << "sorted" << sorted << endl;	

	Student newStudent;
	if (! (list.isEmpty())){
		//cout << "not empty!";
		while (curr){
			//cout << "in curr loop of list copy function " << endl;
			if (sorted){
				newStudent = curr->getStudent();
				this->insertNode(new Node (newStudent));
			}else {
				//cout << "here? " << endl;
				//curr->getStudent()->output();
				newStudent = curr->getStudent();
				this->append(new Node (newStudent));
			}
			curr = curr->getNext();
		}
	}
}
                
List::~List(){
	//cout << "destructor error..." << endl;
	Node *curr  = head;
	Node *temp;
		
	if (curr){
		while (curr){
			temp = curr->getNext();
			//node destructor will delete student 
			delete curr;
			curr = temp;
		}
	}		
	//end of loop both curr and temp should be null 
}


//doesnt work???
bool List::isEmpty() const{
	bool val = true;
	if (head)
		val = false;
	return val;
}

int List::getNumNodes() const{
	int num = 1;
	Node* curr  = head;
	while (curr->getNext()){
		num++;
		curr = curr->getNext();
	}
	return num;
}

void List::append(Node* node){
	//cout << "append function called... " <<endl;
	Node* curr = head;
	if (!head)
		head = node;
	else{
		while (curr->getNext())
			curr  = curr->getNext();
		curr->setNext (node);
	}
}


void List::insertNode(Node* node){

	Node* curr;
	Node* prev;
	
	//if head is null
	if (!head)
		head = node;

	//setting a new head
	else if (node->getAge()<= head->getAge()){
		//cout << "first" <<endl;
		curr = head;
		head = node;
		head->setNext(curr);
		curr = NULL;
	}
	
	//inserting somewhere in body 
	else{
		//cout << "second" << endl;
		prev = head;
		curr = head->getNext();
		
		while (curr){
			if (prev->getAge()<= node->getAge() && curr->getAge() >= node->getAge())
				break;
			else{
				curr  = curr->getNext();
				prev = prev->getNext();
			}
		}
		//curr -> getStudentInfo();
		//prev -> getStudentInfo();

		
		prev->setNext(node);
		//prev->getNext()->getStudentInfo();
		node->setNext(curr);
		}
	//cout << "quitting function ... " << endl;	
}

void List::deleteNode(string val){
	Node *curr = head;
	int pos = 0;
	bool found = false;
	
	//finds pos where string to delete is and then passes that to function that deletes by position
	while (curr){
		if (val == curr->getName()){
			//cout << "error here?";
			deleteNode(pos);
			found = true;
			break;
		}
		else{
			//cout << "error here (!)" <<endl;
			curr = curr->getNext();
			pos++;
		}
	}

	if (!found){
		cout << "----\nElement not found...\n-----" <<endl;
	}	
}

void List::deleteNode (int pos){

	Node *curr;
	Node *prev;
	
	if (pos<0 || pos >getNumNodes())
		cout << "Out of bounds...";
	else{
		//delete head
		if (pos == 0){
			curr = head;
			head = curr->getNext();
			delete curr;
			curr = NULL;
		}//if head	
		
		//otherwise deleting from body 
		else {		
			prev = head;
			curr = head->getNext();
			
			//starting from second element in list 
			//(already checked if pos was head)
			int counter = 1;
	
			//don't have to check when end of list reached because pos is in bounds of list size
			while (pos!= counter){
				curr = curr->getNext();
				prev = prev->getNext();
				pos++;
			}//while loop 

			prev->setNext(curr->getNext());
			delete curr;
			curr = NULL;
			
		}//else: not head
	}//else: not out of bounds
}//delete function 

void List::displayAscending() const{
	Node * curr =head;
	if (!head){
		cout << "Empty List... " << endl;
	}
	else {
		cout << "----\nTotal Elements: " << getNumNodes()<< endl;

		while (curr){
			//cout << "in curr loop for display ascending... " <<endl;
			cout << "----" <<endl;
			curr->getStudentInfo();
			curr = curr->getNext();
		};
	
		cout << "----" <<endl;
	}
}	


//implementation of bubble sort on list
//sorts in increasing order by age

/*bubble sort algorithm with array 
 * void bubbleSort (int a[], int n ){ 
 * 	for (int pass = 1; pass< n; pass++){
 * 		for (int x = 0; x< n-pass; x++){
 * 			if (a[x] > a[x+1])
 * 				swap (a[x],a[x+1]);
 * 		}
 * 	}
 * }
 */

void List::bubbleSortAscending(){
	Node * end = head;
	Node* traversal;
	Node * temp;

	cout << "1"<<endl;
	while (end!=head && head && head->getNext()){
		traversal= head;
		cout << 2 <<endl;
		while (traversal!=end){
			if (traversal->getAge() > traversal->getNext()->getAge()){
				//swap
				temp = traversal->getNext();
				traversal->setNext (temp->getNext());
				temp->setNext (traversal);
			}
			traversal = traversal->getNext();
		}

		//set new end to the element prior to current end
	
		cout << 3 <<endl;
		temp = head;
		while (temp->getNext()!=end)
			temp =temp->getNext();

		end = temp;
	}

	cout <<4 <<endl;
	/*pseudocode
 * 		while end!= head and head and head->next
 *			find new ending
 *			iterate from beginning to end
 *				while traversal is not equal to the end
 *					if traversal is greater than traversal next
 *						swap
 *						temp = traversal.getnext
 *						traversal.setnext(temp.getnext)
 *						temp.setnext(traversal)
 *					traversal = traversal.getnext
 */

}


//bubble sort: sorts in descending order by age
void List::bubbleSortDescending(){
}  

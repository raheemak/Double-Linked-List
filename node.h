#include <iostream>
#include "student.cpp"

class Node {
  public:
    // Constructors – at least the default constructor and one of the other two
   	 Node();			// default Constructor
   	 Node( Student);	// Constructor that takes a student object address as an argument
    	Node( string fname, string lname, char mi, int ss, int age );	// Constructor that takes the individual data
    // members required by the Student object and
    // constructs the student object accordingly
 
	~Node();//delete sPtr; 
    // Public methods as needed – at least the following two		
    	Node *getNext();	// accessor function to retrieve the data member next
	Node *getPrev(){
		return prev;
	}

	void setNext( Node * node);	// mutator function to set the data member next 

	void setPrev (Node * node){
		prev = node;
	}

 	Student getStudent();
 	void getStudentInfo();

	string getName();
	int getAge();
	
	void input();
  private:
    Student  *sPtr;		// pointer to the Student object
    Node *next, *prev;
};

#include "node.h"

Node::Node(){
	sPtr = new Student();
	prev = next= NULL;
}

Node::Node( Student student){
	sPtr = new Student (student);
	prev = next = NULL;
}

Node::~Node(){
	if (sPtr){
		cout << "error in node desturctor"<<endl;
		delete sPtr;
		sPtr = NULL;
	}
}

Node::Node( string fname, string lname, char mi, int ss, int age ){
	sPtr = new Student (fname, lname, mi, age, ss);
	prev = next = NULL;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext( Node * node){
	next = node;
}

Student  Node::getStudent(){
	return *sPtr;
}

void Node::getStudentInfo(){
	cout << "HERE " <<endl;
	sPtr->output();
}

string Node::getName(){
	return sPtr->getFirst();
}

int Node::getAge() {
	return sPtr->getAge();
}

void Node::input(){
	sPtr->input();
}

#include "list.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

main(){
	ifstream file;
	string ans, first, last;
	int social, age;
	char mi;
	
	List list;
	Node* temp;
	while (ans!= "File" || ans!="Keyboard"){
		cout << "Enter File to enter students by a file or 'Keyboard' to enter users manually: ";
		cin >> ans;
	}
	
	if (ans == "File"){
		while (ans!= "Keyboard"){//if someone enters this as filename will cause error during else if statement
			cout << "Enter a file name: ";
			cin >> ans;
		}
		try {
			file.open(ans);	
			while (!file.eof()){
				cin >> first >> last >> mi >> age >> social;
				temp = new Node (first, last, mi, age, social);
				list.insertNode (temp);
			}
		}
		catch (int var){
			ans == "Keyboard";
		}
		
		
	}

	else if (ans == "Keyboard"){
		while (ans!= " "){
			cout << "Type 'QUIT' to quit or 'CONTINUE' to continue: " ;
			cin >> ans;
			if (ans=="QUIT")
				break;
			temp = new Node();
			temp->input();	
			list.insertNode(temp);	
		}
	}

	list.displayAscending();
	
	cout << "Enter file name to enter data into: ";
	cin >> ans;

	file.close();

	ofstream fileWrite;
	fileWrite.open(ans);
	//fileWrite << list.displayAscending();
	fileWrite.close();

	/*//testing functions.........................................
	Student *student = new Student();
	student->output();
	cout <<endl;


	//cout << "testing node output... " <<endl;
	Node* studentNode = new Node(student);
	//studentNode->getStudentInfo();

	cout <<endl;

	
	List newList;
	//newList.displayAscending();
	//cout << endl;
	Node* node = new Node ("Raheema", "Kadwa", 'a', 1, 18);
	
	newList.append(node);
	//newList.displayAscending();
	//cout <<endl;
	newList.append(studentNode);

	Student *newS = new Student();
	newS->input();
	Node * next = new Node(newS);

	//newList.append(studentNode);
	//newList.displayAscending();

	newList.insertNode(next);	
	//newList.displayAscending();

	//cout << newList.isEmpty() <<"empty??? " <<  endl << endl ;
	//List second = List (newList, false);
	//second.displayAscending();

 	newList.deleteNode("raheemakadwa");
	newList.deleteNode("Raheema");	
	newList.displayAscending();
	*/
}

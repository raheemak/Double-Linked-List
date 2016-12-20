/*Raheema Kadwa
 * Computer Algorithms 
 * Double Linked List Lab 
 */

#include "d_list.cpp"

main(){
	DoubleLinkedList list; ;
	string ans = ".";

	Node *temp;

        while (ans!= " "){
                        cout << "Type 'QUIT' to quit or 'CONTINUE' to continue: " ;
                        cin >> ans;
                        if (ans=="QUIT")
                                break;
                        temp = new Node();
                        temp->input();
                        list.insert(temp);
                }
	//List newList(list, false);

	list.append(new Node());

	cout << "Displaying acending.... " <<endl <<endl;
	list.displayAscending();
	
	cout <<"deleting node...";
	list.deleteNode (18);

	cout << "Displaying descending... "<<endl <<endl;
	list.displayDescending();

	
	//list.bubbleSortAscending();
	

}

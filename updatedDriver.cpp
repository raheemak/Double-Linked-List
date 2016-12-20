#include "list.h"

main(){
	List list;
	string ans = ".";

	Node *temp;

        while (ans!= " "){
                        cout << "Type 'QUIT' to quit or 'CONTINUE' to continue: " ;
                        cin >> ans;
                        if (ans=="QUIT")
                                break;
                        temp = new Node();
                        temp->input();
                        list.insertNode(temp);
                }
	//List newList(list, false);


	list.displayAscending();
	list.bubbleSortAscending();
	list.displayAscending();

}

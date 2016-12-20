#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Student{
	public:

		Student(){
			fname = "Bob";
			lname = "Cooper";
			mi = 'D';
			age = 40;
			social = 1111111111;
		}


		Student (string first, string last, char middle, int a, int s){
			fname = first;
			lname = last;
			mi = middle;
			age = a;
			checkAge();
			social = s;
			checkSocial();
		}

		Student(const Student & student){
			fname = student.getFirst();
			lname = student.getLast();
			mi = student.getMiddle();
			age = student.getAge();
			social = student.getSocial();
		}

		Student (Student * student){
			fname = student->getFirst();
			lname = student->getLast();
			mi = student->getMiddle();
			age = student->getAge();	
			social = student->getSocial();
		}

		void input(){
			cout <<"Please enter your name in the format FIRST MI LAST: ";
			cin >> fname >> mi >> lname;
			cout <<"Please enter your age: " ;
			cin >> age;
			checkAge();
			cout <<"Please enter your social secutity # in the form: xxxxxxxxx: " ;
			cin  >> social;
			checkSocial();
			cout <<endl;
		}


		void output(){
			cout <<"Name: " <<fname <<" " <<  mi << ". " <<lname <<endl;
			cout << "Age: " << age <<endl;
			cout << "Social security: xxxxx" << social%10000 <<endl;
		}
	
		string getFirst()const{
			return fname;
		}

		string getLast()const{
			return lname;
		}

		char getMiddle()const{
			return mi;
		}

		int getAge()const{
			return age;
		}

		int getSocial()const{
			return social;
		}
	
	private:
	
		void checkAge(){
			if (age > 100 || age < 5)	
			age = 18;
		}

		void checkInitial(){
		}

		void checkSocial(){
			if (social > 999999999 || social < 1000000000)
				social = 111111111;
		}
 		
		int age, social;
		string fname, lname;
		char mi;
};


/*//testing....
main(){
	Student * sptr = new Student();
	sptr->output();
	Student newStudent(sptr);
	newStudent.output();
}*/

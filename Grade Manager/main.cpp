#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <fstream>
using std::ifstream;
using std::ofstream;

#define max_course 5

class Student{
private: 
	pair<int,string> nameID;
	double engMark, mathMark, physMark, chemMark, musMark;
	double grade;
public:
	void inpMark();
	void inpMark(ifstream& inp);
	void average();
	void inpNameID();
	void inpNameID(ifstream& inp);
	int rID();
	pair<int,string> rnID();
	void printMarkG();
	void uMark(string topic);
	double rMK(string topic);
	double rGrade();
};

//get input from standard input stream
void Student::inpMark(){
	cout << "Please input mark in English: ";
	cin >> engMark;
	cout << "Please input mark in Mathematics: ";
	cin >> mathMark;
	cout << "Please input mark in Physics: ";
	cin >> physMark;
	cout << "Please input mark in Chemistry: ";
	cin >> chemMark;
	cout << "Please input mark in Music: ";
	cin >> musMark;
}

//get input from input file stream
void Student::inpMark(ifstream& inp){
	inp >> engMark >> mathMark >> physMark >> chemMark >> musMark;
}

inline void Student::average(){
	grade = (engMark + mathMark + physMark + chemMark + musMark) / max_course;
}

//input name and ID from standard input stream into a pair
void Student::inpNameID(){
	string name;
	int ID;
	cout << "What is the student name?" << endl;
	getline(cin,name);
	cout << "What is the student's identification number?" << endl;
	cin >> ID;
	nameID = std::make_pair(ID,name);
}

//input name and ID from input file stream into a pair
void Student::inpNameID(ifstream& inp){
	string name;
	int ID;
	inp.ignore();
	getline(inp,name);
	inp >> ID;
	nameID = std::make_pair(ID,name);
}

inline int Student::rID(){
	return this->nameID.first; //returns just the ID
}

inline pair<int,string> Student::rnID(){
	return this->nameID; //returns the pair containing ID and name
}

void Student::printMarkG(){
	cout << "English mark: " << this->engMark << endl;
	cout << "Mathemetics mark: " << this->mathMark << endl;
	cout << "Physics mark: " << this->physMark << endl;
	cout << "chemMark mark: " << this->chemMark << endl;
	cout << "musMark mark: " << this->musMark << endl;
	cout << "Total grade: " << this->grade << endl;
}

//update marks for the subject specified in argument
void Student::uMark(string topic){
	if(topic == "english" || topic == "English"){
		cout << "Current English mark: " << this->engMark << ". Insert new mark: ";
		cin >> engMark;
	} else if(topic == "math" || topic == "Math"){
		cout << "Current Math mark: " << this->mathMark << ". Insert new mark: ";
		cin >> mathMark;
	} else if(topic == "physics" || topic == "Physics"){
		cout << "Current Physics mark: " << this->physMark << ". Insert new mark: ";
		cin >> physMark;
	} else if(topic == "chemistry" || topic == "Chemistry"){
		cout << "Current Chemistry mark: " << this->chemMark << ". Insert new mark: ";
		cin >> chemMark;
	} else if(topic == "music" || topic == "Music"){
		cout << "Current Music mark: " << this->musMark << ". Insert new mark: ";
		cin >> musMark;
	}
}

//return mark for the subject specified in argument
double Student::rMK(string topic){
	if(topic == "english" || topic == "English"){
		return this->engMark;
	} else if(topic == "math" || topic == "Math"){
		return this->mathMark;
	} else if(topic == "physics" || topic == "Physics"){
		return this->physMark;
	} else if(topic == "chemistry" || topic == "Chemistry"){
		return this->chemMark;
	} else if(topic == "music" || topic == "Music"){
		return this->musMark;
	}
}

inline double Student::rGrade(){
	return this->grade;
}

//add new student by getting input from standard input
void addStudent(vector<Student>& myClass){
	Student newStud;
	newStud.inpNameID();
	newStud.inpMark();
	newStud.average();
	myClass.push_back(newStud);
}

void findStud(vector<Student> myClass){
	cout << "Insert the ID of student who's information you wish to view: ";
	int ID;
	cin >> ID;
	
	for(auto& c : myClass){
		if(c.rID()==ID){
			std::pair<int,string> temp = c.rnID();
			cout << "ID: " << temp.first << endl;
			cout << "Name: " << temp.second << endl;
			c.printMarkG();
		}
	}

}

void displayStuds(vector<Student> myClass){
	for(auto& c : myClass){
			std::pair<int,string> temp = c.rnID();
			cout << "ID: " << temp.first << endl;
			cout << "Name: " << temp.second << endl;
			c.printMarkG();
	}
}

//load information of students from a file into a vector of Students
void loadInfo(vector<Student>& myClass){
	ifstream input("in.txt");
	while(!input.eof()){
		Student newStud;
		newStud.inpNameID(input);
		newStud.inpMark(input);
		newStud.average();
		myClass.push_back(newStud);
	}
}

//update student marks
void updateStud(vector<Student>& myClass){

	cout << "Insert ID of student who's mark you wish to update: ";
	int ID, chk=0;
	cin >> ID;

	for(auto& c : myClass){
		if(c.rID()==ID){
			++chk;
			cout << "Which mark do you wish to update?" << endl;
			string choice;
			cin >> choice;
			c.uMark(choice);
			c.average();
		} 
	}

	if(chk==0){
		cout << "Student with that ID not found, ensure correct key has been entered." << endl;
	}

}

//update all student marks
void uAllStud(vector<Student>& myClass){
	for(auto& c: myClass){
		auto temp = c.rnID();
		cout << "ID: " << temp.first << "\tName: " << temp.second << endl;
		c.uMark("english");
		c.uMark("math");
		c.uMark("physics");
		c.uMark("chemistry");
		c.uMark("music");
		c.average();
	}
}

//first range-for loop update the edits in the "in.txt" and the second loop stores changes along with the computed grade in "out.txt"
void savenx(vector<Student> myClass){
	ofstream output("in.txt");
	for(auto& c : myClass){
		std::pair<int,string> temp = c.rnID();
		output << temp.second << endl;
		output << temp.first << endl;
		output << c.rMK("english") << endl;
		output << c.rMK("math") << endl;
		output << c.rMK("physics") << endl;
		output << c.rMK("chemistry") << endl;
		output << c.rMK("music") << endl;
	}
	ofstream output2("out.txt");
	for(auto& c : myClass){
		std::pair<int,string> temp = c.rnID();
		output2 << temp.second << endl;
		output2 << temp.first << endl;
		output2 << c.rMK("english") << endl;
		output2 << c.rMK("math") << endl;
		output2 << c.rMK("physics") << endl;
		output2 << c.rMK("chemistry") << endl;
		output2 << c.rMK("music") << endl;
		output2 << c.rGrade() << endl;
	}
	exit(0);
}

void menu(vector<Student>& myClass){

	loadInfo(myClass);
	system("clear");

	do {
		cout << "------------------------------------------------------------------------" << endl;
		cout << "\n\n\n\n\n 	     WELCOME TO STUDENT REPORT MAINTENANCE PROGRAM" << endl;

			cout << "\t 	     1) Add Student\n" <<
					"\t 	     2) Update Single Student Marks\n" <<
					"\t 	     3) Update All Student Marks\n" <<
					"\t 	     4) Find Student\n" <<
					"\t 	     5) Display Student Infos\n" << 
					"\t 	     6) Save & Exit" << endl;

		cout << "\n\n\n\n------------------------------------------------------------------------" << endl;
		
		int choice;
		cin >> choice;
		cin.ignore();

		switch(choice){
			
			case 1: 
				system("clear"); 
				addStudent(myClass); 
				cout << "Hit return for menu."; 
				cin.ignore();
				cin.get(); 
				system("clear"); 
			break;
			
			case 2: 
				system("clear"); 
				updateStud(myClass); 
				cout << "Hit return for menu."; 
				cin.ignore();
				cin.get(); 
				system("clear"); 
			break;
			
			case 3: 
				system("clear"); 
				uAllStud(myClass); 
				cout << "Hit return for menu."; 
				cin.ignore();
				cin.get(); 
				system("clear"); 
			break;
			
			case 4: 
				system("clear"); 
				findStud(myClass); 
				cout << "Hit return for menu."; 
				cin.ignore();
				cin.get(); 
				system("clear"); 
			break;

			case 5: 
				system("clear"); 
				displayStuds(myClass); 
				cout << "Hit return for menu."; 
				cin.get(); 
				system("clear"); 
			break;
			
			case 6: 
				system("clear"); 
				savenx(myClass); 
			break;
		}
		
	} while (1);

}

int main(void){

	vector<Student> myClass;
		
	menu(myClass);

	return 0;
}

/*

-----------------------------------Text Analysis--------------------------------------------------------------------
The availability of computers with string-manipulation capabilities has resulted in some rather
interesting approaches to analyzing the writings of great authors. Much attention has been focused
on whether William Shakespeare ever lived. Some scholars find substantial evidence that
Christopher Marlowe actually penned the masterpieces attributed to Shakespeare. Researchers
have used computers to find similarities in the writings of these two authors. This project
examines three methods for analyzing texts with a computer.

1) the number of occurrences of each letter of the alphabet in the complete text
2) the number of one-letter words, two-letter words, three-letter words, and so on, appearing in the complete text
3) the number of occurrences of each different word in the complete text
--------------------------------------------------------------------------------------------------------------------

*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <cctype> //required for tolower and ispunct
#include <algorithm> //required for find and remove_if

#define MAXLEN 20

void menu(vector<string>);
//gets input parameters and prints occurences of each alphabet found in input
void letterAnalysis(vector<string>);
//gets input parameters and prints length of words and how many times words of that length occured
void wordLengthAnalysis(vector<string>);
//gets input parameters and prints how many times certain words occured
void wordAnalysis(vector<string>);
//prints out the input text
void printout(vector<string>);

int main(void){
		
		vector<string> input;
		string partialInput;

		cout << "Insert as much text as you would like for analysis, ending with a 'xxx': " << endl;
		while (cin >> partialInput && partialInput != "xxx"){
			input.push_back(partialInput);
		}

		char key;
		do{
			menu(input);

			cout << "Would you like to return to menu? Y/N?	";
			cin >> key;
		} while (key == 'y' || key == 'Y');
		
		
		cout << "\nThank you for using our text analysis program. Until next time.\n" << endl;
		return 0;
}

void menu(vector<string> input){
	
	int choice;
	cout << "\nPlease select from the following menu: \n\n" <<
		"1) Show occurences of each alphabet \n" <<
		"2) Show occurences of words with with variable lengths \n" <<
		"3) Show how many times a certain word occured \n"
		"4) Show text that was inputted \n" << endl;
	cin >> choice;

	switch (choice){

	case 1:	cout << "\nWelcome to function letter analysis\n" << endl;
		letterAnalysis(input);
		cout << '\n';
		break;

	case 2:	cout << "\nWelcome to word length analysis\n" << endl;
		wordLengthAnalysis(input);
		cout << '\n';
		break;

	case 3:	cout << "\nWelcome to word repetition analysis\n" << endl;
		wordAnalysis(input);
		cout << '\n';
		break;

	case 4:	printout(input);
		cout << '\n';
		break;

	default: cout << "\nInvalid option, please select from the listed options." << endl;
		break;
	}

}

//input: vector of strings holding user input
//output: a table printing how many times an alphabet was present in the user input
//purpose: to analyze each alphabet in user input
void letterAnalysis(vector<string> input){
	
	int alphCtr[26] = { 0 };

	for (int i = 0, asci = 65, asci2 = 97; i != 26; ++i, ++asci, ++asci2){
		for (auto word : input){
			for (auto ch : word){
				if (ch == asci || ch == asci2){
					alphCtr[i]++;
				}
			}
		}
	}

	for (int i = 0, asci = 65, asci2 = 97; i != 26; ++i, ++asci, ++asci2){
		if (alphCtr[i] == 0)
			continue;
		cout << static_cast<char>(asci) << " or " << static_cast<char>(asci2) << " appeared " << alphCtr[i] << " times." << endl;
	}
}
//input: vector of strings holding user input
//output:a table printing how many times a word of certain length appeared
//purpose: to analyze each word length in user input
void wordLengthAnalysis(vector<string> input){

	int ctr[MAXLEN] = { 0 };
	vector<string>::iterator it;

	for (it = input.begin(); it != input.end(); ++it){
		for (int i = 0; i != MAXLEN; ++i){
			if ((*it).length() == i){
				ctr[i]++;
			}
		}
	}

	for (int i = 0; i != MAXLEN; ++i){
		if (ctr[i] == 0)
			continue;
		cout << "word of length " << i << " appeared " << ctr[i] << " times." << endl;
	}

}
//input: vector of strings holding user input
//output: a table printing how many times a word repeated 
//purpose: to analyze each word's occurence in user input
void wordAnalysis(vector<string> input){

	map<string, int> appearance;
	
	for(auto& ch : input){
		//upper cases are ignored; same counter is incremented
		for(auto& cch: ch){
			cch = tolower(cch);
		}
		//punctuations are ignored; same counter is incremented
		ch.erase(remove_if(ch.begin(), ch.end(), ispunct), ch.end());
		++appearance[ch];
	}

	for(auto& ch : appearance){
		cout << ch.first << " appeared " << ch.second << " times." << endl;
	}	
}
//input: vector of strings holding user input
//output: original user input
//purpose: to print user input via ostream
void printout(vector<string> input){

	for (auto ch : input){
		cout << ch << " ";
	}
	cout << '\n' << endl;
}

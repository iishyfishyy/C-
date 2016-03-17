/*

AUTHOR: Ishan Mishra
Date: 5/25/2015
Simple Maze Project

Currently working on an algorithm to generate random mazes each level. 
This would save tedious level-specific work in the program.

*/



#include <iostream>
using std::endl;
using std::cout;
using std::cin;
#include <string>
using std::string;

#include<Windows.h>
#include<conio.h>


void welcome();
void setMe(int);
void printLevel(int);
void update(int, int, int);
void makeSpace(int, int, int);
int getPos(int, int&);
int getX(int, int &);
bool isExit(int, int, int);
bool isWall(int, int, int);
bool applyMove(int, int, int, int, int);
char getKeyPress();

const char space = ' ';
const char me = '@';
char lvl1[15][15] = { { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ 'X', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', 'O' },
					{ '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };

char lvl2[15][15] = { { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', 'O' },
					{ '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#' },
					{ '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
					{ '#', '#', ' ', '#', ' ', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#' },
					{ 'X', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };


int main(void){
	welcome();
begin:
	system("CLS");
	cout << "\n\n\n\n\n\n\n    \t\t\t";
	cout << "PLEASE SELECT A LEVEL \n\n    \t\t\t1---2---3---4---5---6\n    \t\t\t";
	int lvl;
	cin >> lvl;
	if (lvl != 2 && lvl != 1 && lvl > 0){
		cout << endl << endl;
		cout << "\t\t";
		cout << "Level not available yet, please check back later." << endl;
		Sleep(1000);
		goto begin;
	}
	system("CLS");
	setMe(lvl);
	printLevel(lvl);
	int x, y;

	while (1){

		char move = getKeyPress();
		x = getPos(lvl, y);

		switch (move){

		case 'u':
			if (applyMove(x,y,lvl,-1,0)){
				goto begin;
			}
			break;
		case 'd':
			if (applyMove(x, y, lvl, 1, 0)){
				goto begin;
			}
			break;
		case 'l':
			if (applyMove(x, y, lvl, 0, -1)){
				goto begin;
			}
			break;
		case 'r':
			if (applyMove(x, y, lvl, 0, 1)){
				goto begin;
			}
			break;
		default:
			break;
		}

	}

	return 0;
}

void welcome(){
	string start = "WELCOME TO MAZE RUNNER v1.0";
	string indev = "Currently in development, only two levels available.";
	string howto = "Use the arrow keys and traverse through the maze. Exit is marked 'O'.";
	cout << endl;
	cout << "\n\n\n\n\n\n\n    \t\t\t";
	for (auto ch : start){
		cout << ch;
		Sleep(40);
	} cout << endl << endl;
	cout << "    \t   ";
	for (auto ch : indev){
		cout << ch;
		Sleep(40);
	} cout << endl << endl << endl;
	cout << "\t";
	for (auto ch : howto){
		cout << ch;
		Sleep(40);
	}
	Sleep(1500);
}


void printLevel(int lvl){
	cout << "\n\n\n\n\n";
	if (lvl == 1){
		for (int i = 0; i != 15; ++i){
			cout << endl << "\t\t\t\t";
			for (int j = 0; j != 15; ++j){
				cout << lvl1[i][j];
			}
		} cout << endl;
	} else if (lvl == 2){
		for (int i = 0; i != 15; ++i){
			cout << endl << "\t\t\t\t";
			for (int j = 0; j != 15; ++j){
				cout << lvl2[i][j];
			}
		} cout << endl;
	}
}

void setMe(int lvl){
	int x, y;
	if (lvl == 1){
		x = getX(lvl, y);
		lvl1[x][y] = me;
	} else if (lvl == 2){
		x = getX(lvl, y);
		lvl2[x][y] = me;
	}
}

char getKeyPress()
{
	char key = 127;

	key = _getch();

	if (key == 0 || key == -32){

		key = _getch();

		if (key == 72) {
			key = 'u';
		} else if (key == 75){
			key = 'l';
		} else if (key == 77){
			key = 'r';
		} else if (key == 80){
			key = 'd';
		}
	}
	return key;
}

bool isExit(int x, int y, int lvl){
	if (lvl == 1){
		return lvl1[x][y] == 'O';
	} else if (lvl == 2){
		return lvl2[x][y] == 'O';
	}
	return true;
}

int getPos(int lvl, int &y){
	int xCoord;
	if (lvl == 1){
		for (int i = 0; i != 15; ++i){
			for (int j = 0; j != 15; ++j){
				if (lvl1[i][j] == '@'){
					xCoord = i;
					y = j;
					return xCoord;
				}
			}
		}
	} else if (lvl == 2){
		for (int i = 0; i != 15; ++i){
			for (int j = 0; j != 15; ++j){
				if (lvl2[i][j] == '@'){
					xCoord = i;
					y = j;
					return xCoord;
				}
			}
		}
	}
	return 0;
}

bool isWall(int x, int y, int lvl){
	if (lvl == 1){
		if (lvl1[x][y] == '#'){
			cout << "\n\t\t\tCannot move! That is a wall / boundary.";
			Sleep(400);
			system("CLS");
			printLevel(lvl);
			return true;
		}
		else {
			return false;
		}
	} else if (lvl == 2){
		if (lvl2[x][y] == '#'){
			cout << "\n\t\t\tCannot move! That is a wall / boundary.";
			Sleep(400);
			system("CLS");
			printLevel(lvl);
			return true;
		}
		else {
			return false;
		}
	}
	return true;
}

int getX(int lvl, int &y){
	int xCoord;
	if (lvl == 1){
		for (int i = 0; i != 15; ++i){
			for (int j = 0; j != 15; ++j){
				if (lvl1[i][j] == 'X'){
					xCoord = i;
					y = j;
					return xCoord;
				}
			}
		}
	} else if (lvl == 2){
		for (int i = 0; i != 15; ++i){
			for (int j = 0; j != 15; ++j){
				if (lvl2[i][j] == 'X'){
					xCoord = i;
					y = j;
					return xCoord;
				}
			}
		}
	}
	return 0;
}

void update(int lvl, int x, int y){
	if (lvl == 1){
		lvl1[x][y] = me;
		printLevel(lvl);
	} else if (lvl == 2){
		lvl2[x][y] = me;
		printLevel(lvl);
	}
}

void makeSpace(int lvl, int x, int y){
	if (lvl == 1){
		lvl1[x][y] = space;
	} else if (lvl == 2){
		lvl2[x][y] = space;
	}
}

bool applyMove(int x, int y, int lvl, int dx, int dy){
	if (!isWall(x + dx, y + dy, lvl)){
		if (isExit(x + dx, y + dy, lvl)){
			system("CLS");
			cout << "You Win!" << endl;
			Sleep(2000);
			return true;
		}
		system("CLS");
		makeSpace(lvl, x, y);
		update(lvl, x + dx, y + dy);
	}
	return false;
}
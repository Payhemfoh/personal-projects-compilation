/*
* This is a console-based tick-tack-toe game
* The program is written in C++
* Structured programming
* Project start: 14 May 2020 0928 (UTC+8.00)
* - the main program is created
* - 23 May 2020, 2113 : add exception handling to input part
* - 25 May 2020, 2044 : add continue to play function into program
* - 25 May 2020, 2044 : add mainpage to the program and add player struct to store information
* - 27 May 2020, 0624 : divide game process into one function
* - 27 May 2020, 1923 : scoreboard function added
* - 11 January 2021, 1009 : display scoreboard added, debug printMark function, clearMap function
*** scoreboard appending and renew function to be added
*/
//include libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

//struct for player
struct Player 
{
	std::string name;
	int mark;
};


//function prototypes
std::string enterName();
bool check_game_state(int** map,int value,int* mark);
void printMap(int** map);
void printMark(std::string name, int player_mark,std::string name2, int com_mark);
void clearMap();
void computer_input(int** map);
void user_input(int** map);
int enterNum(std::string);
void decide_winner(int*, int*);
bool check_map(int**);
void display_mainpage();
char mainpage_enter();
void game_process();
void readScoreboard();
void writeScoreboard();
void printScoreboard();

//constant variable
const int MAPSIZE = 5;

/*
	global variable: scoreboard
	list with size of 10
	data type: Player
*/
Player score[10];

//declare the variable needed
int ConsoleTickTackToe(int argc, char** argv)
{
	bool repeat = 1;
	do {
		//main page
		display_mainpage();
		char option = mainpage_enter();
		switch (option) {
		case '1':
			game_process();
			break;
		case '2':
			printScoreboard();
			break;
		case '0':
			repeat = 0;
			break;
		default:
			std::cout << "Invalid input!Please try again!!" << std::endl;
		}
	} while (repeat);
	return 0;
}

//functions
//printing the map
std::string enterName()
{
	try {
		std::string name("");
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter your name : ";

		if (!std::getline(std::cin, name) || name.length() == 0) {
			std::cout << "Invalid name, please enter again!!" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter your name : ";
		}
		std::cout << "Welcome! " << name << std::endl;
		return name;
	}
	catch (...) {
		std::cout << "Oops! Error occur when entering name, the program will be closed soon!" << std::endl;
		exit(-1);
	}
}
void printMap(int** map)
{
	for (int row = 0; row < MAPSIZE; row++) {
		for (int col = 0; col < MAPSIZE; col++) {
			if (row % 2 == 1 && col % 2 == 1)
				printf(" + ");
			else if (col % 2 == 1)
				printf(" | ");
			else if (row % 2 == 1)
				printf(" - ");
			else if (map[row][col] == 1)
				printf(" O ");
			else if (map[row][col] == 2)
				printf(" X ");
			else
				printf("   ");
		}
		std::cout << std::endl;
	}
}


void printMark(std::string name, int player_mark,std::string name2, int com_mark)
{
	printf("%s : %d\t%s : %d\n", name.c_str(), player_mark, name2.c_str(), com_mark);
}

void clearMap()
{
	system("cls");
	/*
	for (int i = 0; i < 10; i++)
		std::cout << std::endl;
	*/
}

bool check_game_state(int** map,int value,int* mark)
{
	//win condition
	bool condition = true;
	//00 01 02
	if (map[0][0] == value && map[0][2] == value && map[0][4] == value)
		condition = false;
	//00 10 20
	else if (map[0][0] == value && map[2][0] == value && map[4][0] == value)
		condition = false;
	//00 11 22
	else if (map[0][0] == value && map[2][2] == value && map[4][4] == value)
		condition = false;
	//01 11 21
	else if (map[0][2] == value && map[2][2] == value && map[4][2] == value)
		condition = false;
	//02 12 22
	else if (map[0][4] == value && map[2][4] == value && map[4][4] == value)
		condition = false;
	//02 11 20
	else if (map[0][4] == value && map[2][2] == value && map[4][0] == value)
		condition = false;
	//10 11 12
	else if (map[2][0] == value && map[2][2] == value && map[2][4] == value)
		condition = false;
	//20 21 22
	else if (map[4][0] == value && map[4][2] == value && map[4][4] == value)
		condition = false;
	else
		condition = true;

	if (!condition)
		(*mark)++;
	return condition;
}

void computer_input(int** map)
{
	srand(time(0));
	int row = 0, col = 0;
	row = rand() % 3 * 2;
	col = rand() % 3 * 2;
	while (map[row][col] != 0) {
		row = rand() % 3 * 2;
		col = rand() % 3 * 2;
	}
	map[row][col] = 2;
}

void user_input(int** map)
{
	int row = enterNum("row");
	int col = enterNum("col");
	int value = map[row][col];
	while (value != 0)
	{
		std::cout << "The block is not empty!! Please enter again!!" << std::endl;
		row = enterNum("row");
		col = enterNum("col");
		value = map[row][col];
		printf(value + "\n");
	}
	map[row][col] = 1;
}

int enterNum(std::string str)
{
	int input = 0;
	try {
		std::cout << "Please enter the block " << str << " (0,2,4) : " << std::endl;
		while (!(std::cin >> input) || (input != 0 && input != 2 && input != 4))
		{
			std::cout << "Invalid input, Please try again!!" << std::endl;
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			std::cout << "Please enter the block " << str << " (0,2,4) : " << std::endl;
		}
	}
	catch (...) {
		std::cout << "Oops! Error occur when entering number, the program will be closed soon!" << std::endl;
		exit(-1);
	}
	return input;
}

bool check_map(int** map)
{
	for (int i = 0; i < MAPSIZE; i += 2)
		for (int j = 0; j < MAPSIZE; j += 2)
			if (map[i][j] == 0)
				return true;
	return false;
}

void decide_winner(int* player_mark, int* com_mark)
{
	if (*player_mark > *com_mark)
		std::cout << "Congratulation, You Win!!" << std::endl;
	else if (*player_mark == *com_mark)
		std::cout << "Draw!" << std::endl;
	else
		std::cout << "Computer Win!!" << std::endl;
}

void display_mainpage()
{
	std::cout << "Welcome to console tik-tak-toe game!!\n\n" << std::endl;
	std::cout << "1.Start new game" << std::endl;
	std::cout << "2.ScoreBoard" << std::endl;
	std::cout << "0.Exit" << std::endl;
	std::cout << "Your choice : ";
}

char mainpage_enter()
{
	char choice='\0';
	std::cin >> choice;
	while (choice != '1' && choice != '2' && choice != '0') {
		std::cout << "Invalid choice! Please try again!!" << std::endl;
		std::cin.clear();
		std::cin >> choice;
	}
	return choice;
}

void game_process()
{
	//declare the variable needed in the game
	Player player, computer;
	int** map = new int* [MAPSIZE];
	bool game_state = true, map_state = true, game_continue = true;
	for (int i = 0; i < MAPSIZE; i++)
		map[i] = new int[MAPSIZE];

	for (int i = 0; i < MAPSIZE; i++)
		for (int j = 0; j < MAPSIZE; j++)
			map[i][j] = 0;
	player.name = enterName();
	computer.name = "Computer";
	computer.mark = 0;

	//loop to repeat until user stop the game
	do {
		game_state = true;
		map_state = true;

		//main process of the game(looping)
		while (game_state && map_state) {
			clearMap();
			//print the map
			printMark(player.name, player.mark, computer.name, computer.mark);
			printMap(map);

			//user enter block
			user_input(map);
			//check game_state
			game_state = check_game_state(map, 1, &player.mark);
			map_state = check_map(map);
			if (!game_state || !map_state) {
				break;
			}
			//computer enter block
			computer_input(map);
			//check game_state
			game_state = check_game_state(map, 2, &computer.mark);
			map_state = check_map(map);
			if (!game_state || !map_state) {
				break;
			}

		}

		clearMap();
		//print the map
		printMark(player.name, player.mark, computer.name, computer.mark);
		printMap(map);

		decide_winner(&player.mark, &computer.mark);

		std::cout << "Do you want to continue?(y - 1/n - 0)" << std::endl;
		std::cin >> game_continue;
		
		//initialize the map
		for (int i = 0; i < MAPSIZE; i++)
			for (int j = 0; j < MAPSIZE; j++)
				map[i][j] = 0;
	} while (game_continue);

	//delete the dynamic array
	for (int i = 0; i < MAPSIZE; i++)
		delete[] map[i];
	delete[] map;
}

void readScoreboard()
{
	std::fstream file;
	file.open("Score.txt", std::ios::in);
	if (!file.is_open()) {
		std::cout << "oops!Error occur when writing scoreboard data!" << std::endl;
		exit(-2);
	}

	if (file.eof()) {
		std::cout << "The file is empty, the scoreboard will be initialized!" << std::endl;
		for (int i = 0; i < 10; i++) {
			score[i].name = "";
			score[i].mark = 0;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			file >> score[i].name >> score[i].mark;
		}
	}
	file.close();
}
void writeScoreboard()
{
	std::fstream file;
	file.open("Score.txt", std::ios::out);
	if (!file.is_open()) {
		std::cout << "oops!Error occur when writing scoreboard data!" << std::endl;
		exit(-2);
	}
	for (int i = 0; i < 10; i++) {
		file << score[i].name << "\n" << score[i].mark << std::endl;
	}
	file.close();
}

void printScoreboard()
{
	std::string output("");
	for (int i = 0; i < 10; i++) {
		std::cout << score[i].name << "\t................" << score[i].mark << std::endl;
	}
}
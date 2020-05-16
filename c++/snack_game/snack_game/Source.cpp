#include<iostream>
#include<conio.h>
#include<thread>
#include<ctime>
#include<cstdlib>

using namespace std;

const int HEIGHT = 15;
const int WIDTH  = 20;

class Objects
{
protected:
	int posx;
	int posy;
public:
	void changePos(int a, int b)
	{
		posx = a;
		posy = b;
	}
	int getX() {
		return posx;
	}
	int getY() {
		return posy;
	}
};

class Snack : public Objects
{
private:
	int body;
	int direction;
	bool die;
public:
	Snack() {
		posx = WIDTH / 2;
		posy = HEIGHT / 2;
		body = 3;
		die = false;
		direction = 1;
	}
	void add_body() {
		body++;
	}

	int getBody() {
		return body;
	}
	
	void faceto(char key) {
		switch (key) {
		case 'w':
		case '8':
			if (direction == 3)
				direction = direction;
			else
				direction = 1;
			break;

		case 'a':
		case '4':
			if (direction == 4)
				direction = direction;
			else
				direction = 2;
			break;

		case 's':
		case '2':
			if (direction == 1)
				direction = direction;
			else
				direction = 3;
			break;

		case 'd':
		case '6':
			if (direction == 2)
				direction = direction;
			else
				direction = 4;
			break;
		}	
	}

	void dies(bool result) {
		die = result;
	}

	bool getDie() {
		return die;
	}


	void movement() {
		switch (direction) {
		//w
		case 1:
			posy--;
			break;
		//a
		case 2:
			posx--;
			break;
		//s
		case 3:
			posy++;
			break;
		//d
		case 4:
			posx++;
			break;
		}
	}

	friend void conditions();
};

class Map
{
private:
	int map[HEIGHT][WIDTH] = { 0 };
public:
	Map() {
		for (int row = 0; row < HEIGHT; row++)
			for (int colomn = 0; colomn < WIDTH; colomn++)
				map[row][colomn] = 0;

		for (int row = 0; row < HEIGHT; row++) {
			map[row][0] = -2;
			map[row][WIDTH - 1] = -2;
		}

		for (int colomn = 0; colomn < WIDTH; colomn++) {
			map[0][colomn] = -2;
			map[HEIGHT-1][colomn] = -2;
		}
	}

	void generateMap(Snack& snack)
	{
		for (int row = 0; row < HEIGHT; row++) {
			for (int colomn = 0; colomn < WIDTH; colomn++) {
				if (map[row][colomn] == -2)
					cout << 'X' ;
				if (map[row][colomn] == -1)
					cout << 'O' << ' ';
				else if (row == snack.getY() && colomn == snack.getX()) {
					cout << '@' << ' ';
					map[row][colomn] = snack.getBody();
				}
				else if (map[row][colomn] > 0) {
					cout << 'o' << ' ';
					map[row][colomn]--;
				}
				else
					cout << ' ' << ' ';
			}
			cout << endl;
		}		
	}

	int getMapValue(int y, int x) {
		return map[y][x];
	}

	void changeMapValue(int y, int x, int c) {
		map[y][x] = c;
	}

	friend void conditions();
};


class Food : public Objects
{
private:
	bool gotFood = false;
public:
	void generateFood(Map *maps)
	{
		srand(time(0));
		if (gotFood == false) {
			int repeat = 1;

			while (repeat == 1)
			{
				posx = rand() % WIDTH;
				posy = rand() % HEIGHT;

				if (maps->getMapValue(posy, posx) == 0) {
					maps->changeMapValue(posy, posx, -1);
					repeat = 0;
					gotFood = true;
				}
				else
					repeat = 1;
			}
		}
	}

	void eatFood() {
		gotFood = false;
	}

	friend void conditions();
};

void conditions(Snack* snack, Food* foods, Map* maps) {
	if (maps->getMapValue(snack->getY(),snack->getX()) == -2 || maps->getMapValue(snack->getY(), snack->getX()) > 0) {
		snack->dies(true);
	}
	else if (maps->getMapValue(snack->getY(), snack->getX()) == -1) {
		maps->changeMapValue(foods->getY(), foods->getX(), 0);
		snack->add_body();
		foods->eatFood();
	}
}



int main()
{
	Snack snack;
	Map maps;
	Food foods;
	char press;
	bool gameover=false;
	snack.dies(false);

	do {
		foods.generateFood(&maps);
		
		//if keyboard is hitted, the snack may change the direction
		//else snack will move forward.
		if (_kbhit()) {
			press = _getch();
			snack.faceto(press);
		}

		snack.movement();
		conditions(&snack,&foods,&maps);
		//snack.getDie will return true when the snack die
		//need ! to convert to gameover = true
		gameover = !(snack.getDie());

		this_thread::sleep_for(0.35s);
		system("cls");
		maps.generateMap(snack);
	} while (gameover != false);

	cout << endl << "Your Result :" << snack.getBody()-3;

	return 0;
}